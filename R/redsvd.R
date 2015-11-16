redsvd <- function(A,num){
  if (is(A,"CsparseMatrix")) {
    if (is(A, "symmetricMatrix")) {
      A <- as(A, "dgCMatrix")
    }
    redSVDwrap(A, num)
  }
}

redpca <- function(A,num){
  if (is(A,"CsparseMatrix")) {
    if (is(A, "symmetricMatrix")) {
      A <- as(A, "dgCMatrix")
    }
    redPCAwrap(A, num)
  }
}

redSymEigen <- function(A,num){
  if (is(A,"CsparseMatrix")) {
    if (is(A, "symmetricMatrix")) {
      A <- as(A, "dgCMatrix")
    }
    redSymwrap(A, num)
  }
}
