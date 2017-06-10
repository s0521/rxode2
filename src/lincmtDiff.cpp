// [[Rcpp::depends(RcppArmadillo)]]
// Generated by refresh.R;Can be recreated by refresh(derivs=TRUE) in source directory after loading RxODE by library(devtools);load_all();
#include <RcppArmadillo.h>
#include <R.h>
using namespace Rcpp;
using namespace R;
using namespace arma;
extern "C" double getLinDeriv(int ncmt, int diff1, int diff2, double rate, double tinf, double Dose, double ka, double tlag, double T, double tT, mat par);
double getLinDeriv(int ncmt, int diff1, int diff2, double rate, double tinf, double Dose, double ka, double tlag, double T, double tT, mat par){
double ret = 0;

 if(ncmt==1&&ka>0&&diff1==1&&diff2==0){//dA
 ret+=Dose*(-exp(-T*ka)+exp(-T*par(0,0)));
 return ret;
}//dA
if(ncmt==1&&ka>0&&diff1==1&&diff2==1){//dA.dA
 ret+=0;
 return ret;
}//dA.dA
if(ncmt==1&&ka>0&&diff1==1&&diff2==2){//dA.dALPHA
 ret-=Dose*T*exp(-T*par(0,0));
 return ret;
}//dA.dALPHA
if(ncmt==1&&ka>0&&diff1==1&&diff2==7){//dA.dKA
 ret+=Dose*T*exp(-T*ka);
 return ret;
}//dA.dKA
if(ncmt==1&&ka>0&&diff1==1&&diff2==8){//dA.dTLAG
 ret+=Dose*(par(0,0)*exp(-par(0,0)*(tT-tlag))-ka*exp(-ka*(tT-tlag)));
 return ret;
}//dA.dTLAG
if(ncmt==1&&ka>0&&diff1==2&&diff2==0){//dALPHA
 ret-=par(0,1)*Dose*T*exp(-T*par(0,0));
 return ret;
}//dALPHA
if(ncmt==1&&ka>0&&diff1==2&&diff2==2){//dALPHA.dALPHA
 ret+=par(0,1)*Dose*pow(T,2)*exp(-T*par(0,0));
 return ret;
}//dALPHA.dALPHA
if(ncmt==1&&ka>0&&diff1==2&&diff2==7){//dALPHA.dKA
 ret+=0;
 return ret;
}//dALPHA.dKA
if(ncmt==1&&ka>0&&diff1==2&&diff2==8){//dALPHA.dTLAG
 ret+=par(0,1)*Dose*par(0,0)*(-tT+tlag)*exp(-par(0,0)*(tT-tlag));
 ret+=par(0,1)*Dose*exp(-par(0,0)*(tT-tlag));
 return ret;
}//dALPHA.dTLAG
if(ncmt==1&&ka>0&&diff1==7&&diff2==0){//dKA
 ret+=par(0,1)*Dose*T*exp(-T*ka);
 return ret;
}//dKA
if(ncmt==1&&ka>0&&diff1==7&&diff2==7){//dKA.dKA
 ret-=par(0,1)*Dose*pow(T,2)*exp(-T*ka);
 return ret;
}//dKA.dKA
if(ncmt==1&&ka>0&&diff1==7&&diff2==8){//dKA.dTLAG
 ret-=par(0,1)*Dose*ka*(-tT+tlag)*exp(-ka*(tT-tlag));
 ret-=par(0,1)*Dose*exp(-ka*(tT-tlag));
 return ret;
}//dKA.dTLAG
if(ncmt==1&&ka>0&&diff1==8&&diff2==0){//dTLAG
 ret+=par(0,1)*Dose*(par(0,0)*exp(-par(0,0)*(tT-tlag))-ka*exp(-ka*(tT-tlag)));
 return ret;
}//dTLAG
if(ncmt==1&&ka>0&&diff1==8&&diff2==8){//dTLAG.dTLAG
 ret+=par(0,1)*Dose*(pow(par(0,0),2)*exp(-par(0,0)*(tT-tlag))-pow(ka,2)*exp(-ka*(tT-tlag)));
 return ret;
}//dTLAG.dTLAG
 if(ncmt==1&&ka<=0&&diff1==1&&diff2==0){//dA
if(rate>0){
 if(T<=tinf){
  ret+=rate*(1-exp(-T*par(0,0)))/par(0,0);
 }else{
  ret+=rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/par(0,0);
 }
}else{
  ret+=Dose*exp(-T*par(0,0));
}
 return ret;
}//dA
if(ncmt==1&&ka<=0&&diff1==1&&diff2==1){//dA.dA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dA
if(ncmt==1&&ka<=0&&diff1==1&&diff2==2){//dA.dALPHA
if(rate>0){
 if(T<=tinf){
  ret+=T*rate*exp(-T*par(0,0))/par(0,0);
  ret-=rate*(1-exp(-T*par(0,0)))/pow(par(0,0),2);
 }else{
  ret+=rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
 }
}else{
  ret-=Dose*T*exp(-T*par(0,0));
}
 return ret;
}//dA.dALPHA
if(ncmt==1&&ka<=0&&diff1==2&&diff2==0){//dALPHA
if(rate>0){
 if(T<=tinf){
  ret+=par(0,1)*T*rate*exp(-T*par(0,0))/par(0,0);
  ret-=par(0,1)*rate*(1-exp(-T*par(0,0)))/pow(par(0,0),2);
 }else{
  ret+=par(0,1)*rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
 }
}else{
  ret-=par(0,1)*Dose*T*exp(-T*par(0,0));
}
 return ret;
}//dALPHA
if(ncmt==1&&ka<=0&&diff1==2&&diff2==2){//dALPHA.dALPHA
if(rate>0){
 if(T<=tinf){
  ret-=par(0,1)*pow(T,2)*rate*exp(-T*par(0,0))/par(0,0);
  ret-=2*par(0,1)*T*rate*exp(-T*par(0,0))/pow(par(0,0),2);
  ret+=2*par(0,1)*rate*(1-exp(-T*par(0,0)))/pow(par(0,0),3);
 }else{
  ret-=par(0,1)*rate*pow(tinf,2)*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=2*par(0,1)*rate*tinf*(-T+tinf)*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*pow((-T+tinf),2)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=2*par(0,1)*rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
  ret-=2*par(0,1)*rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
  ret+=2*par(0,1)*rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),3);
 }
}else{
  ret+=par(0,1)*Dose*pow(T,2)*exp(-T*par(0,0));
}
 return ret;
}//dALPHA.dALPHA
 if(ncmt==2&&ka>0&&diff1==1&&diff2==0){//dA
 ret+=Dose*(-exp(-T*ka)+exp(-T*par(0,0)));
 return ret;
}//dA
if(ncmt==2&&ka>0&&diff1==1&&diff2==1){//dA.dA
 ret+=0;
 return ret;
}//dA.dA
if(ncmt==2&&ka>0&&diff1==1&&diff2==2){//dA.dALPHA
 ret-=Dose*T*exp(-T*par(0,0));
 return ret;
}//dA.dALPHA
if(ncmt==2&&ka>0&&diff1==1&&diff2==3){//dA.dB
 ret+=0;
 return ret;
}//dA.dB
if(ncmt==2&&ka>0&&diff1==1&&diff2==4){//dA.dBETA
 ret+=0;
 return ret;
}//dA.dBETA
if(ncmt==2&&ka>0&&diff1==1&&diff2==7){//dA.dKA
 ret+=Dose*T*exp(-T*ka);
 return ret;
}//dA.dKA
if(ncmt==2&&ka>0&&diff1==1&&diff2==8){//dA.dTLAG
 ret+=Dose*(par(0,0)*exp(-par(0,0)*(tT-tlag))-ka*exp(-ka*(tT-tlag)));
 return ret;
}//dA.dTLAG
if(ncmt==2&&ka>0&&diff1==2&&diff2==0){//dALPHA
 ret-=par(0,1)*Dose*T*exp(-T*par(0,0));
 return ret;
}//dALPHA
if(ncmt==2&&ka>0&&diff1==2&&diff2==2){//dALPHA.dALPHA
 ret+=par(0,1)*Dose*pow(T,2)*exp(-T*par(0,0));
 return ret;
}//dALPHA.dALPHA
if(ncmt==2&&ka>0&&diff1==2&&diff2==3){//dALPHA.dB
 ret+=0;
 return ret;
}//dALPHA.dB
if(ncmt==2&&ka>0&&diff1==2&&diff2==4){//dALPHA.dBETA
 ret+=0;
 return ret;
}//dALPHA.dBETA
if(ncmt==2&&ka>0&&diff1==2&&diff2==7){//dALPHA.dKA
 ret+=0;
 return ret;
}//dALPHA.dKA
if(ncmt==2&&ka>0&&diff1==2&&diff2==8){//dALPHA.dTLAG
 ret+=par(0,1)*Dose*par(0,0)*(-tT+tlag)*exp(-par(0,0)*(tT-tlag));
 ret+=par(0,1)*Dose*exp(-par(0,0)*(tT-tlag));
 return ret;
}//dALPHA.dTLAG
if(ncmt==2&&ka>0&&diff1==3&&diff2==0){//dB
 ret+=Dose*(exp(-T*par(1,0))-exp(-T*ka));
 return ret;
}//dB
if(ncmt==2&&ka>0&&diff1==3&&diff2==3){//dB.dB
 ret+=0;
 return ret;
}//dB.dB
if(ncmt==2&&ka>0&&diff1==3&&diff2==4){//dB.dBETA
 ret-=Dose*T*exp(-T*par(1,0));
 return ret;
}//dB.dBETA
if(ncmt==2&&ka>0&&diff1==3&&diff2==7){//dB.dKA
 ret+=Dose*T*exp(-T*ka);
 return ret;
}//dB.dKA
if(ncmt==2&&ka>0&&diff1==3&&diff2==8){//dB.dTLAG
 ret+=Dose*(-ka*exp(-ka*(tT-tlag))+par(1,0)*exp(-par(1,0)*(tT-tlag)));
 return ret;
}//dB.dTLAG
if(ncmt==2&&ka>0&&diff1==4&&diff2==0){//dBETA
 ret-=par(1,1)*Dose*T*exp(-T*par(1,0));
 return ret;
}//dBETA
if(ncmt==2&&ka>0&&diff1==4&&diff2==4){//dBETA.dBETA
 ret+=par(1,1)*Dose*pow(T,2)*exp(-T*par(1,0));
 return ret;
}//dBETA.dBETA
if(ncmt==2&&ka>0&&diff1==4&&diff2==7){//dBETA.dKA
 ret+=0;
 return ret;
}//dBETA.dKA
if(ncmt==2&&ka>0&&diff1==4&&diff2==8){//dBETA.dTLAG
 ret+=par(1,1)*Dose*par(1,0)*(-tT+tlag)*exp(-par(1,0)*(tT-tlag));
 ret+=par(1,1)*Dose*exp(-par(1,0)*(tT-tlag));
 return ret;
}//dBETA.dTLAG
if(ncmt==2&&ka>0&&diff1==7&&diff2==0){//dKA
 ret+=par(0,1)*Dose*T*exp(-T*ka);
 ret+=par(1,1)*Dose*T*exp(-T*ka);
 return ret;
}//dKA
if(ncmt==2&&ka>0&&diff1==7&&diff2==7){//dKA.dKA
 ret-=par(0,1)*Dose*pow(T,2)*exp(-T*ka);
 ret-=par(1,1)*Dose*pow(T,2)*exp(-T*ka);
 return ret;
}//dKA.dKA
if(ncmt==2&&ka>0&&diff1==7&&diff2==8){//dKA.dTLAG
 ret-=par(0,1)*Dose*ka*(-tT+tlag)*exp(-ka*(tT-tlag));
 ret-=par(0,1)*Dose*exp(-ka*(tT-tlag));
 ret-=par(1,1)*Dose*ka*(-tT+tlag)*exp(-ka*(tT-tlag));
 ret-=par(1,1)*Dose*exp(-ka*(tT-tlag));
 return ret;
}//dKA.dTLAG
if(ncmt==2&&ka>0&&diff1==8&&diff2==0){//dTLAG
 ret+=par(0,1)*Dose*(par(0,0)*exp(-par(0,0)*(tT-tlag))-ka*exp(-ka*(tT-tlag)));
 ret+=par(1,1)*Dose*(-ka*exp(-ka*(tT-tlag))+par(1,0)*exp(-par(1,0)*(tT-tlag)));
 return ret;
}//dTLAG
if(ncmt==2&&ka>0&&diff1==8&&diff2==8){//dTLAG.dTLAG
 ret+=par(0,1)*Dose*(pow(par(0,0),2)*exp(-par(0,0)*(tT-tlag))-pow(ka,2)*exp(-ka*(tT-tlag)));
 ret+=par(1,1)*Dose*(-pow(ka,2)*exp(-ka*(tT-tlag))+pow(par(1,0),2)*exp(-par(1,0)*(tT-tlag)));
 return ret;
}//dTLAG.dTLAG
 if(ncmt==2&&ka<=0&&diff1==1&&diff2==0){//dA
if(rate>0){
 if(T<=tinf){
  ret+=rate*(1-exp(-T*par(0,0)))/par(0,0);
 }else{
  ret+=rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/par(0,0);
 }
}else{
  ret+=Dose*exp(-T*par(0,0));
}
 return ret;
}//dA
if(ncmt==2&&ka<=0&&diff1==1&&diff2==1){//dA.dA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dA
if(ncmt==2&&ka<=0&&diff1==1&&diff2==2){//dA.dALPHA
if(rate>0){
 if(T<=tinf){
  ret+=T*rate*exp(-T*par(0,0))/par(0,0);
  ret-=rate*(1-exp(-T*par(0,0)))/pow(par(0,0),2);
 }else{
  ret+=rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
 }
}else{
  ret-=Dose*T*exp(-T*par(0,0));
}
 return ret;
}//dA.dALPHA
if(ncmt==2&&ka<=0&&diff1==1&&diff2==3){//dA.dB
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dB
if(ncmt==2&&ka<=0&&diff1==1&&diff2==4){//dA.dBETA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dBETA
if(ncmt==2&&ka<=0&&diff1==2&&diff2==0){//dALPHA
if(rate>0){
 if(T<=tinf){
  ret+=par(0,1)*T*rate*exp(-T*par(0,0))/par(0,0);
  ret-=par(0,1)*rate*(1-exp(-T*par(0,0)))/pow(par(0,0),2);
 }else{
  ret+=par(0,1)*rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
 }
}else{
  ret-=par(0,1)*Dose*T*exp(-T*par(0,0));
}
 return ret;
}//dALPHA
if(ncmt==2&&ka<=0&&diff1==2&&diff2==2){//dALPHA.dALPHA
if(rate>0){
 if(T<=tinf){
  ret-=par(0,1)*pow(T,2)*rate*exp(-T*par(0,0))/par(0,0);
  ret-=2*par(0,1)*T*rate*exp(-T*par(0,0))/pow(par(0,0),2);
  ret+=2*par(0,1)*rate*(1-exp(-T*par(0,0)))/pow(par(0,0),3);
 }else{
  ret-=par(0,1)*rate*pow(tinf,2)*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=2*par(0,1)*rate*tinf*(-T+tinf)*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*pow((-T+tinf),2)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=2*par(0,1)*rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
  ret-=2*par(0,1)*rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
  ret+=2*par(0,1)*rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),3);
 }
}else{
  ret+=par(0,1)*Dose*pow(T,2)*exp(-T*par(0,0));
}
 return ret;
}//dALPHA.dALPHA
if(ncmt==2&&ka<=0&&diff1==2&&diff2==3){//dALPHA.dB
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dALPHA.dB
if(ncmt==2&&ka<=0&&diff1==2&&diff2==4){//dALPHA.dBETA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dALPHA.dBETA
if(ncmt==2&&ka<=0&&diff1==3&&diff2==0){//dB
if(rate>0){
 if(T<=tinf){
  ret+=rate*(1-exp(-T*par(1,0)))/par(1,0);
 }else{
  ret+=rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/par(1,0);
 }
}else{
  ret+=Dose*exp(-T*par(1,0));
}
 return ret;
}//dB
if(ncmt==2&&ka<=0&&diff1==3&&diff2==3){//dB.dB
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dB.dB
if(ncmt==2&&ka<=0&&diff1==3&&diff2==4){//dB.dBETA
if(rate>0){
 if(T<=tinf){
  ret+=T*rate*exp(-T*par(1,0))/par(1,0);
  ret-=rate*(1-exp(-T*par(1,0)))/pow(par(1,0),2);
 }else{
  ret+=rate*tinf*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=rate*(1-exp(-par(1,0)*tinf))*(-T+tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret-=rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
 }
}else{
  ret-=Dose*T*exp(-T*par(1,0));
}
 return ret;
}//dB.dBETA
if(ncmt==2&&ka<=0&&diff1==4&&diff2==0){//dBETA
if(rate>0){
 if(T<=tinf){
  ret+=par(1,1)*T*rate*exp(-T*par(1,0))/par(1,0);
  ret-=par(1,1)*rate*(1-exp(-T*par(1,0)))/pow(par(1,0),2);
 }else{
  ret+=par(1,1)*rate*tinf*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=par(1,1)*rate*(1-exp(-par(1,0)*tinf))*(-T+tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret-=par(1,1)*rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
 }
}else{
  ret-=par(1,1)*Dose*T*exp(-T*par(1,0));
}
 return ret;
}//dBETA
if(ncmt==2&&ka<=0&&diff1==4&&diff2==4){//dBETA.dBETA
if(rate>0){
 if(T<=tinf){
  ret-=par(1,1)*pow(T,2)*rate*exp(-T*par(1,0))/par(1,0);
  ret-=2*par(1,1)*T*rate*exp(-T*par(1,0))/pow(par(1,0),2);
  ret+=2*par(1,1)*rate*(1-exp(-T*par(1,0)))/pow(par(1,0),3);
 }else{
  ret-=par(1,1)*rate*pow(tinf,2)*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=2*par(1,1)*rate*tinf*(-T+tinf)*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=par(1,1)*rate*(1-exp(-par(1,0)*tinf))*pow((-T+tinf),2)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret-=2*par(1,1)*rate*tinf*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
  ret-=2*par(1,1)*rate*(1-exp(-par(1,0)*tinf))*(-T+tinf)*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
  ret+=2*par(1,1)*rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/pow(par(1,0),3);
 }
}else{
  ret+=par(1,1)*Dose*pow(T,2)*exp(-T*par(1,0));
}
 return ret;
}//dBETA.dBETA
 if(ncmt==3&&ka>0&&diff1==1&&diff2==0){//dA
 ret+=Dose*(-exp(-T*ka)+exp(-T*par(0,0)));
 return ret;
}//dA
if(ncmt==3&&ka>0&&diff1==1&&diff2==1){//dA.dA
 ret+=0;
 return ret;
}//dA.dA
if(ncmt==3&&ka>0&&diff1==1&&diff2==2){//dA.dALPHA
 ret-=Dose*T*exp(-T*par(0,0));
 return ret;
}//dA.dALPHA
if(ncmt==3&&ka>0&&diff1==1&&diff2==3){//dA.dB
 ret+=0;
 return ret;
}//dA.dB
if(ncmt==3&&ka>0&&diff1==1&&diff2==4){//dA.dBETA
 ret+=0;
 return ret;
}//dA.dBETA
if(ncmt==3&&ka>0&&diff1==1&&diff2==5){//dA.dC
 ret+=0;
 return ret;
}//dA.dC
if(ncmt==3&&ka>0&&diff1==1&&diff2==6){//dA.dGAMMA
 ret+=0;
 return ret;
}//dA.dGAMMA
if(ncmt==3&&ka>0&&diff1==1&&diff2==7){//dA.dKA
 ret+=Dose*T*exp(-T*ka);
 return ret;
}//dA.dKA
if(ncmt==3&&ka>0&&diff1==1&&diff2==8){//dA.dTLAG
 ret+=Dose*(par(0,0)*exp(-par(0,0)*(tT-tlag))-ka*exp(-ka*(tT-tlag)));
 return ret;
}//dA.dTLAG
if(ncmt==3&&ka>0&&diff1==2&&diff2==0){//dALPHA
 ret-=par(0,1)*Dose*T*exp(-T*par(0,0));
 return ret;
}//dALPHA
if(ncmt==3&&ka>0&&diff1==2&&diff2==2){//dALPHA.dALPHA
 ret+=par(0,1)*Dose*pow(T,2)*exp(-T*par(0,0));
 return ret;
}//dALPHA.dALPHA
if(ncmt==3&&ka>0&&diff1==2&&diff2==3){//dALPHA.dB
 ret+=0;
 return ret;
}//dALPHA.dB
if(ncmt==3&&ka>0&&diff1==2&&diff2==4){//dALPHA.dBETA
 ret+=0;
 return ret;
}//dALPHA.dBETA
if(ncmt==3&&ka>0&&diff1==2&&diff2==5){//dALPHA.dC
 ret+=0;
 return ret;
}//dALPHA.dC
if(ncmt==3&&ka>0&&diff1==2&&diff2==6){//dALPHA.dGAMMA
 ret+=0;
 return ret;
}//dALPHA.dGAMMA
if(ncmt==3&&ka>0&&diff1==2&&diff2==7){//dALPHA.dKA
 ret+=0;
 return ret;
}//dALPHA.dKA
if(ncmt==3&&ka>0&&diff1==2&&diff2==8){//dALPHA.dTLAG
 ret+=par(0,1)*Dose*par(0,0)*(-tT+tlag)*exp(-par(0,0)*(tT-tlag));
 ret+=par(0,1)*Dose*exp(-par(0,0)*(tT-tlag));
 return ret;
}//dALPHA.dTLAG
if(ncmt==3&&ka>0&&diff1==3&&diff2==0){//dB
 ret+=Dose*(exp(-T*par(1,0))-exp(-T*ka));
 return ret;
}//dB
if(ncmt==3&&ka>0&&diff1==3&&diff2==3){//dB.dB
 ret+=0;
 return ret;
}//dB.dB
if(ncmt==3&&ka>0&&diff1==3&&diff2==4){//dB.dBETA
 ret-=Dose*T*exp(-T*par(1,0));
 return ret;
}//dB.dBETA
if(ncmt==3&&ka>0&&diff1==3&&diff2==5){//dB.dC
 ret+=0;
 return ret;
}//dB.dC
if(ncmt==3&&ka>0&&diff1==3&&diff2==6){//dB.dGAMMA
 ret+=0;
 return ret;
}//dB.dGAMMA
if(ncmt==3&&ka>0&&diff1==3&&diff2==7){//dB.dKA
 ret+=Dose*T*exp(-T*ka);
 return ret;
}//dB.dKA
if(ncmt==3&&ka>0&&diff1==3&&diff2==8){//dB.dTLAG
 ret+=Dose*(-ka*exp(-ka*(tT-tlag))+par(1,0)*exp(-par(1,0)*(tT-tlag)));
 return ret;
}//dB.dTLAG
if(ncmt==3&&ka>0&&diff1==4&&diff2==0){//dBETA
 ret-=par(1,1)*Dose*T*exp(-T*par(1,0));
 return ret;
}//dBETA
if(ncmt==3&&ka>0&&diff1==4&&diff2==4){//dBETA.dBETA
 ret+=par(1,1)*Dose*pow(T,2)*exp(-T*par(1,0));
 return ret;
}//dBETA.dBETA
if(ncmt==3&&ka>0&&diff1==4&&diff2==5){//dBETA.dC
 ret+=0;
 return ret;
}//dBETA.dC
if(ncmt==3&&ka>0&&diff1==4&&diff2==6){//dBETA.dGAMMA
 ret+=0;
 return ret;
}//dBETA.dGAMMA
if(ncmt==3&&ka>0&&diff1==4&&diff2==7){//dBETA.dKA
 ret+=0;
 return ret;
}//dBETA.dKA
if(ncmt==3&&ka>0&&diff1==4&&diff2==8){//dBETA.dTLAG
 ret+=par(1,1)*Dose*par(1,0)*(-tT+tlag)*exp(-par(1,0)*(tT-tlag));
 ret+=par(1,1)*Dose*exp(-par(1,0)*(tT-tlag));
 return ret;
}//dBETA.dTLAG
if(ncmt==3&&ka>0&&diff1==5&&diff2==0){//dC
 ret+=Dose*(exp(-T*par(2,0))-exp(-T*ka));
 return ret;
}//dC
if(ncmt==3&&ka>0&&diff1==5&&diff2==5){//dC.dC
 ret+=0;
 return ret;
}//dC.dC
if(ncmt==3&&ka>0&&diff1==5&&diff2==6){//dC.dGAMMA
 ret-=Dose*T*exp(-T*par(2,0));
 return ret;
}//dC.dGAMMA
if(ncmt==3&&ka>0&&diff1==5&&diff2==7){//dC.dKA
 ret+=Dose*T*exp(-T*ka);
 return ret;
}//dC.dKA
if(ncmt==3&&ka>0&&diff1==5&&diff2==8){//dC.dTLAG
 ret+=Dose*(-ka*exp(-ka*(tT-tlag))+par(2,0)*exp(-par(2,0)*(tT-tlag)));
 return ret;
}//dC.dTLAG
if(ncmt==3&&ka>0&&diff1==6&&diff2==0){//dGAMMA
 ret-=Dose*T*par(2,1)*exp(-T*par(2,0));
 return ret;
}//dGAMMA
if(ncmt==3&&ka>0&&diff1==6&&diff2==6){//dGAMMA.dGAMMA
 ret+=Dose*pow(T,2)*par(2,1)*exp(-T*par(2,0));
 return ret;
}//dGAMMA.dGAMMA
if(ncmt==3&&ka>0&&diff1==6&&diff2==7){//dGAMMA.dKA
 ret+=0;
 return ret;
}//dGAMMA.dKA
if(ncmt==3&&ka>0&&diff1==6&&diff2==8){//dGAMMA.dTLAG
 ret+=Dose*par(2,1)*par(2,0)*(-tT+tlag)*exp(-par(2,0)*(tT-tlag));
 ret+=Dose*par(2,1)*exp(-par(2,0)*(tT-tlag));
 return ret;
}//dGAMMA.dTLAG
if(ncmt==3&&ka>0&&diff1==7&&diff2==0){//dKA
 ret+=par(0,1)*Dose*T*exp(-T*ka);
 ret+=par(1,1)*Dose*T*exp(-T*ka);
 ret+=Dose*T*par(2,1)*exp(-T*ka);
 return ret;
}//dKA
if(ncmt==3&&ka>0&&diff1==7&&diff2==7){//dKA.dKA
 ret-=par(0,1)*Dose*pow(T,2)*exp(-T*ka);
 ret-=par(1,1)*Dose*pow(T,2)*exp(-T*ka);
 ret-=Dose*pow(T,2)*par(2,1)*exp(-T*ka);
 return ret;
}//dKA.dKA
if(ncmt==3&&ka>0&&diff1==7&&diff2==8){//dKA.dTLAG
 ret-=par(0,1)*Dose*ka*(-tT+tlag)*exp(-ka*(tT-tlag));
 ret-=par(0,1)*Dose*exp(-ka*(tT-tlag));
 ret-=par(1,1)*Dose*ka*(-tT+tlag)*exp(-ka*(tT-tlag));
 ret-=par(1,1)*Dose*exp(-ka*(tT-tlag));
 ret-=Dose*ka*par(2,1)*(-tT+tlag)*exp(-ka*(tT-tlag));
 ret-=Dose*par(2,1)*exp(-ka*(tT-tlag));
 return ret;
}//dKA.dTLAG
if(ncmt==3&&ka>0&&diff1==8&&diff2==0){//dTLAG
 ret+=par(0,1)*Dose*(par(0,0)*exp(-par(0,0)*(tT-tlag))-ka*exp(-ka*(tT-tlag)));
 ret+=par(1,1)*Dose*(-ka*exp(-ka*(tT-tlag))+par(1,0)*exp(-par(1,0)*(tT-tlag)));
 ret+=Dose*par(2,1)*(-ka*exp(-ka*(tT-tlag))+par(2,0)*exp(-par(2,0)*(tT-tlag)));
 return ret;
}//dTLAG
if(ncmt==3&&ka>0&&diff1==8&&diff2==8){//dTLAG.dTLAG
 ret+=par(0,1)*Dose*(pow(par(0,0),2)*exp(-par(0,0)*(tT-tlag))-pow(ka,2)*exp(-ka*(tT-tlag)));
 ret+=par(1,1)*Dose*(-pow(ka,2)*exp(-ka*(tT-tlag))+pow(par(1,0),2)*exp(-par(1,0)*(tT-tlag)));
 ret+=Dose*par(2,1)*(-pow(ka,2)*exp(-ka*(tT-tlag))+pow(par(2,0),2)*exp(-par(2,0)*(tT-tlag)));
 return ret;
}//dTLAG.dTLAG
 if(ncmt==3&&ka<=0&&diff1==1&&diff2==0){//dA
if(rate>0){
 if(T<=tinf){
  ret+=rate*(1-exp(-T*par(0,0)))/par(0,0);
 }else{
  ret+=rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/par(0,0);
 }
}else{
  ret+=Dose*exp(-T*par(0,0));
}
 return ret;
}//dA
if(ncmt==3&&ka<=0&&diff1==1&&diff2==1){//dA.dA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dA
if(ncmt==3&&ka<=0&&diff1==1&&diff2==2){//dA.dALPHA
if(rate>0){
 if(T<=tinf){
  ret+=T*rate*exp(-T*par(0,0))/par(0,0);
  ret-=rate*(1-exp(-T*par(0,0)))/pow(par(0,0),2);
 }else{
  ret+=rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
 }
}else{
  ret-=Dose*T*exp(-T*par(0,0));
}
 return ret;
}//dA.dALPHA
if(ncmt==3&&ka<=0&&diff1==1&&diff2==3){//dA.dB
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dB
if(ncmt==3&&ka<=0&&diff1==1&&diff2==4){//dA.dBETA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dBETA
if(ncmt==3&&ka<=0&&diff1==1&&diff2==5){//dA.dC
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dC
if(ncmt==3&&ka<=0&&diff1==1&&diff2==6){//dA.dGAMMA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dA.dGAMMA
if(ncmt==3&&ka<=0&&diff1==2&&diff2==0){//dALPHA
if(rate>0){
 if(T<=tinf){
  ret+=par(0,1)*T*rate*exp(-T*par(0,0))/par(0,0);
  ret-=par(0,1)*rate*(1-exp(-T*par(0,0)))/pow(par(0,0),2);
 }else{
  ret+=par(0,1)*rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
 }
}else{
  ret-=par(0,1)*Dose*T*exp(-T*par(0,0));
}
 return ret;
}//dALPHA
if(ncmt==3&&ka<=0&&diff1==2&&diff2==2){//dALPHA.dALPHA
if(rate>0){
 if(T<=tinf){
  ret-=par(0,1)*pow(T,2)*rate*exp(-T*par(0,0))/par(0,0);
  ret-=2*par(0,1)*T*rate*exp(-T*par(0,0))/pow(par(0,0),2);
  ret+=2*par(0,1)*rate*(1-exp(-T*par(0,0)))/pow(par(0,0),3);
 }else{
  ret-=par(0,1)*rate*pow(tinf,2)*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=2*par(0,1)*rate*tinf*(-T+tinf)*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret+=par(0,1)*rate*(1-exp(-par(0,0)*tinf))*pow((-T+tinf),2)*exp(-par(0,0)*(T-tinf))/par(0,0);
  ret-=2*par(0,1)*rate*tinf*exp(-par(0,0)*tinf)*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
  ret-=2*par(0,1)*rate*(1-exp(-par(0,0)*tinf))*(-T+tinf)*exp(-par(0,0)*(T-tinf))/pow(par(0,0),2);
  ret+=2*par(0,1)*rate*(1-exp(-par(0,0)*tinf))*exp(-par(0,0)*(T-tinf))/pow(par(0,0),3);
 }
}else{
  ret+=par(0,1)*Dose*pow(T,2)*exp(-T*par(0,0));
}
 return ret;
}//dALPHA.dALPHA
if(ncmt==3&&ka<=0&&diff1==2&&diff2==3){//dALPHA.dB
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dALPHA.dB
if(ncmt==3&&ka<=0&&diff1==2&&diff2==4){//dALPHA.dBETA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dALPHA.dBETA
if(ncmt==3&&ka<=0&&diff1==2&&diff2==5){//dALPHA.dC
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dALPHA.dC
if(ncmt==3&&ka<=0&&diff1==2&&diff2==6){//dALPHA.dGAMMA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dALPHA.dGAMMA
if(ncmt==3&&ka<=0&&diff1==3&&diff2==0){//dB
if(rate>0){
 if(T<=tinf){
  ret+=rate*(1-exp(-T*par(1,0)))/par(1,0);
 }else{
  ret+=rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/par(1,0);
 }
}else{
  ret+=Dose*exp(-T*par(1,0));
}
 return ret;
}//dB
if(ncmt==3&&ka<=0&&diff1==3&&diff2==3){//dB.dB
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dB.dB
if(ncmt==3&&ka<=0&&diff1==3&&diff2==4){//dB.dBETA
if(rate>0){
 if(T<=tinf){
  ret+=T*rate*exp(-T*par(1,0))/par(1,0);
  ret-=rate*(1-exp(-T*par(1,0)))/pow(par(1,0),2);
 }else{
  ret+=rate*tinf*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=rate*(1-exp(-par(1,0)*tinf))*(-T+tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret-=rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
 }
}else{
  ret-=Dose*T*exp(-T*par(1,0));
}
 return ret;
}//dB.dBETA
if(ncmt==3&&ka<=0&&diff1==3&&diff2==5){//dB.dC
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dB.dC
if(ncmt==3&&ka<=0&&diff1==3&&diff2==6){//dB.dGAMMA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dB.dGAMMA
if(ncmt==3&&ka<=0&&diff1==4&&diff2==0){//dBETA
if(rate>0){
 if(T<=tinf){
  ret+=par(1,1)*T*rate*exp(-T*par(1,0))/par(1,0);
  ret-=par(1,1)*rate*(1-exp(-T*par(1,0)))/pow(par(1,0),2);
 }else{
  ret+=par(1,1)*rate*tinf*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=par(1,1)*rate*(1-exp(-par(1,0)*tinf))*(-T+tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret-=par(1,1)*rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
 }
}else{
  ret-=par(1,1)*Dose*T*exp(-T*par(1,0));
}
 return ret;
}//dBETA
if(ncmt==3&&ka<=0&&diff1==4&&diff2==4){//dBETA.dBETA
if(rate>0){
 if(T<=tinf){
  ret-=par(1,1)*pow(T,2)*rate*exp(-T*par(1,0))/par(1,0);
  ret-=2*par(1,1)*T*rate*exp(-T*par(1,0))/pow(par(1,0),2);
  ret+=2*par(1,1)*rate*(1-exp(-T*par(1,0)))/pow(par(1,0),3);
 }else{
  ret-=par(1,1)*rate*pow(tinf,2)*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=2*par(1,1)*rate*tinf*(-T+tinf)*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret+=par(1,1)*rate*(1-exp(-par(1,0)*tinf))*pow((-T+tinf),2)*exp(-par(1,0)*(T-tinf))/par(1,0);
  ret-=2*par(1,1)*rate*tinf*exp(-par(1,0)*tinf)*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
  ret-=2*par(1,1)*rate*(1-exp(-par(1,0)*tinf))*(-T+tinf)*exp(-par(1,0)*(T-tinf))/pow(par(1,0),2);
  ret+=2*par(1,1)*rate*(1-exp(-par(1,0)*tinf))*exp(-par(1,0)*(T-tinf))/pow(par(1,0),3);
 }
}else{
  ret+=par(1,1)*Dose*pow(T,2)*exp(-T*par(1,0));
}
 return ret;
}//dBETA.dBETA
if(ncmt==3&&ka<=0&&diff1==4&&diff2==5){//dBETA.dC
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dBETA.dC
if(ncmt==3&&ka<=0&&diff1==4&&diff2==6){//dBETA.dGAMMA
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dBETA.dGAMMA
if(ncmt==3&&ka<=0&&diff1==5&&diff2==0){//dC
if(rate>0){
 if(T<=tinf){
  ret+=rate*(1-exp(-T*par(2,0)))/par(2,0);
 }else{
  ret+=rate*(1-exp(-par(2,0)*tinf))*exp(-par(2,0)*(T-tinf))/par(2,0);
 }
}else{
  ret+=Dose*exp(-T*par(2,0));
}
 return ret;
}//dC
if(ncmt==3&&ka<=0&&diff1==5&&diff2==5){//dC.dC
if(rate>0){
 if(T<=tinf){
  ret+=0;
 }else{
  ret+=0;
 }
}else{
  ret+=0;
}
 return ret;
}//dC.dC
if(ncmt==3&&ka<=0&&diff1==5&&diff2==6){//dC.dGAMMA
if(rate>0){
 if(T<=tinf){
  ret+=T*rate*exp(-T*par(2,0))/par(2,0);
  ret-=rate*(1-exp(-T*par(2,0)))/pow(par(2,0),2);
 }else{
  ret+=rate*tinf*exp(-par(2,0)*tinf)*exp(-par(2,0)*(T-tinf))/par(2,0);
  ret+=rate*(1-exp(-par(2,0)*tinf))*(-T+tinf)*exp(-par(2,0)*(T-tinf))/par(2,0);
  ret-=rate*(1-exp(-par(2,0)*tinf))*exp(-par(2,0)*(T-tinf))/pow(par(2,0),2);
 }
}else{
  ret-=Dose*T*exp(-T*par(2,0));
}
 return ret;
}//dC.dGAMMA
if(ncmt==3&&ka<=0&&diff1==6&&diff2==0){//dGAMMA
if(rate>0){
 if(T<=tinf){
  ret+=T*rate*par(2,1)*exp(-T*par(2,0))/par(2,0);
  ret-=rate*par(2,1)*(1-exp(-T*par(2,0)))/pow(par(2,0),2);
 }else{
  ret+=rate*par(2,1)*tinf*exp(-par(2,0)*tinf)*exp(-par(2,0)*(T-tinf))/par(2,0);
  ret+=rate*par(2,1)*(1-exp(-par(2,0)*tinf))*(-T+tinf)*exp(-par(2,0)*(T-tinf))/par(2,0);
  ret-=rate*par(2,1)*(1-exp(-par(2,0)*tinf))*exp(-par(2,0)*(T-tinf))/pow(par(2,0),2);
 }
}else{
  ret-=Dose*T*par(2,1)*exp(-T*par(2,0));
}
 return ret;
}//dGAMMA
if(ncmt==3&&ka<=0&&diff1==6&&diff2==6){//dGAMMA.dGAMMA
if(rate>0){
 if(T<=tinf){
  ret-=pow(T,2)*rate*par(2,1)*exp(-T*par(2,0))/par(2,0);
  ret-=2*T*rate*par(2,1)*exp(-T*par(2,0))/pow(par(2,0),2);
  ret+=2*rate*par(2,1)*(1-exp(-T*par(2,0)))/pow(par(2,0),3);
 }else{
  ret-=rate*par(2,1)*pow(tinf,2)*exp(-par(2,0)*tinf)*exp(-par(2,0)*(T-tinf))/par(2,0);
  ret+=2*rate*par(2,1)*tinf*(-T+tinf)*exp(-par(2,0)*tinf)*exp(-par(2,0)*(T-tinf))/par(2,0);
  ret+=rate*par(2,1)*(1-exp(-par(2,0)*tinf))*pow((-T+tinf),2)*exp(-par(2,0)*(T-tinf))/par(2,0);
  ret-=2*rate*par(2,1)*tinf*exp(-par(2,0)*tinf)*exp(-par(2,0)*(T-tinf))/pow(par(2,0),2);
  ret-=2*rate*par(2,1)*(1-exp(-par(2,0)*tinf))*(-T+tinf)*exp(-par(2,0)*(T-tinf))/pow(par(2,0),2);
  ret+=2*rate*par(2,1)*(1-exp(-par(2,0)*tinf))*exp(-par(2,0)*(T-tinf))/pow(par(2,0),3);
 }
}else{
  ret+=Dose*pow(T,2)*par(2,1)*exp(-T*par(2,0));
}
 return ret;
}//dGAMMA.dGAMMA
 stop("Linear derivatives not calculated; Somethings wrong.");
 return ret;
}
