#include <RcppEigen.h>
#include "redsvd-h/include/RedSVD/RedSVD.hpp"  
using namespace Rcpp;

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
List redSVDwrap(const Eigen::MappedSparseMatrix<double> A, const int num){
   RedSVD::RedSVD<Eigen::MappedSparseMatrix<double> > svA(A, num);
  
   return List::create(
     Named("V") = Rcpp::wrap(svA.matrixV()),
     Named("U")=  Rcpp::wrap(svA.matrixU()),
     Named("D")=  Rcpp::wrap(svA.singularValues()));
}

// [[Rcpp::export]]
List redSymwrap(const Eigen::MappedSparseMatrix<double> A, const int num){
  RedSVD::RedSymEigen<Eigen::MappedSparseMatrix<double> > p(A, num);
  
  return List::create(
    Named("eigenValues") = Rcpp::wrap(p.eigenvalues()),
    Named("eigenVectors")= Rcpp::wrap(p.eigenvectors()));
}

// [[Rcpp::export]]
List redPCAwrap(const Eigen::MappedSparseMatrix<double> A, const int num){
   RedSVD::RedPCA<Eigen::MappedSparseMatrix<double> > p(A, num);
  
   return List::create(
     Named("principalComponents") = Rcpp::wrap(p.components()),
     Named("scores") =  Rcpp::wrap(p.scores()));
}
