#ifndef ZILTOID_MATHEMATICS_H
#define ZILTOID_MATHEMATICS_H 1

  #include <math.h>
  #include <stdlib.h>
  #include <stdio.h>

  #include "Polynomial/Polynomial.h"
  #include "Fourier/Fourier.h"
  #include "RandomNumbers/RandomNumbers.h"
  #include "LinearAlgebra/LinearAlgebra.h"

  // Scalar functions
  double absolute(double);
  int    isPowerOfTwo (unsigned int);
  int    bin2dec(int *, int *, int);
  int    dec2bin(int  , int *, int);

  double minimum(double, double);
  double maximum(double, double);
  int    minimum_int(int, int);
  int    maximum_int(int, int);

  // 1D array analysis
  double d1min(     double *, int); // Minimum of array
  double d1max(     double *, int); // Maximum of array
  double d1mean(    double *, int); // Mean of array
  double d1variance(double *, int); // Variance of array

  float  f1min(      float *, int); // Minimum of array
  float  f1max(      float *, int); // Maximum of array
  float  f1mean(     float *, int); // Mean of array
  float  f1variance( float *, int); // Variance of array

  int    i1min(        int *, int); // Minimum of array
  int    i1max(        int *, int); // Maximum of array

  // 2D array analysis
  void gradarray2D(double **, char, int, double, int, int, double *);



#endif
