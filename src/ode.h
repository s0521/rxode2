#define __HD_ODE_1__ "#include <stdio.h>\n#include <stdarg.h>\n#include <R.h>\n#include <Rinternals.h>\n#include <Rmath.h>\n#include <R_ext/Rdynload.h>\n#define JAC_Rprintf Rprintf\n#define JAC0_Rprintf if ( (&_solveData->subjects[_cSub])->jac_counter == 0) Rprintf\n#define ODE_Rprintf Rprintf\n#define ODE0_Rprintf if ( (&_solveData->subjects[_cSub])->dadt_counter == 0) Rprintf\n#define LHS_Rprintf Rprintf\n#define _safe_log(a) (((a) <= 0) ? log(DOUBLE_EPS) : log(a))\n#define safe_zero(a) ((a) == 0 ? DOUBLE_EPS : (a))\n#define _as_zero(a) (fabs(a) < sqrt(DOUBLE_EPS) ? 0.0 : a)\n#define factorial(a) exp(lgamma1p(a))\n#define sign_exp(sgn, x)(((sgn) > 0.0) ? exp(x) : (((sgn) < 0.0) ? -exp(x) : 0.0))\n#define R_pow(a, b) (((a) == 0 && (b) <= 0) ? R_pow(DOUBLE_EPS, b) : R_pow(a, b))\n#define R_pow_di(a, b) (((a) == 0 && (b) <= 0) ? R_pow_di(DOUBLE_EPS, b) : R_pow_di(a, b))\n#define Rx_pow(a, b) (((a) == 0 && (b) <= 0) ? R_pow(DOUBLE_EPS, b) : R_pow(a, b))\n#define Rx_pow_di(a, b) (((a) == 0 && (b) <= 0) ? R_pow_di(DOUBLE_EPS, b) : R_pow_di(a, b))\ntypedef void (*t_dydt)(int *neq, double t, double *A, double *DADT);\ntypedef void (*t_calc_jac)(int *neq, double t, double *A, double *JAC, unsigned int __NROWPD__);\ntypedef void (*t_calc_lhs)(int cSub, double t, double *A, double *lhs);\ntypedef void (*t_update_inis)(int cSub, double *);\ntypedef void (*t_dydt_lsoda_dum)(int *neq, double *t, double *A, double *DADT);\ntypedef void (*t_jdum_lsoda)(int *neq, double *t, double *A,int *ml, int *mu, double *JAC, int *nrowpd);\ntypedef int (*t_dydt_liblsoda)(double t, double *y, double *ydot, void *data);\ntypedef void (*t_ode_current)();\n\ntypedef struct {\n  // These options should not change based on an individual solve\n  int badSolve;\n  double ATOL;          //absolute error\n  double RTOL;          //relative error\n  double H0;\n  double HMIN;\n  int mxstep;\n  int MXORDN;\n  int MXORDS;\n  //\n  int do_transit_abs;\n  int nlhs;\n  int neq;\n  int stiff;\n  int ncov;\n  char modNamePtr[1000];\n  int *par_cov;\n  double *inits;\n  double *scale;\n  int do_par_cov;\n  // approx fun options\n  double f1;\n  double f2;\n  int kind;\n  int is_locf;\n  int cores;\n  int extraCmt;\n  double hmax2; // Determined by diff\n  double *rtol2;\n  double *atol2;\n  int nDisplayProgress;\n  int ncoresRV;\n  int isChol;\n  int *svar;\n  int abort;\n} rx_solving_options;\n\n\ntypedef struct {\n  int *slvr_counter;\n  int *dadt_counter;\n  int *jac_counter;\n  double *InfusionRate;\n  int *BadDose;\n  int nBadDose;\n  double HMAX; // Determined by diff\n  double tlast;\n  double podo;\n  double *par_ptr;\n  double *dose;\n  double *solve;\n  double *lhs;\n  int  *evid;\n  int *rc;\n  double *cov_ptr;\n  int n_all_times;\n  int ixds;\n  int ndoses;\n  double *all_times;\n  int *idose;\n  int idosen;\n  int id;\n  int sim;\n  double ylow;\n  double yhigh;\n} rx_solving_options_ind;\n\ntypedef struct {\n  rx_solving_options_ind *subjects;\n  rx_solving_options *op;\n  int nsub;\n  int nsim;\n  int nall;\n  int nobs;\n  int nr;\n  int add_cov;\n  int matrix;\n  int *stateIgnore;\n} rx_solve;\n\ntypedef void (*t_set_solve)(rx_solve *);\ntypedef rx_solve *(*t_get_solve)();\n\n\nrx_solve *getRxSolve_();\nrx_solve *getRxSolve(SEXP ptr);\n\nvoid par_solve(rx_solve *rx);\n\nrx_solving_options *getRxOp(rx_solve *rx);\n\nSEXP RxODE_df(int doDose);\nSEXP RxODE_par_df();\n\nrx_solving_options_ind *rxOptionsIniEnsure(int mx);\n\nvoid rxUpdateFuns(SEXP trans);\n#define abs_log1p(x) (((x) + 1.0 > 0.0) ? log1p(x) : (((x) + 1.0 > 0.0) ? log1p(-x) : 0.0))\n#define abs_log(x) ((fabs(x) <= sqrt(DOUBLE_EPS)) ? log(sqrt(DOUBLE_EPS)) : (((x) > 0.0) ? log(x) ? (((x) == 0) ? 0.0 : log(-x))))\n\n\n// Types for par pointers.r\ntypedef double (*RxODE_fn) (double x);\ntypedef double (*RxODE_fn2) (double x, double y);\ntypedef double (*RxODE_fn2i) (double x, int i);\ntypedef int (*RxODE_fn0i) ();\ntypedef double (*RxODE_vec) (int val, rx_solve *rx, unsigned int id);\ntypedef double (*RxODE_val) (rx_solve *rx, unsigned int id);\ntypedef void (*RxODE_assign_ptr)(SEXP);\ntypedef void (*RxODE_ode_so"
#define __HD_ODE_2__ "lver_old_c)(int *neq,double *theta,double *time,int *evid,int *ntime,double *inits,double *dose,double *ret,double *atol,double *rtol,int *stiff,int *transit_abs,int *nlhs,double *lhs,int *rc);\n\nRxODE_assign_ptr _assign_ptr = NULL;\n\ntypedef void (*_rxRmModelLibType)(const char *inp);\n_rxRmModelLibType _rxRmModelLib = NULL;\n\ntypedef SEXP (*_rxGetModelLibType)(const char *s);\n_rxGetModelLibType _rxGetModelLib = NULL;\n\nRxODE_ode_solver_old_c _old_c = NULL;\n\nRxODE_fn0i _ptrid=NULL;\n\ntypedef  SEXP (*_rx_asgn) (SEXP objectSEXP);\n_rx_asgn _RxODE_rxAssignPtr =NULL;\n\ntypedef int(*_rxIsCurrentC_type)(SEXP);\n_rxIsCurrentC_type _rxIsCurrentC=NULL;\n\ntypedef double(*_rxSumType)(double *, int, double *, int, int);\n_rxSumType _sumPS = NULL;\n\ndouble _sum(double *input, double *pld, int m, int type, int n, ...){\n  va_list valist;\n  va_start(valist, n);\n  for (unsigned int i = 0; i < n; i++){\n    input[i] = va_arg(valist, double);\n  }\n  va_end(valist);\n  return _sumPS(input, n, pld, m, type);\n}\n\ntypedef double(*_rxProdType)(double*, double*, int, int);\n_rxProdType _prodPS = NULL;\n\ndouble _prod(double *input, double *p, int type, int n, ...){\n  va_list valist;\n  va_start(valist, n);\n  for (unsigned int i = 0; i < n; i++){\n    input[i] = va_arg(valist, double);\n  }\n  va_end(valist);\n  return _prodPS(input, p, n, type);\n}\n\ndouble _sign(unsigned int n, ...){\n  va_list valist;\n  va_start(valist, n);\n  double s = 1;\n  for (unsigned int i = 0; i < n; i++){\n    s = sign(va_arg(valist, double))*s;\n    if (s == 0){\n      break;\n    }\n  }\n  va_end(valist);\n  return s;\n}\n\ndouble _max(unsigned int n, ...){\n  va_list valist;\n  va_start(valist, n);\n  double mx = NA_REAL;\n  double tmp = 0;\n  if (n >= 1){\n    mx = va_arg(valist, double);\n    for (unsigned int i = 1; i < n; i++){\n      tmp = va_arg(valist, double);\n      if (tmp>mx) mx=tmp;\n    }\n    va_end(valist);\n  }\n  return mx;\n}\n\ndouble _min(unsigned int n, ...){\n  va_list valist;\n  va_start(valist, n);\n  double mn = NA_REAL;\n  double tmp = 0;\n  if (n >= 1){\n    mn = va_arg(valist, double);\n    for (unsigned int i = 1; i < n; i++){\n      tmp = va_arg(valist, double);\n      if (tmp<mn) mn=tmp;\n    }\n    va_end(valist);\n  }\n  return mn;\n}\n\nrx_solve *_solveData = NULL;\n\n/* Authors: Robert Gentleman and Ross Ihaka and The R Core Team */\n/* Taken directly from https://github.com/wch/r-source/blob/922777f2a0363fd6fe07e926971547dd8315fc24/src/library/stats/src/approx.c*/\n/* Changed as follows:\n   - Different Name\n   - Use RxODE structure\n   - Make inline\n*/\nstatic inline double rx_approxP(double v, double *x, double *y, int n,\n                         rx_solving_options *Meth, rx_solving_options_ind *id){\n  /* Approximate  y(v),  given (x,y)[i], i = 0,..,n-1 */\n  int i, j, ij;\n\n  if(!n) return R_NaN;\n\n  i = 0;\n  j = n - 1;\n\n  /* handle out-of-domain points */\n  if(v < x[i]) return id->ylow;\n  if(v > x[j]) return id->yhigh;\n\n  /* find the correct interval by bisection */\n  while(i < j - 1) { /* x[i] <= v <= x[j] */\n    ij = (i + j)/2; /* i+1 <= ij <= j-1 */\n    if(v < x[ij]) j = ij; else i = ij;\n    /* still i < j */\n  }\n  /* provably have i == j-1 */\n\n  /* interpolation */\n\n  if(v == x[j]) return y[j];\n  if(v == x[i]) return y[i];\n  /* impossible: if(x[j] == x[i]) return y[i]; */\n\n  if(Meth->kind == 1) /* linear */\n    return y[i] + (y[j] - y[i]) * ((v - x[i])/(x[j] - x[i]));\n  else /* 2 : constant */\n    return (Meth->f1 != 0.0 ? y[i] * Meth->f1 : 0.0)\n      + (Meth->f2 != 0.0 ? y[j] * Meth->f2 : 0.0);\n}/* approx1() */\n\n/* End approx from R */\n\n\nstatic inline void _update_par_ptr(double t, unsigned int id){\n  rx_solving_options_ind *ind;\n  ind = (&_solveData->subjects[id]);\n  rx_solving_options *op = _solveData->op;\n  if (op->neq > 0){\n    // Update all covariate parameters\n    int k;\n    int ncov = op->ncov;\n    if (op->do_par_cov){\n      for (k = ncov; k--;){\n        if (op->par_cov[k]){\n	  double *par_ptr = ind->par_ptr;\n          double *all_times = ind"
#define __HD_ODE_3__ "->all_times;\n          double *cov_ptr = ind->cov_ptr;\n          // Use the same methodology as approxfun.\n          // There is some rumor the C function may go away...\n          ind->ylow = cov_ptr[ind->n_all_times*k];\n          ind->yhigh = cov_ptr[ind->n_all_times*k+ind->n_all_times-1];\n          par_ptr[op->par_cov[k]-1] = rx_approxP(t, all_times, cov_ptr+ind->n_all_times*k, ind->n_all_times, op, ind);\n        }\n      }\n    }\n  }\n}\n\nstatic inline double _transit4P(double t, unsigned int id, double n, double mtt, double bio){\n  double ktr = (n+1)/mtt;\n  double lktr = log(n+1)-log(mtt);\n  double tc = (t-(_solveData->subjects[id].tlast));\n  return exp(log(bio*(_solveData->subjects[id].podo))+lktr+n*(lktr+log(tc))-ktr*(tc)-lgamma1p(n));\n}\n\nstatic inline double _transit3P(double t, unsigned int id, double n, double mtt){\n  double ktr = (n+1)/mtt;\n  double lktr = log(n+1)-log(mtt);\n  double tc = (t-(_solveData->subjects[id].tlast));\n  return exp(log(_solveData->subjects[id].podo)+lktr+n*(lktr+log(tc))-ktr*(tc)-lgamma1p(n));\n}\n\n\n// Linear compartment models/functions\n\nstatic inline int _locateDoseIndex(const double obs_time,  rx_solving_options_ind *ind){\n  // Uses bisection for slightly faster lookup of dose index.\n  int i, j, ij;\n  i = 0;\n  j = ind->ndoses - 1;\n  if (obs_time <= ind->all_times[ind->idose[i]]){\n    while(obs_time == ind->all_times[ind->idose[i+1]]){\n      i++;\n    }\n    return i;\n  }\n  if (obs_time >= ind->all_times[ind->idose[j]]){\n    return j;\n  }\n  while(i < j - 1) { /* x[i] <= obs_time <= x[j] */\n    ij = (i + j)/2; /* i+1 <= ij <= j-1 */\n    if(obs_time < ind->all_times[ind->idose[ij]])\n      j = ij;\n    else\n      i = ij;\n  }\n  while(obs_time == ind->all_times[ind->idose[i+1]]){\n    i++;\n  }\n  return i;\n}\n\nstatic inline double solveLinB(rx_solve *rx, unsigned int id, double t, int linCmt, int diff1, int diff2, double d_A, double d_alpha, double d_B, double d_beta, double d_C, double d_gamma, double d_ka, double d_tlag){\n  if (diff1 != 0 || diff2 != 0){\n    error(\"Exact derivtives are no longer calculated.\");\n  }\n  unsigned int ncmt = 1;\n  double beta1=0, gamma1=0, alpha1=0;\n  double alpha = d_alpha;\n  double A = d_A;\n  double beta = d_beta;\n  double B = d_B;\n  double gamma = d_gamma;\n  double C = d_C;\n  double ka = d_ka;\n  double tlag = d_tlag;\n  if (d_gamma > 0.){\n    ncmt = 3;\n    gamma1 = 1.0/gamma;\n    beta1 = 1.0/beta;\n    alpha1 = 1.0/alpha;\n  } else if (d_beta > 0.){\n    ncmt = 2;\n    beta1 = 1.0/beta;\n    alpha1 = 1.0/alpha;\n  } else if (d_alpha > 0.){\n    ncmt = 1;\n    alpha1 = 1.0/alpha;\n  } else {\n    return 0.0;\n    //error(\"You need to specify at least A(=%%f) and alpha (=%%f). (@t=%%f, d1=%%d, d2=%%d)\", d_A, d_alpha, t, diff1, diff2);\n  }\n  rx_solving_options *op = _solveData->op;\n  double ATOL = op->ATOL;          //absolute error\n  double RTOL = op->RTOL;          //relative error\n  if (linCmt+1 > op->extraCmt){\n    op->extraCmt = linCmt+1;\n  }\n  int oral, cmt;\n  oral = (ka > 0) ? 1 : 0;\n  double ret = 0,cur=0, tmp=0;\n  unsigned int m = 0, l = 0, p = 0;\n  int evid, evid100;\n  double thisT = 0.0, tT = 0.0, res, t1, t2, tinf, dose = 0;\n  double rate;\n  rx_solving_options_ind *ind = &(_solveData->subjects[id]);\n  if (ind->ndoses < 0){\n    ind->ndoses=0;\n    for (unsigned int i = 0; i < ind->n_all_times; i++){\n      if (ind->evid[i]){\n        ind->ndoses++;\n        ind->idose[ind->ndoses-1] = i;\n      }\n    }\n  }\n  m = _locateDoseIndex(t, ind);\n  int ndoses = ind->ndoses;\n  for(l=m+1; l--;){// Optimized for loop as https://www.thegeekstuff.com/2015/01/c-cpp-code-optimization/\n    cur=0;\n    //superpostion\n    evid = ind->evid[ind->idose[l]];\n    dose = ind->dose[l];\n    // Support 100+ compartments...\n    evid100 = floor(evid/1e5);\n    evid = evid- evid100*1e5;\n    cmt = (evid%%10000)/100 - 1 + 100*evid100;\n    if (cmt != linCmt) continue;\n    if (evid > 10000) {\n      if (dose > 0){\n        // During infusion\n        tT = t - ind->all_times[ind->idose[l]] ;"
#define __HD_ODE_4__ "\n        thisT = tT - tlag;\n        p = l+1;\n        while (p < ndoses && ind->dose[p] != -dose){\n          p++;\n        }\n        if (ind->dose[p] != -dose){\n          error(\"Could not find a error to the infusion.  Check the event table.\");\n        }\n        tinf  = ind->all_times[ind->idose[p]] - ind->all_times[ind->idose[l]];\n        rate  = dose;\n        if (tT >= tinf) continue;\n      } else {\n        // After  infusion\n        p = l-1;\n        while (p > 0 && ind->dose[p] != -dose){\n          p--;\n        }\n        if (ind->dose[p] != -dose){\n          error(\"Could not find a start to the infusion.  Check the event table.\");\n        }\n        tinf  = ind->all_times[ind->idose[l]] - ind->all_times[ind->idose[p]] - tlag;\n        \n        tT = t - ind->all_times[ind->idose[p]];\n        thisT = tT -tlag;\n        rate  = -dose;\n      }\n      t1 = ((thisT < tinf) ? thisT : tinf);        //during infusion\n      t2 = ((thisT > tinf) ? thisT - tinf : 0.0);  // after infusion\n      cur +=  rate*A*alpha1*(1.0-exp(-alpha*t1))*exp(-alpha*t2);\n      if (ncmt >= 2){\n        cur +=  rate*B*beta1*(1.0-exp(-beta*t1))*exp(-beta*t2);\n        if (ncmt >= 3){\n          cur +=  rate*C*gamma1*(1.0-exp(-gamma*t1))*exp(-gamma*t2);\n        }\n      }\n    } else {\n      tT = t - ind->all_times[ind->idose[l]];\n      thisT = tT -tlag;\n      if (thisT < 0) continue;\n      res = ((oral == 1) ? exp(-ka*thisT) : 0.0);\n      cur +=  dose*A*(exp(-alpha*thisT)-res);\n      if (ncmt >= 2){\n        cur +=  dose*B*(exp(-beta*thisT)-res);\n        if (ncmt >= 3){\n          cur += dose*C*(exp(-gamma*thisT)-res);\n        }\n      }\n    }\n    // Since this starts with the most recent dose, and then goes\n    // backward, you can use a tolerance calcuation to exit the loop\n    // early.\n    //\n    // See  http://web.mit.edu/10.001/Web/Tips/Converge.htm\n    //\n    // | True value - Computed value | < RTOL*|True Value| + ATOL \n    // | (ret+cur) - ret| < RTOL*|ret+cur|+ATOL\n    // | cur | < RTOL*|ret+cur|+ATOL\n    //\n    // For this calcuation all values should be > 0.  If they are less\n    // than 0 then it is approximately zero.\n    if (cur < 0) break;\n    tmp = ret+cur;\n    if (cur < RTOL*tmp+ATOL){ \n      ret=tmp;\n      break;\n    }\n    ret = tmp;\n  } //l\n  return ret;\n}\n\nRxODE_fn0i _prodType = NULL;\nRxODE_fn0i _sumType = NULL;\n\nextern void __ODE_SOLVER_SOLVEDATA__ (rx_solve *solve){\n  _solveData = solve;\n}\n\nextern rx_solve *__ODE_SOLVER_GET_SOLVEDATA__(){\n  return _solveData;\n}\n\nSEXP __MODEL_VARS__();\nextern void __ODE_SOLVER__(int *neq,\n			   double *theta,      //order:\n			   double *time,\n			   int *evid,\n			   int *ntime,\n			   double *inits,\n			   double *dose,\n			   double *ret,\n			   double *atol,\n			   double *rtol,\n			   int *stiff,\n			   int *transit_abs,\n			   int *nlhs,\n			   double *lhs,\n			   int *rc){\n  // Backward compatible ode solver for 0.5* C interface\n  //if (_ptrid() != __TIMEID__ ){ _assign_ptr(__MODEL_VARS__());}\n  __FIX_INIS__\n  _old_c(neq, _theta, time, evid, ntime, inits, dose, ret, atol, rtol, stiff, transit_abs, nlhs, lhs, rc);\n}\n\nstatic R_NativePrimitiveArgType __ODE_SOLVER__rx_t[] = {\n  //*neq, *theta, *time,  *evid, *ntime, *inits,   *dose,   *ret,     *atol,  *rtol,   *stiff, *transit_abs, *nlhs, *lhs, *rc\n  INTSXP,REALSXP, REALSXP, INTSXP, INTSXP, REALSXP, REALSXP, REALSXP, REALSXP, REALSXP, INTSXP, INTSXP, INTSXP, REALSXP, INTSXP\n};\n"
#define __HD_SOLVE1__ "\nextern void __DYDT_LSODA__(int *neq, double *t, double *A, double *DADT)\n{\n  __DYDT__(neq, *t, A, DADT);\n}\n\nextern int __DYDT_LIBLSODA__(double t, double *y, double *ydot, void *data)\n{\n  int *neq = (int*)(data);\n  __DYDT__(neq, t, y, ydot);\n  return(0);\n}\n\nextern void __CALC_JAC_LSODA__(int *neq, double *t, double *A,int *ml, int *mu, double *JAC, int *nrowpd){\n  // Update all covariate parameters\n  __CALC_JAC__(neq, *t, A, JAC, *nrowpd);\n}\n\n//Initilize the dll to match RxODE's calls\nvoid __R_INIT__ (DllInfo *info){\n  // Get C callables on load; Otherwise it isn't thread safe\n  _assign_ptr=(RxODE_assign_ptr) R_GetCCallable(\"RxODE\",\"RxODE_assign_fn_pointers\");\n  _rxRmModelLib=(_rxRmModelLibType) R_GetCCallable(\"RxODE\",\"rxRmModelLib\");\n  _rxGetModelLib=(_rxGetModelLibType) R_GetCCallable(\"RxODE\",\"rxGetModelLib\");\n  _old_c = (RxODE_ode_solver_old_c) R_GetCCallable(\"RxODE\",\"rxSolveOldC\");\n  _RxODE_rxAssignPtr=(_rx_asgn)R_GetCCallable(\"RxODE\",\"_RxODE_rxAssignPtr\");\n  _rxIsCurrentC = (_rxIsCurrentC_type)R_GetCCallable(\"RxODE\",\"rxIsCurrentC\");\n  _sumPS  = (_rxSumType) R_GetCCallable(\"PreciseSums\",\"PreciseSums_sum_r\");\n  _prodPS = (_rxProdType) R_GetCCallable(\"PreciseSums\",\"PreciseSums_prod_r\");\n  _prodType=(RxODE_fn0i)R_GetCCallable(\"PreciseSums\", \"PreciseSums_prod_get\");\n  _sumType=(RxODE_fn0i)R_GetCCallable(\"PreciseSums\", \"PreciseSums_sum_get\");\n  _ptrid=(RxODE_fn0i)R_GetCCallable(\"RxODE\", \"RxODE_current_fn_pointer_id\");\n  // Register the outside functions\n  R_RegisterCCallable(__LIB_STR__,__ODE_SOLVER_STR__,       (DL_FUNC) __ODE_SOLVER__);\n  R_RegisterCCallable(__LIB_STR__,\"__INIS__\", (DL_FUNC) __INIS__);\n  R_RegisterCCallable(__LIB_STR__,\"__INIS__\", (DL_FUNC) __INIS__);\n  R_RegisterCCallable(__LIB_STR__,\"__DYDT__\", (DL_FUNC) __DYDT__);\n  R_RegisterCCallable(__LIB_STR__,\"__CALC_LHS__\", (DL_FUNC) __CALC_LHS__);\n  R_RegisterCCallable(__LIB_STR__,\"__CALC_JAC__\", (DL_FUNC) __CALC_JAC__);\n  R_RegisterCCallable(__LIB_STR__,\"__DYDT_LSODA__\", (DL_FUNC) __DYDT_LSODA__);\n  R_RegisterCCallable(__LIB_STR__,\"__CALC_JAC_LSODA__\", (DL_FUNC) __CALC_JAC_LSODA__);\n  R_RegisterCCallable(__LIB_STR__,\"__ODE_SOLVER_SOLVEDATA__\", (DL_FUNC) __ODE_SOLVER_SOLVEDATA__);\n  R_RegisterCCallable(__LIB_STR__,\"__ODE_SOLVER_GET_SOLVEDATA__\", (DL_FUNC) __ODE_SOLVER_GET_SOLVEDATA__);\n  R_RegisterCCallable(__LIB_STR__,\"__DYDT_LIBLSODA__\", (DL_FUNC) __DYDT_LIBLSODA__);\n  \n  static const R_CMethodDef cMethods[] = {\n    {__ODE_SOLVER_STR__, (DL_FUNC) &__ODE_SOLVER__, 15, __ODE_SOLVER__rx_t},\n    {NULL, NULL, 0, NULL}\n  };\n  \n  R_CallMethodDef callMethods[]  = {\n    {__MODEL_VARS_STR__, (DL_FUNC) &__MODEL_VARS__, 0},\n    {NULL, NULL, 0}\n  };\n  R_registerRoutines(info, cMethods, callMethods, NULL, NULL);\n  R_useDynamicSymbols(info,FALSE);\n}\n\nvoid __R_UNLOAD__ (DllInfo *info){\n  // Free resources required for single subject solve.\n  SEXP _mv = PROTECT(_rxGetModelLib(__MODEL_VARS_STR__));\n  if (!isNull(_mv)){\n    _rxRmModelLib(__MODEL_VARS_STR__);\n  }\n  UNPROTECT(1);\n}"
#define __HD_SOLVE2__ ""
#define __VER_2__ "    SET_STRING_ELT(version,2,mkChar(\"66225594848984fa2d21d711b3fc4c7e\"));\n"
#define __VER_1__ "    SET_STRING_ELT(version,1,mkChar(\"https://github.com/nlmixrdevelopment/RxODE\"));\n"
#define __VER_0__ "    SET_STRING_ELT(version,0,mkChar(\"0.7.1-0\"));\n"
#define __VER_md5__ "66225594848984fa2d21d711b3fc4c7e"
