#include <RcppEigen.h>
#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
#include "redsvd-h/include/RedSVD/RedSVD-h"  
using namespace Rcpp;

// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::MatrixXf;
using Eigen::MappedSparseMatrix;
using Eigen::SparseMatrix;

// [[Rcpp::export]]
List redSVDwrap(const MappedSparseMatrix<double> AA, const int num){
   REDSVD::RedSVD svA(A, num);
  
   return List::create(
     Named("V") = Rcpp::wrap(svA.matrixV()),
     Named("U")=  Rcpp::wrap(svA.matrixU()),
     Named("D")=  Rcpp::wrap(svA.singularValues()));
}

// [[Rcpp::export]]
List redSymwrap(const MappedSparseMatrix<double> AA, const int num){
  REDSVD::RedSymEigen p(A,num);
  
  return List::create(
    Named("eigenValues") = Rcpp::wrap(p.eigenValues()),
    Named("eigenVectors")= Rcpp::wrap(p.eigenVectors()));
}

SEXP redPCAwrap(SEXP AA,SEXP nn){
  //  int num=INTEGER(nn)[0];
  Rcpp::NumericVector dd(nn);
  int num=(int)dd[0];
   const MappedSparseMatrix<double> A(as<MappedSparseMatrix<double> >(AA));
   REDSVD::RedPCA p(A, num);
   return List::create(Named("principalComponents") = Rcpp::wrap(p.principalComponents()),
		       Named("scores") =  Rcpp::wrap(p.scores()));
}
