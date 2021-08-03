#ifndef __GETTIME_H___
#define __GETTIME_H___

#include "handle_evid.h"

#if defined(__cplusplus)
#define FLOOR(x) std::floor(x)
extern "C" {
#else
#define FLOOR(x) floor(x)
#endif

  double getTime(int idx, rx_solving_options_ind *ind);


  void radix_r(const int from, const int to, const int radix,
			rx_solving_options_ind *ind, rx_solve *rx);

  void calcNradix(int *nbyte, int *nradix, int *spare, uint64_t *maxD, uint64_t *minD);

  uint64_t dtwiddle(const void *p, int i);

  void sortRadix(rx_solving_options_ind *ind);

  extern t_dydt dydt;

  extern t_calc_jac calc_jac;

  extern t_calc_lhs calc_lhs;

  extern t_update_inis update_inis;

  extern t_dydt_lsoda_dum dydt_lsoda_dum;

  extern t_dydt_liblsoda dydt_liblsoda;

  extern t_jdum_lsoda jdum_lsoda;

  extern t_get_solve get_solve;

  extern t_assignFuns assignFuns;

  extern t_LAG LAG;
  extern t_RATE RATE;
  extern t_DUR DUR;
  extern t_calc_mtime calc_mtime;

  extern t_ME ME;
  extern t_IndF IndF;

  static inline void calcMtime(int solveid, double *mtime){
    calc_mtime(solveid,mtime);
  }

  static inline double getLag(rx_solving_options_ind *ind, int id, int cmt, double time){
    double ret = LAG(id, cmt, time);
    if (ISNA(ret)) {
      rx_solving_options *op = &op_global;
      op->badSolve=1;
      op->naTime = 1;
    }
    return ret;
  }

  static inline double getRate(rx_solving_options_ind *ind, int id, int cmt, double dose, double t){
    double ret = RATE(id, cmt, dose, t);
    if (ISNA(ret)){
      rx_solving_options *op = &op_global;
      op->badSolve=1;
      op->naTime = 1;
    }
    return ret;
  }

  static inline double getDur(rx_solving_options_ind *ind, int id, int cmt, double dose, double t){
    double ret = DUR(id, cmt, dose, t);
    if (ISNA(ret)){
      rx_solving_options *op = &op_global;
      op->badSolve=1;
      op->naTime = 1;
    }
    return ret;
  }

  static inline void updateDur(int idx, rx_solving_options_ind *ind, double *yp){
    double t = ind->all_times[idx];
    int oldIdx = ind->idx;
    ind->idx=idx;
    if (ind->all_times[idx+1] == t){
      double dur, rate, amt;
      // The duration and f cannot depend on state values
      amt  = getAmt(ind, ind->id, ind->cmt, ind->dose[idx], t, yp);
      dur  = getDur(ind, ind->id, ind->cmt, amt, t);
      if (dur > 0){
	rate = amt/dur;// mg/hr
	ind->dose[idx+1]      = -rate;
	ind->all_times[idx+1] = t + dur;
	ind->idx=oldIdx;
      } else {
	rx_solve *rx = &rx_global;
	rx_solving_options *op = &op_global;
	if (ind->cmt < op->neq){
	  if (rx->needSort & 4){
	    if (!(ind->err & 16)){
	      ind->err += 16;
	    }
	    return;
	    /* Rf_errorcall(R_NilValue, "Duration is zero/negative (dur=%f; cmt=%d; amt=%f)", dur, ind->cmt+1, amt); */
	  } else {
	    if (!(ind->err & 32)){
	      ind->err += 32;
	    }
	    return;
	    /* Rf_errorcall(R_NilValue, "Modeled duration requested in event table, but not in model; use 'dur(cmt) ='"); */
	  }
	}
      }
    }
    ind->idx=oldIdx;
  }

  static inline void updateRate(int idx, rx_solving_options_ind *ind, double *yp) {
    double t = ind->all_times[idx];
    int oldIdx = ind->idx;
    ind->idx=idx;
    if (ind->all_times[idx+1] == t){
      double dur, rate, amt;
      amt  = getAmt(ind, ind->id, ind->cmt, ind->dose[idx], t, yp);
      rate  = getRate(ind, ind->id, ind->cmt, amt, t);
      if (rate > 0){
	dur = amt/rate; // mg/hr
	ind->dose[idx+1]      = - rate;
	ind->all_times[idx+1] = t+dur;
	ind->idx=oldIdx;
      } else {
	rx_solve *rx;
	rx = &rx_global;
	rx_solving_options *op = &op_global;
	if (ind->cmt < op->neq){
	  if (rx->needSort & 8){
	    if (!(ind->err & 2)){
	      ind->err += 2;
	      /* Rf_errorcall(R_NilValue, "Rate is zero/negative"); */
	    }
	    return;
	  } else {
	    // FIXME don't error out with linear compartmental model
	    if (!(ind->err & 4)){
	      ind->err += 4;
	    }
	    return;
	    /* Rf_errorcall(R_NilValue, "Modeled rate requested in event table, but not in model; use 'rate(cmt) ='"); */
	  }
	}
	// error rate is zero/negative
      }
    }
    ind->idx=oldIdx;
  }

  static inline int isEvidType(int evid, int type) {
    int wh, cmt, wh100, whI, wh0;
    getWh(evid, &wh, &cmt, &wh100, &whI, &wh0);
    return (whI == type);
  }

#define isEvidModeledDurationStart(evid) isEvidType(evid, EVIDF_MODEL_DUR_ON)
#define isEvidModeledDurationStop(evid) isEvidType(evid, EVIDF_MODEL_DUR_OFF)
#define isEvidModeledRateStart(evid) isEvidType(evid, EVIDF_MODEL_RATE_ON)
#define isEvidModeledRateStop(evid) isEvidType(evid, EVIDF_MODEL_RATE_OFF)

  static inline void handleTurnOffModeledDuration(int idx, rx_solve *rx, rx_solving_options *op, rx_solving_options_ind *ind) {
    if (idx > 0){
      if (!isEvidModeledDurationStart(ind->evid[idx-1])) {
	if (!(ind->err & 64)){
	  ind->err += 64;
	}
	return;
      }
      // This will update the duration data
      updateDur(idx-1, ind, rx->ypNA);
    } else {
      if (!(ind->err & 128)){
	ind->err += 128;
      }
      return;
      /* Rf_errorcall(R_NilValue, "Data Error -6\n"); */
    }
  }

  static inline void handleTurnOnModeledDuration(int idx, rx_solve *rx, rx_solving_options *op, rx_solving_options_ind *ind) {
    // This calculates the rate and the duration and then assigns it to the next record
    if (idx >= ind->n_all_times){
      // error: Last record, can't be used.
      if (!(ind->err & 256)){
	ind->err += 256;
      }
      /* Rf_errorcall(R_NilValue, "Data Error 9\n"); */
      return;
    } else {
      if (!isEvidModeledDurationStop(ind->evid[idx+1])) {
	if (!(ind->err & 512)){
	  ind->err += 512;
	}
	return;
       }
      updateDur(idx, ind, rx->ypNA);
    }
  }

  static inline void handleTurnOffModeledRate(int idx, rx_solve *rx, rx_solving_options *op, rx_solving_options_ind *ind) {
    if (idx > 0){
      if (!isEvidModeledRateStart(ind->evid[idx-1])) {
	if (!(ind->err & 1024)){
	  ind->err += 1024;
	}
	/* Rf_errorcall(R_NilValue, "Data error 797 (whI = %d; evid=%d)", whI, ind->evid[idx-1]); */
	return;
      }
      updateRate(idx-1, ind, rx->ypNA);
    } else {
      if (!(ind->err & 2048)){
	ind->err += 2048;
      }
      /* Rf_errorcall(R_NilValue, "Data Error -7\n"); */
      return;
    }
  }

  static inline void handleTurnOnModeledRate(int idx, rx_solve *rx, rx_solving_options *op, rx_solving_options_ind *ind) {
    // This calculates the rate and the duration and then assigns it to the next record
    if (idx >= ind->n_all_times){
      // error: Last record, can't be used.
      if (!(ind->err & 4096)){
	ind->err += 4096;
      }
      /* Rf_errorcall(R_NilValue, "Data Error 9\n"); */
      return;
    } else {
      if (!isEvidModeledRateStop(ind->evid[idx+1])) {
	if (!(ind->err & 8192)){
	  ind->err += 8192;
	}
	return;
       }
      updateRate(idx, ind, rx->ypNA);
    }
  }

  static inline double handleInfusionItem(int idx, rx_solve *rx, rx_solving_options *op, rx_solving_options_ind *ind) {
    double amt = ind->dose[idx];
    if (amt > 0){
      return getLag(ind, ind->id, ind->cmt, ind->all_times[idx]);
    } else if (amt < 0){
      int j = getDoseNumberFromIndex(ind, idx);
      if (j == -1){
	if (!(ind->err & 16384)){
	  ind->err += 16384;
	}
	return 0.0;
	/* Rf_errorcall(R_NilValue, "Corrupted event table during sort (1)."); */
      }
      int k;
      for (k = j; k--;){
	if (ind->evid[ind->idose[j]] == ind->evid[ind->idose[k]]) break;
	if (k == 0) {
	  if (!(ind->err & 32768)){
	    ind->err += 32768;
	  }
	  return 0.0;
	}
      }
      rx_solve *rx = &rx_global;
      double f = getAmt(ind, ind->id, ind->cmt, 1.0, ind->all_times[ind->idose[j-1]], rx->ypNA);
      if (ISNA(f)){
	rx_solving_options *op = &op_global;
	op->badSolve=1;
	op->naTime = 1;
      }
      double durOld = (ind->all_times[ind->idose[j]] -
		       ind->all_times[ind->idose[k]]); 
      double dur = f*durOld;
      double t = ind->all_times[ind->idose[k]]+dur;
      return getLag(ind, ind->id, ind->cmt, t);
    } else {
      /* Rf_errorcall(R_NilValue, "Corrupted events."); */
      if (!(ind->err & 131072)){
	ind->err += 131072;
      }
      return 0.0;
    }
  }

  static inline double getTime_(int idx, rx_solving_options_ind *ind) {
    rx_solving_options *op = &op_global;
    rx_solve *rx = &rx_global;
    int evid = ind->evid[idx];
    if (evid == 9) return 0.0;
    if (evid >= 10 && evid <= 99) return ind->mtime[evid-10];
    if (isObs(evid))  return ind->all_times[idx];
    getWh(evid, &(ind->wh), &(ind->cmt), &(ind->wh100), &(ind->whI), &(ind->wh0));
    if (ind->wh0 == EVID0_SSINF){
    } else {
      // yp should be the current solve values
      //
      // Before solving the solve will be zero
      // After solving the yp will contain the solved values
      //
      switch(ind->whI){
      case EVIDF_MODEL_DUR_OFF:
	handleTurnOffModeledDuration(idx, rx, op, ind);
	break;
      case EVIDF_MODEL_DUR_ON:
	handleTurnOnModeledDuration(idx, rx, op, ind);
	break;
      case EVIDF_MODEL_RATE_OFF:
	handleTurnOffModeledRate(idx, rx, op, ind);
	break;
      case EVIDF_MODEL_RATE_ON:
	handleTurnOnModeledRate(idx, rx, op, ind);
	break;
      case EVIDF_INF_RATE:
	return handleInfusionItem(idx, rx, op, ind);
	break;
      }
    }
    return getLag(ind, ind->id, ind->cmt, ind->all_times[idx]);
  }

  static inline void resetTimeForModeledInfusionIfNeeded(int i, rx_solving_options_ind *ind) {
    if (isObs(ind->evid[i])) {
      int wh, cmt, wh100, whI, wh0;
      getWh(ind->evid[i], &wh, &cmt, &wh100, &whI, &wh0);
      if (whI == EVIDF_MODEL_RATE_OFF || whI == EVIDF_MODEL_DUR_OFF) {
	ind->all_times[i] = ind->all_times[i-1];
      } else if (i != ind->n_all_times - 1 && (whI == EVIDF_MODEL_RATE_ON ||
					       whI == EVIDF_MODEL_DUR_ON) ) {
	ind->all_times[i + 1] = ind->all_times[i];
      }
    }

  }
#if defined(__cplusplus)
}
#endif


#endif
