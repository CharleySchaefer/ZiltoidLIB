/*
  
  // Eigenvalues of a real symmetric matrix using LAPACK

  USAGE:
    Install LAPACK: apt-get install liblapack-dev
    Compile script: gcc -o executable.o eigenvalues_real_symmetric_matrix.c -llapack
  
  ALGORITHM:
    0. Define real symmetric matrix A
    1. Decompose A = Q * T * Q', with Q an orthogonal matrix (Q=Q'), with Q' the transposed Q,
       and T a tridiagonal matrix. Our script does this using the DSTRD routine of LAPACK, see
       https://physics.oregonstate.edu/~landaur/nacphy/lapack/routines/ssytrd.html
    2. Decompose T = Q * D * Q', with Q again an orthogonal matrix. D is now a diagonal matrix,
       which contains the eigenvalues. Our script does this using the DSTEQR routine of 
       LAPACK, see https://physics.oregonstate.edu/~landaur/nacphy/lapack/routines/dsteqr.html

    NOTE: The DSTEQR routine can in principle calculate the eigenvectors, if the matrix
          Q under step 1. is passed to step 2 as input to DSTEQR.
          
    Alternatives to DSTEQR (see https://physics.oregonstate.edu/~landaur/nacphy/lapack/eigen.html) are: 
    dsteqr: Computes all eigenvalues and eigenvectors of a real symmetric tridiagonal matrix, using the implicit QL or QR algorithm
    dsterf: Computes all eigenvalues of a real symmetric tridiagonal matrix, using a root-free variant of the QL or QR algorithm
    dstebz: Computes selected eigenvalues of a real symmetric tridiagonal matrix by bisection
    dstein: Computes selected eigenvectors of a real symmetric tridiagonal matrix by inverse iteration
    dpteqr: Computes all eigenvalues and eigenvectors of a real symmetric positive definite tridiagonal matrix, by computing the SVD of its bidiagonal Cholesky factor

*/

int eigenvalues_real_symmetric_matrix(double **matrix, int n, double *mat1D, double *buff1, double *buff2, double *buff3, double *eigenvalues)
{
  int i,j;

  // Copy matrix
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      mat1D[i*n + j] = matrix[i][j];


  // STEP 1: DECOMPOSE MATRIX TO OBTAIN TRIDIAGONAL MATRIX USING LAPACK'S DSYTRD
  char      uplo='U';    // U: Upper triangle of A is stored;
  int       lwork=2*n-1; // The dimension of the array WORK.  LWORK >= 1. For optimum 
                         // performance LWORK >= N*NB, where NB is the optimal blocksize.
  double    *work=buff1; //On exit, if INFO = 0, WORK(1) returns the optimal LWORK.
  const int LDA=n;       //The leading dimension of the array A. LDA >= max(1,N).
  double    *E=buff2;      // The off-diagonal elements of the tridiagonal matrix T: E(i) =
	                 // A(i,i+1) if UPLO = 'U', E(i) = A(i+1,i) if UPLO = 'L'.
  double    *tau=buff3;    // The scalar factors of the elementary reflectors (see Further
	                 // https://physics.oregonstate.edu/~landaur/nacphy/lapack/routines/ssytrd.html).
  double    *D=eigenvalues;        // The diagonal elements of the tridiagonal matrix T: D(i) = A(i,i).
  int       info;        // = 0: successful exit
	                 // < 0: if INFO = -i, the i-th argument had an illegal value

  dsytrd_(&uplo, &n, mat1D, &LDA, D, E, tau, work,&lwork, &info); // For floats, use ssytrd
  if (info!=0)   // check for errors
  {
    printf("Error: dsytrd_ returned error code %d.\n", info);
    return -1;
  }

  // STEP 2: DIAGONALISE TRIDIAGONAL MATRIX USING LAPACK'S DSTEQR ROUTINE
  char      compz='N'; // N:  Compute eigenvalues only
  int       ldz=1;
  double    *z;
  dsteqr_(&compz, &n, D, E, z, &ldz, work, &info);

  // check for errors
  if (info!=0)
  {
    printf("Error: dsteqr_ returned error code %d.\n", info);
    return -1;
  }
  return(1);
}

