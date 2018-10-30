

#include <stdio.h>
#include <stdlib.h>

#include "eigenvalues_real_symmetric_matrix.h"


int main(int argc, char** argv)
{
  int       i,j;
  const int n=4;

  double buff1[2*n-1];
  double buff2[n-1];
  double buff3[n-1];
  double eigenvalues[n];

  double    **matrix;
  double    *mat;
  double *mat1D=(double*)malloc(n*n*sizeof(double));

  matrix=(double**)malloc(n*sizeof(double*));
  for(i=0;i<n; i++)
    matrix[i]=(double*)malloc(n*sizeof(double));
  matrix[0][0]= 1; matrix[0][1]= 1; matrix[0][2]= 1; matrix[0][3]= 1;
  matrix[1][0]= 1; matrix[1][1]= 1; matrix[1][2]= 1; matrix[1][3]= 1;
  matrix[2][0]= 1; matrix[2][1]= 1; matrix[2][2]= 3; matrix[2][3]= 1;
  matrix[3][0]= 1; matrix[3][1]= 1; matrix[3][2]= 1; matrix[3][3]= 4;

  if(eigenvalues_real_symmetric_matrix(matrix, n, mat1D, buff1, buff2, buff3, eigenvalues)!=1)
    { printf("Error: eigenvalues_real_symmetric_matrix() failed.\n"); return(-1);}

  for(i=0; i<n; i++)
    printf("%e\n", eigenvalues[i]);

  return 0;
}
