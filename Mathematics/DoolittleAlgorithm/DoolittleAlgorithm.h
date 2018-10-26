/*
  
  Developed by https://github.com/lawliet89/DoolittleDeterminant/

  Modified from 25 July 2018 as part of ZiltoidLIB
*/

/**
    Note: The arrays are implemented as Ragged Arrays
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DOOLITTLEALGORITHM_H 1


int   DL_LUdecomposition(float **, float **, int);
int   DL_eigenvalues(float **, float **, float *, int);
float DL_determinant(float **,float **, int);
void  DL_swapRows(float **, int, int);

// For demo purposes
float **DL_randomMatrix(int dimension);
void DL_printMatrix(float **, int );
