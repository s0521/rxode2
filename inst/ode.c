#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <R_ext/Rdynload.h>
#define JAC_Rprintf Rprintf
#define JAC0_Rprintf if (jac_counter_val() == 0) Rprintf
#define ODE_Rprintf Rprintf
#define ODE0_Rprintf if (dadt_counter_val() == 0) Rprintf
#define LHS_Rprintf Rprintf
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
// Types for par pointers.r
typedef void (*RxODE_update_par_ptr)(double t);
typedef double (*RxODE_transit3)(double t, double n, double mtt);
typedef double (*RxODE_fn) (double x);
typedef double (*RxODE_fn2) (double x, double y);
typedef double (*RxODE_transit4)(double t, double n, double mtt, double bio);
typedef double (*RxODE_vec) (int val);
typedef long (*RxODE_cnt) ();
typedef void (*RxODE_inc) ();
typedef double (*RxODE_val) ();
typedef SEXP (*RxODE_ode_solver) (SEXP sexp_theta, SEXP sexp_inits, SEXP sexp_lhs, SEXP sexp_time, SEXP sexp_evid,SEXP sexp_dose, SEXP sexp_pcov, SEXP sexp_cov, SEXP sexp_locf, SEXP sexp_atol, SEXP sexp_rtol, SEXP sexp_hmin, SEXP sexp_hmax, SEXP sexp_h0, SEXP sexp_mxordn, SEXP sexp_mxords, SEXP sexp_mx,SEXP sexp_stiff, SEXP sexp_transit_abs, SEXP sexp_object, SEXP sexp_extra_args);
typedef void (*RxODE_assign_fn_pointers)(void (*fun_dydt)(unsigned int, double, double *, double *),void (*fun_calc_lhs)(double, double *, double *),void (*fun_calc_jac)(unsigned int, double, double *, double *, unsigned int),int fun_jt,int fun_mf, int fun_debug);

typedef void (*RxODE_ode_solver_old_c)(int *neq,double *theta,double *time,int *evid,int *ntime,double *inits,double *dose,double *ret,double *atol,double *rtol,int *stiff,int *transit_abs,int *nlhs,double *lhs,int *rc);
typedef void (*RxODE_ode_solver_0_6_c)(int *neq,double *theta,double *time,int *evid,int *ntime,double *inits,double *dose,double *ret,double *atol,double *rtol,int *stiff,int *transit_abs,int *nlhs,double *lhs,int *rc,double hmin, double hmax,double h0,int mxordn,int mxords,int mxstep);
// Give par pointers
RxODE_vec par_ptr, InfusionRate;
RxODE_update_par_ptr update_par_ptr;
RxODE_cnt dadt_counter_val, jac_counter_val;
RxODE_inc dadt_counter_inc, jac_counter_inc;
RxODE_val podo, tlast;
RxODE_transit4 transit4;
RxODE_transit3 transit3;
RxODE_fn factorial;
RxODE_fn2 polygamma;
RxODE_fn2 besseli;
RxODE_fn2 besselj;
RxODE_fn2 besselk;
RxODE_fn2 bessely;
RxODE_assign_fn_pointers assign_fn_pointers;
RxODE_ode_solver_old_c old_c;
RxODE_ode_solver_0_6_c c_0_6;


void __ODE_SOLVER__(
                    int *neq,
                    double *theta,      //order:
                    double *time,
                    int *evid,
                    int *ntime,
                    double *inits,
                    double *dose,
                    double *ret,
                    double *atol,
                    double *rtol,
                    int *stiff,
                    int *transit_abs,
                    int *nlhs,
                    double *lhs,
                    int *rc
                    ){
  // Backward compatible ode solver for 0.5* C interface
  assign_fn_pointers(__DYDT__ , __CALC_LHS__ , __CALC_JAC__, __JT__ , __MF__,
#ifdef __DEBUG__
                     1
#else
                     0
#endif
                     );
  old_c(neq, theta, time, evid, ntime, inits, dose, ret, atol, rtol, stiff, transit_abs, nlhs, lhs, rc);
}

void __ODE_SOLVER_0_6__(int *neq,
                        double *theta,  //order:
                        double *time,
                        int *evid,
                        int *ntime,
                        double *inits,
                        double *dose,
                        double *ret,
                        double *atol,
                        double *rtol,
                        int *stiff,
                        int *transit_abs,
                        int *nlhs,
                        double *lhs,
                        int *rc,
                        double hmin,
                        double hmax,
                        double h0,
                        int mxordn,
                        int mxords,
                        int mxstep) {
  // Backward compatible ode solver for 0.5* C interface
  assign_fn_pointers(__DYDT__ , __CALC_LHS__ , __CALC_JAC__, __JT__ , __MF__,
#ifdef __DEBUG__
                     1
#else
                     0
#endif
                     );
  c_0_6(neq, theta, time, evid, ntime, inits, dose, ret, atol, rtol, stiff, transit_abs, nlhs, lhs, rc,
	hmin, hmax, h0, mxordn, mxords, mxstep);
}

