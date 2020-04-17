#include <Rcpp.h>
#include <checkmate.h>

using namespace Rcpp;

extern "C" R_xlen_t find_missing_string(SEXP);
static R_xlen_t check_strict_names(SEXP x) {
  const R_xlen_t nx = Rf_xlength(x);
  const char *str;
  for (R_xlen_t i = 0; i < nx; i++) {
    str = CHAR(STRING_ELT(x, i));
    while (*str == '.')
      str++;
    if (!isalpha(*str))
      return i + 1;
    for (; *str != '\0'; str++) {
      if (!isalnum(*str) && *str != '.' && *str != '_')
	return i + 1;
    }
  }
  return 0;
}

// Modified by Matt
SEXP qstrictS(SEXP nn, const char *what){
  BEGIN_RCPP
  R_xlen_t pos = find_missing_string(nn);
  if (pos > 0) {
    stop("Must have %s, but is NA at position %i", what, pos);
  }
  if (Rf_isNull(nn)) {
    stop("Must have %s", what);
  }
  pos = Rf_any_duplicated(nn, FALSE);
  if (pos > 0){
    stop("Must have unique %s, but element %i is duplicated", what, pos);
  }
  pos = check_strict_names(nn);
  if (pos > 0){
    stop("Must have %s according to R's variable naming conventions, but element %i does not comply", what, pos);
  }
  return R_NilValue;
  END_RCPP
}

SEXP qstrictSn(SEXP x_, const char *what) {
  BEGIN_RCPP
  RObject x  = as<RObject>(x_);
  return qstrictS(as<SEXP>(x.attr("names")), what);
  END_RCPP
}

SEXP qassertS(SEXP in, const char *test, const char *what){
  BEGIN_RCPP
  if (!qtest(as<SEXP>(in), test)) {
    char ch1 = tolower(test[0]);
    std::string what0 = std::string(what);
    std::string err = "'" + what0 + "' must be class '";
    if (ch1 == 'r') {
      err += "double";
    } else if (ch1 == 'b') {
      err += "boolean"; 
    } else if (ch1 == 'x') {
      err += "integer";
    } else if (ch1 == 'm') {
      err += "matrix";
    }
    err += "' ";
    int i = 1;
    int including = 0;
    int startedLen = 0;
    while (test[i] != 0) {
      if (test[i] >= '1' && test[i] <= '9') {
	if (startedLen){
	} else {
	  err.append("of length ");
	  startedLen=1;
	}
	err.append(1, test[i]);
      } else {
	if (test[i] == '[' || test[i] == '(') {
	  including = 1;
	  err.append(" with range ");
	  err.append(1,test[i]);
	} else if (including) {
	  err.append(1, test[i]);
	  if (test[i] == ',' && test[i+1] == ')') {
	    err += "Inf";
	  }
	}
      }
      i++;
    }
    // err.append("test: '");
    // err.append(test);
    // err.append("'");
    Rcpp::stop(err);
  }
  return R_NilValue;
  END_RCPP
}

SEXP qassertS(RObject in, const char *test, const char *what){
  return qassertS(as<SEXP>(in), test, what);
}
