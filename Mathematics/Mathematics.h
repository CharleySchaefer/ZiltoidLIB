#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef POLYNOMIAL_H
  #include "Polynomial/polynomial.h"
#endif
#ifndef DOOLITTLEALGORITHM_H
  #include "DoolittleAlgorithm/DoolittleAlgorithm.h"
#endif
#ifndef FOURIER_H
  #include "Fourier/Fourier.h"
#endif
#ifndef INTERPOLATION_H
  #include "Interpolation/Interpolation.h"
#endif
#ifndef RANDOMNUMBERS_H
  #include "RandomNumbers/RandomNumbers.h"
#endif

// Scalar functions
double absolute(double);
int    isPowerOfTwo (unsigned int);

double minimum(double, double);
double maximum(double, double);
int    minimum_int(int, int);
int    maximum_int(int, int);

// 1D array analysis
double min1(     double *, int); // Minimum of array
double max1(     double *, int); // Maximum of array
double mean1(    double *, int); // Mean of array
double variance1(double *, int); // Variance of array

// 2D array analysis
void gradarray2D(double **, char, int, double, int, int, double *);


// Linear algebra
int gram_schmidt(double *, int, int, double *, double *, double *);
int francisQRstep(double**, int, int, int, double, double*,double*, double*, double*, double *);
void gauss_jordan(float **, int, int );
