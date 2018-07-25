#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef POLYNOMIAL_H
  #include "Polynomial/polynomial.h"
#endif
#ifndef DOOLITTLEDETERMINANT_INCLUDED
  #include "DoolittleDeterminant/DoolittleDeterminant.h"
#endif
double minimum(double, double);
double maximum(double, double);
double absolute(double);
int    minimum_int(int, int);
int    maximum_int(int, int);
int    isPowerOfTwo (unsigned int);
void gradarray2D(double **, char, int, double, int, int, double *);
