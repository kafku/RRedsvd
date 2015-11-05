#include <RcppEigen.h>
#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
#include "redsvd-h/include/RedSVD/RedSVD-h"  
using namespace Rcpp;

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
List redSVDwrap(const Eigen::MappedSparseMatrix<double> AA, const int num){
   RedSVD::RedSVD<Eigen::SparseMatrix<double> > svA(A, num);
  
   return List::create(
     Named("V") = Rcpp::wrap(svA.matrixV()),
     Named("U")=  Rcpp::wrap(svA.matrixU()),
     Named("D")=  Rcpp::wrap(svA.singularValues()));
}

// [[Rcpp::export]]
List redSymwrap(const Eigen::MappedSparseMatrix<double> AA, const int num){
  RedSVD::RedSymEigen<Eigen::SparseMatrix<double> > p(A, num);
  
  return List::create(
    Named("eigenValues") = Rcpp::wrap(p.eigenValues()),
    Named("eigenVectors")= Rcpp::wrap(p.eigenVectors()));
}

// [[Rcpp::export]]
List redPCAwrap(const Eigen::MappedSparseMatrix<double> AA, const int num){
   RedSVD::RedPCA<Eigen::SparseMatrix<double> > p(A, num);
  
   return List::create(
     Named("principalComponents") = Rcpp::wrap(p.principalComponents()),
     Named("scores") =  Rcpp::wrap(p.scores()));
}
