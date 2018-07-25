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


float DL_determinant(float **matrix, int dimension);
float DL_getAt(float **m, int i, int j);
void  DL_putAt(float **m, int i, int j, float value);
float **DL_randomMatrix(int dimension);
float **DL_copyMatrix(float **matrix, int dimension);
void DL_deleteMatrix(float **matrix, int dimension);
void DL_swapRows(float **m, int a, int b);
