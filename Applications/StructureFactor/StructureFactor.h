#ifndef STRUCTURE_FACTOR_H
  #define STRUCTURE_FACTOR_H
  #include <stdio.h>
  #include <stdlib.h>
  #include <complex.h>
  #include <math.h>
  #include "../../Mathematics/Fourier/Fourier.h"
  #include "../../Mathematics/Mathematics.h"
  int calculateStructureFactor2D(int, int, double, double **, complex double **, int, complex double *, double *, double *);
  int calculateStructureFactor2Drect(int, int, double, double, double **, complex double **, int, complex double *, double *, double *);
  int calculateStructureFactor3D(int, int, int, double, double ***, complex double ***, int, complex double *, double *, double *);
#endif

