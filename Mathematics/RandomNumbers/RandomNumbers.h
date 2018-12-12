#ifndef RANDOMNUMBERS_H
  #define RANDOMNUMBERS_H   1
  #include <stdlib.h>
  #include <math.h>

  int    irand(  int);              // random int scalar
  void   i1rand( int *, int, int);  // random int array

  void   randperm(int *, int);      // random permutation of input array

  int    randint(int); // identical to irand
  int    randint2(int, int);
  double randf(double);
  double randf2(double, double);
  double randn(void);
  double rand_dev_double(double, double, double, double);
  int    getRandConfig(int *, int, int *, int);
  void   getNoiseField2Ddouble(int, double, double **);
  void   getNoiseField2Dfloat(int, double, float **);
#endif

	
