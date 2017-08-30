// Generated by refresh.R;Can be recreated by refresh(derivs=TRUE) in source directory after loading RxODE by library(devtools);load_all();
#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>

#define dTlag 8
#define dKa 7

#define _prod RxODE_prodV
#define _sum  RxODE_sumV
#define _sign RxODE_signV
#define safe_zero RxODE_safe_zero

extern double RxODE_signV(unsigned int n, ...);
extern double RxODE_prodV(unsigned int n, ...);
extern double RxODE_sumV(unsigned int n, ...);
extern double RxODE_safe_zero(double x);

extern double rxSolveLinBdInf(int diff1, int diff2, int dA, int dAlpha, double rate, double tT, double t1, double t2, double tinf, double A, double alpha, double tlag){
double ret = 0, tinfA=tinf+tlag;
  if ((diff1 == dA && diff2 == 0) || (diff1 == 0 && diff2 == dA)){
    ret=_prod(4, (double) rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha));
  } else if ((diff1 == dAlpha && diff2 == 0) || (diff1 == 0 && diff2 == dAlpha)){
    ret=_sum(3, (double) _prod(6, (double) A,(double)rate,(double)t1,(double)exp(_prod(2, (double) -alpha,(double)t1)),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(6, (double) A,(double)rate,(double)t2,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(5, (double) A,(double)rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero( R_pow(alpha,2))));
  } else if (t2 <= 0.0 && ((diff1 == dTlag && diff2 == 0) || (diff1 == 0 && diff2 == dTlag))){
    ret=_prod(3, (double) -A,(double)rate,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (t2 > 0.0 && ((diff1 == dTlag && diff2 == 0) || (diff1 == 0 && diff2 == dTlag))){
    ret=_sum(2, (double) _prod(4, (double) A,(double)rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(4, (double) A,(double)rate,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))));
  } else if (diff1 == dA && diff2 == dA){
    ret=0;
  } else if (diff1 == dA && diff2 == dAlpha){
    ret=_sum(3, (double) _prod(5, (double) rate,(double)t1,(double)exp(_prod(2, (double) -alpha,(double)t1)),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(5, (double) rate,(double)t2,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(4, (double) rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero( R_pow(alpha,2))));
  } else if (diff1 == dAlpha && diff2 == dA){
    ret=_sum(3, (double) _prod(5, (double) rate,(double)t1,(double)exp(_prod(2, (double) -alpha,(double)t1)),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(5, (double) rate,(double)t2,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(4, (double) rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero( R_pow(alpha,2))));
  } else if (diff1 == dAlpha && diff2 == dAlpha){
    ret=_sum(6, (double) _prod(6, (double) -A,(double)rate,(double) R_pow(t1,2),(double)exp(_prod(2, (double) -alpha,(double)t1)),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(8, (double) 2,(double)A,(double)rate,(double)t1,(double)t2,(double)exp(_prod(2, (double) -alpha,(double)t1)),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)_prod(6, (double) A,(double)rate,(double) R_pow(t2,2),(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero(alpha)),(double)-_prod(7, (double) 2,(double)A,(double)rate,(double)t1,(double)exp(_prod(2, (double) -alpha,(double)t1)),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero( R_pow(alpha,2))),(double)_prod(7, (double) 2,(double)A,(double)rate,(double)t2,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero( R_pow(alpha,2))),(double)_prod(6, (double) 2,(double)A,(double)rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)t1))),(double)exp(_prod(2, (double) -alpha,(double)t2)),(double)1/safe_zero( R_pow(alpha,3))));
ret=_prod(2, (double) -rate,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
ret=_prod(4, (double) -A,(double)rate,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
ret=_prod(4, (double) -A,(double)alpha,(double)rate,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
ret=_sum(2, (double) _prod(3, (double) rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(3, (double) rate,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))));
ret=_sum(3, (double) _prod(5, (double) A,(double)rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))),(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(5, (double) A,(double)rate,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))),(double)-_prod(6, (double) 2,(double)A,(double)rate,(double)_sum(2, (double) -tinfA,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))));
ret=_sum(2, (double) _prod(5, (double) A,(double)alpha,(double)rate,(double)_sum(2, (double) 1,(double)-exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(6, (double) 3,(double)A,(double)alpha,(double)rate,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tinfA,(double)-tlag)))));
  } else {
    return 0;
  }

  return ret;
}

extern double rxSolveLinBDiff(int diff1, int diff2, int dA, int dAlpha, double dose, double tT, double A, double alpha, double ka, double tlag){
  double ret = 0;
  if (ka > 0 && ((diff1 == dA && diff2 == 0) || (diff1 == 0 && diff2 == dA))){
    ret=_prod(2, (double) dose,(double)_sum(2, (double) -exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))));
  } else if (ka > 0 && ((diff1 == dAlpha && diff2 == 0) || (diff1 == 0 && diff2 == dAlpha))){
    ret=_prod(4, (double) A,(double)dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && ((diff1 == dKa && diff2 == 0) || (diff1 == 0 && diff2 == dKa))){
    ret=_prod(4, (double) -A,(double)dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && ((diff1 == dTlag && diff2 == 0) || (diff1 == 0 && diff2 == dTlag))){
    ret=_prod(3, (double) A,(double)dose,(double)_sum(2, (double) _prod(2, (double) alpha,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(2, (double) ka,(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))))));
  } else if (ka <= 0 && ((diff1 == dA && diff2 == 0) || (diff1 == 0 && diff2 == dA))){
    ret=_prod(2, (double) dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka <= 0 && ((diff1 == dAlpha && diff2 == 0) || (diff1 == 0 && diff2 == dAlpha))){
    ret=_prod(4, (double) A,(double)dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka <= 0 && ((diff1 == dTlag && diff2 == 0) || (diff1 == 0 && diff2 == dTlag))){
    ret=_prod(4, (double) A,(double)alpha,(double)dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && diff1 == dA && diff2 == dA){
    ret=0;
  } else if (ka > 0 && diff1 == dA && diff2 == dAlpha){
    ret=_prod(3, (double) dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && diff1 == dA && diff2 == dKa){
    ret=_prod(3, (double) -dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && diff1 == dA && diff2 == dTlag){
    ret=_prod(2, (double) dose,(double)_sum(2, (double) _prod(2, (double) alpha,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(2, (double) ka,(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))))));
  } else if (ka > 0 && diff1 == dAlpha && diff2 == dA){
    ret=_prod(3, (double) dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && diff1 == dAlpha && diff2 == dAlpha){
    ret=_prod(4, (double) A,(double)dose,(double) R_pow(_sum(2, (double) -tT,(double)tlag),2),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && diff1 == dAlpha && diff2 == dKa){
    ret=0;
  } else if (ka > 0 && diff1 == dAlpha && diff2 == dTlag){
    ret=_sum(2, (double) _prod(5, (double) A,(double)alpha,(double)dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)_prod(3, (double) A,(double)dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))));
  } else if (ka > 0 && diff1 == dKa && diff2 == dA){
    ret=_prod(3, (double) -dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && diff1 == dKa && diff2 == dAlpha){
    ret=0;
  } else if (ka > 0 && diff1 == dKa && diff2 == dKa){
    ret=_prod(4, (double) -A,(double)dose,(double) R_pow(_sum(2, (double) -tT,(double)tlag),2),(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka > 0 && diff1 == dKa && diff2 == dTlag){
    ret=_sum(2, (double) _prod(5, (double) -A,(double)dose,(double)ka,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(3, (double) A,(double)dose,(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag)))));
  } else if (ka > 0 && diff1 == dTlag && diff2 == dA){
    ret=_prod(2, (double) dose,(double)_sum(2, (double) _prod(2, (double) alpha,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(2, (double) ka,(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))))));
  } else if (ka > 0 && diff1 == dTlag && diff2 == dAlpha){
    ret=_prod(3, (double) A,(double)dose,(double)_sum(2, (double) _prod(3, (double) alpha,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))));
  } else if (ka > 0 && diff1 == dTlag && diff2 == dKa){
    ret=_prod(3, (double) A,(double)dose,(double)_sum(2, (double) _prod(3, (double) -ka,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag)))));
  } else if (ka > 0 && diff1 == dTlag && diff2 == dTlag){
    ret=_prod(3, (double) A,(double)dose,(double)_sum(2, (double) _prod(2, (double)  R_pow(alpha,2),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)-_prod(2, (double)  R_pow(ka,2),(double)exp(_prod(2, (double) -ka,(double)_sum(2, (double) tT,(double)-tlag))))));
  } else if (ka <= 0 && diff1 == dA && diff2 == dA){
    ret=0;
  } else if (ka <= 0 && diff1 == dA && diff2 == dAlpha){
    ret=_prod(3, (double) dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka <= 0 && diff1 == dA && diff2 == dTlag){
    ret=_prod(3, (double) alpha,(double)dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka <= 0 && diff1 == dAlpha && diff2 == dA){
    ret=_prod(3, (double) dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka <= 0 && diff1 == dAlpha && diff2 == dAlpha){
    ret=_prod(4, (double) A,(double)dose,(double) R_pow(_sum(2, (double) -tT,(double)tlag),2),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka <= 0 && diff1 == dAlpha && diff2 == dTlag){
    ret=_sum(2, (double) _prod(5, (double) A,(double)alpha,(double)dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)_prod(3, (double) A,(double)dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))));
  } else if (ka <= 0 && diff1 == dTlag && diff2 == dA){
    ret=_prod(3, (double) alpha,(double)dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else if (ka <= 0 && diff1 == dTlag && diff2 == dAlpha){
    ret=_sum(2, (double) _prod(5, (double) A,(double)alpha,(double)dose,(double)_sum(2, (double) -tT,(double)tlag),(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))),(double)_prod(3, (double) A,(double)dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag)))));
  } else if (ka <= 0 && diff1 == dTlag && diff2 == dTlag){
    ret=_prod(4, (double) A,(double) R_pow(alpha,2),(double)dose,(double)exp(_prod(2, (double) -alpha,(double)_sum(2, (double) tT,(double)-tlag))));
  } else {
    return 0;
  }

  return ret;
}
