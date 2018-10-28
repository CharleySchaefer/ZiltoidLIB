
#include <stdlib.h>
#include <math.h>

#define RANDOMNUMBERS_H   1

int    randint(int);
int    randint2(int, int);
double randf(double);
double randf2(double, double);
double randn(void);
double rand_dev_double(double, double, double, double);
int    getRandConfig(int *, int, int *, int);
void   getNoiseField2Ddouble(int, double, double **);
void   getNoiseField2Dfloat(int, double, float **);

	