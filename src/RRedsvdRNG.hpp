#ifndef __REDSVD_RNG_H__
#define __REDSVD_RNG_H__

#include <Rcpp.h>
#include <algorithm>

struct RcppGaussian{
  template<typename MatrixType>
  static void set(MatrixType& mat)
  {
    typedef typename MatrixType::Index Index;
    
    Index num_element = mat.rows() * mat.cols();
    const Rcpp::NumericVector rand_vec = Rcpp::rnorm(num_element);
    
    std::copy(rand_vec.begin(), rand_vec.end(), mat.data());
  }
};

#endif