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

// [[Rcpp::export]]
List redPCAwrap(const MappedSparseMatrix<double> AA, const int num){
   REDSVD::RedPCA p(A, num);
  
   return List::create(
     Named("principalComponents") = Rcpp::wrap(p.principalComponents()),
     Named("scores") =  Rcpp::wrap(p.scores()));
}
