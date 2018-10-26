#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef POLYNOMIAL_H
  #include "Polynomial/polynomial.h"
#endif
#ifndef DOOLITTLEDETERMINANT_INCLUDED
  #include "DoolittleAlgorithm/DoolittleAlgorithm.h"
#endif

double minimum(double, double);
double maximum(double, double);
double absolute(double);
int    minimum_int(int, int);
int    maximum_int(int, int);
int    isPowerOfTwo (unsigned int);

// 1D array analysis
double min1(     double *, int); // Minimum of array
double max1(     double *, int); // Maximum of array
double mean1(    double *, int); // Mean of array
double variance1(double *, int); // Variance of array

// 2D array analysis
void gradarray2D(double **, char, int, double, int, int, double *);

void gauss_jordan(float **, int, int );
