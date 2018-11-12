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



#endif
