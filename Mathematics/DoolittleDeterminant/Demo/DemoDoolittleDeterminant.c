/*
  
  Developed by https://github.com/lawliet89/DoolittleDeterminant/

  Modified from 25 July 2018 as part of ZiltoidLIB
*/

/**
    Note: The arrays are implemented as Ragged Arrays
*/


#include "../DoolittleDeterminant.h"

int main(){
    int MatrixSize=3; // Size of square matrix is MatrixSize x MatrixSize 
    float **matrix;     // matrix is a pointer to pointer
    float det;
    
   // Generate, and initialise random matrix
    matrix = DL_randomMatrix(MatrixSize);
    det = DL_determinant(matrix, MatrixSize);
    
    printf("%f \n", det);   
    return 0;
}