extern SEXP __ODE_SOLVER_SEXP__ (// Parameters
                                 SEXP sexp_theta,
                                 SEXP sexp_inits,
                                 SEXP sexp_lhs,
				 // Events
				 SEXP sexp_time,
				 SEXP sexp_evid,
				 SEXP sexp_dose,
				 // Covariates
				 SEXP sexp_pcov,
				 SEXP sexp_cov,
				 SEXP sexp_locf,
				 // Solver Options
				 SEXP sexp_atol,
				 SEXP sexp_rtol,
				 SEXP sexp_hmin,
				 SEXP sexp_hmax,
				 SEXP sexp_h0,
				 SEXP sexp_mxordn,
				 SEXP sexp_mxords,
				 SEXP sexp_mx,
				 SEXP sexp_stiff,
				 SEXP sexp_transit_abs,
				 // Object Creation
				 SEXP sexp_object,
				 SEXP sexp_extra_args){
  RxODE_ode_solver ode_solver=(RxODE_ode_solver) R_GetCCallable("RxODE","RxODE_ode_solver");
  assign_fn_pointers(__DYDT__ , __CALC_LHS__ , __CALC_JAC__, __JT__ , __MF__,
#ifdef __DEBUG__
                     1
#else
                     0
#endif
		     );
  ode_solver(sexp_theta,sexp_inits,sexp_lhs,sexp_time,sexp_evid,sexp_dose,sexp_pcov,sexp_cov,sexp_locf,sexp_atol,
	     sexp_rtol,sexp_hmin,sexp_hmax,sexp_h0,sexp_mxordn,sexp_mxords,sexp_mx,sexp_stiff,sexp_transit_abs,
	     sexp_object,sexp_extra_args);
}

//Initilize the dll to match RxODE's calls
void __R_INIT__ (DllInfo *info){
  // Get the RxODE calling interfaces
  InfusionRate   = (RxODE_vec) R_GetCCallable("RxODE","RxODE_InfusionRate");
  update_par_ptr = (RxODE_update_par_ptr) R_GetCCallable("RxODE","RxODE_update_par_ptr");
  par_ptr = (RxODE_vec) R_GetCCallable("RxODE","RxODE_par_ptr");
  dadt_counter_val = (RxODE_cnt) R_GetCCallable("RxODE","RxODE_dadt_counter_val");
  jac_counter_val  = (RxODE_cnt) R_GetCCallable("RxODE","RxODE_jac_counter_val");
  dadt_counter_inc = (RxODE_inc) R_GetCCallable("RxODE","RxODE_dadt_counter_inc");
  jac_counter_inc  = (RxODE_inc) R_GetCCallable("RxODE","RxODE_jac_counter_inc");
  podo  = (RxODE_val) R_GetCCallable("RxODE","RxODE_podo");
  tlast = (RxODE_val) R_GetCCallable("RxODE","RxODE_tlast");
  transit3 = (RxODE_transit3) R_GetCCallable("RxODE","RxODE_transit3");
  transit4 = (RxODE_transit4) R_GetCCallable("RxODE","RxODE_transit4");
  factorial=(RxODE_fn) R_GetCCallable("RxODE","RxODE_factorial");
  polygamma=(RxODE_fn2) R_GetCCallable("RxODE","RxODE_polygamma");
  besseli=(RxODE_fn2) R_GetCCallable("RxODE","RxODE_besseli");
  besselj=(RxODE_fn2) R_GetCCallable("RxODE","RxODE_besselj");
  besselk=(RxODE_fn2) R_GetCCallable("RxODE","RxODE_besselk");
  bessely=(RxODE_fn2) R_GetCCallable("RxODE","RxODE_bessely");
  assign_fn_pointers=(RxODE_assign_fn_pointers) R_GetCCallable("RxODE","RxODE_assign_fn_pointers");
  old_c = (RxODE_ode_solver_old_c) R_GetCCallable("RxODE","RxODE_ode_solver_old_c");
  c_0_6 = (RxODE_ode_solver_0_6_c)R_GetCCallable("RxODE","RxODE_ode_solver_0_6_c");
  // Register the outside functions
  R_RegisterCCallable(__LIB_STR__,__ODE_SOLVER_STR__,       (DL_FUNC) __ODE_SOLVER__);
  R_RegisterCCallable(__LIB_STR__,__ODE_SOLVER_SEXP_STR__,  (DL_FUNC) __ODE_SOLVER_SEXP__);
  R_RegisterCCallable(__LIB_STR__,__ODE_SOLVER_0_6_STR__,   (DL_FUNC) __ODE_SOLVER_0_6__);
  // Register the function pointers so if someone directly calls the
  // ode solvers directly, they use the last loaded RxODE model.
  assign_fn_pointers(__DYDT__ , __CALC_LHS__ , __CALC_JAC__, __JT__ , __MF__,
#ifdef __DEBUG__
				       1
#else
				       0
#endif
				       );
  
}
