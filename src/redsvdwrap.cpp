#include <Rcpp.h>
#include <RcppEigen.h>
#include "redsvd-h/include/RedSVD/RedSVD.hpp"  

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
Rcpp::List redSVDwrap(const Eigen::MappedSparseMatrix<double> A, const int num){
   RedSVD::RedSVD<Eigen::MappedSparseMatrix<double> > svA(A, num);
  
   return Rcpp::List::create(
     Rcpp::Named("V") = Rcpp::wrap(svA.matrixV()),
     Rcpp::Named("U") = Rcpp::wrap(svA.matrixU()),
     Rcpp::Named("D") = Rcpp::wrap(svA.singularValues()));
}

// [[Rcpp::export]]
Rcpp::List redSymwrap(const Eigen::MappedSparseMatrix<double> A, const int num){
  RedSVD::RedSymEigen<Eigen::MappedSparseMatrix<double> > p(A, num);
  
  return Rcpp::List::create(
    Rcpp::Named("eigenValues") = Rcpp::wrap(p.eigenvalues()),
    Rcpp::Named("eigenVectors")= Rcpp::wrap(p.eigenvectors()));
}

// [[Rcpp::export]]
Rcpp::List redPCAwrap(const Eigen::MappedSparseMatrix<double> A, const int num){
   RedSVD::RedPCA<Eigen::MappedSparseMatrix<double> > p(A, num);
  
   return Rcpp::List::create(
     Rcpp::Named("principalComponents") = Rcpp::wrap(p.components()),
     Rcpp::Named("scores") =  Rcpp::wrap(p.scores()));
}
