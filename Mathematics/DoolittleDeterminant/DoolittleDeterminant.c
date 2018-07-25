/*
  
  Developed by https://github.com/lawliet89/DoolittleDeterminant/

  Modified from 25 July 2018 as part of ZiltoidLIB
*/

/**
    Note: The arrays are implemented as Ragged Arrays
*/
#include "DoolittleDeterminant.h"


float DL_determinant(float **matrix, int dimension){
    int i, j, k, p, swapCount=0, determinantFactor=1;
    float a, ajj, result, value;
	int swapee = 0;		// used to indicate row to swap
    float **m = NULL;

    // Let us copy the matrix first
    m = DL_copyMatrix(matrix, dimension);

    // First step: perform LU Decomposition using Doolittle's Method
    // This algorithm will return, in the same matrix, a lower unit triangular matrix
    // (i.e. diagonals one)
    // and an upper trangular matrix
    // https://vismor.com/documents/network_analysis/matrix_algorithms/S4.SS2.php

    for (i = 0; i < dimension; i++){
        for (j = 0; j < i; j++){
            ajj = DL_getAt(m,j,j);

            // a number we are dividing by is zero.
            // we thus have to do a partial pivot
            if (ajj == 0){
                if (swapCount == dimension){
                    // Seems like we have exhaused all swaps
                    return NAN;
                }

                // Let's find a swap row to swap
                result = -INFINITY;
                for (k = 0; k < dimension; k++){
                    value = DL_getAt(m, k, j);
                    if (value > result){
                        result = value;
                        swapee = k;
                    }
                }
				// Swap rows
				DL_swapRows(m, j, swapee);              
                swapCount++;
                determinantFactor *= -1;

                ajj = DL_getAt(m,j,j);
            }

            a = DL_getAt(m, i, j);
            for (p = 0; p < j; p++){
                a -= DL_getAt(m, i, p) * DL_getAt(m, p, j);
            }
            DL_putAt(m, i, j, a/ajj);
        }
        for (j = i; j < dimension; j++){
            a = DL_getAt(m, i, j);
            for (p = 0; p < i; p++){
                a -= DL_getAt(m, i, p) * DL_getAt(m, p, j);
            }
            DL_putAt(m, i, j, a);
        }
    }

    // Second step is to find the determinant.
    // Because the lower triangle is a unit triangular matrix
    // the determinant is simply a product of all the upper triangle diagonal
    // which in this case is exactly the diagonal of m
    result = determinantFactor;
    for (i = 0; i < dimension; i++)
        result *= DL_getAt(m, i, i);

    DL_deleteMatrix(m, dimension);
	
    return result;
}

// Based on i and j, and a float pointer, get the value at row i column j
float DL_getAt(float **m, int i, int j){
    return *(*(m + i) + j);
}

// Based on i and j, and a float pointer, put the value at row i column j
void DL_putAt(float **m, int i, int j, float value){
    *( (*(m+i)) + j ) = value;
} 

// Generate a n by n matrix consisting of numbers between -1 and 1.
// Outputs in a Matlab format, good for checking in Matlab
float **DL_randomMatrix(int dimension){
    int i, j;
    float **matrix;
    float *row;
    float no;

    // let's first initialise the ragged array
    // initialise Ragged Array
    matrix = (float **) malloc(dimension*sizeof(float *));

    // Seed random number generator
    srand(time(NULL));

    printf("[");
    for (i = 0; i < dimension; i++){
        // Initialise this row
        row = (float *) malloc(dimension*sizeof(float));
        *(matrix + i) = row;

        // random no between -1 and 1
        for (j = 0; j < dimension; j++){
            no = ((float) (rand()%20))/10-1;
             *(row + j) = no;
            printf("%f ", no);
        }
        printf(";\n");
    }
    printf("]\n");

    return matrix;
}

// copy matrix (ragged array)
float **DL_copyMatrix(float **matrix, int dimension){
    int i;
    float **copy = (float **) malloc(dimension*sizeof(float *));

    for (i = 0; i < dimension; i++){
        // allocate memory for row
        *(copy + i) = (float *) malloc(dimension*sizeof(float));
        // copy row
        memcpy( *(copy +i), *(matrix + i), sizeof(float)*dimension );
    }

    return copy;
}

// delete matrix (ragged array)
void DL_deleteMatrix(float **matrix, int dimension){
    int i;
    for (i = 0; i <dimension; i++){
        free( *(matrix+i));
    }
	free(matrix);
}

// swap rows -- ragged array. swap rows a and b
void DL_swapRows(float **matrix, int a, int b){
	 float *swapRowTemp = *( matrix + a );
	 *( matrix + a ) = *( matrix + b );
	 *( matrix + b ) = swapRowTemp;
}
