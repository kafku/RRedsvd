redsvd <- function(A,num){
  if (is(A,"CsparseMatrix")) {
    redSVDwrap(A, num)
  }
}

redpca <- function(A,num){
  if (is(A,"CsparseMatrix")) {
    redPCAwrap(A, num)
  }
}

redSymEigen <- function(A,num){
  if (is(A,"CsparseMatrix")) {
    redSymwrap(A, num)
  }
}
