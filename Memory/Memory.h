#ifndef ZILTOID_MEMORY_H
#define ZILTOID_MEMORY_H
#include <stdlib.h> // alloc and free

// free 1D array
void i1free(int      *);
void f1free(float    *);
void d1free(double   *);
void c1free(char     *);

// free 2D array
void i2free(int     **, int);
void f2free(float   **, int);
void d2free(double  **, int);
void c2free(char    **, int);

// free 3D array
void i3free(int    ***, int, int);
void f3free(float  ***, int, int);
void d3free(double ***, int, int);
void c3free(char   ***, int, int); 

#endif // ZILTOID_MEMORY_H
