#ifndef ZILTOID_MEMORY_H
#define ZILTOID_MEMORY_H
#include <stdlib.h> // alloc and free

// 1D arrays size N
int    *i1malloc(int);                  // int N
float  *f1malloc(int);
double *d1malloc(int);
char   *c1malloc(int);

int    *i1calloc(int);                    
float  *f1calloc(int);
double *d1calloc(int);
char   *c1calloc(int);

void    i1free(int      *);
void    f1free(float    *);
void    d1free(double   *);
void    c1free(char     *);

// 2D arrays size MxN
int    **i2malloc(int, int);            // int M, int N
float  **f2malloc(int, int);
double **d2malloc(int, int);
char   **c2malloc(int, int);

int    **i2calloc(int, int);
float  **f2calloc(int, int);
double **d2calloc(int, int);
char   **c2calloc(int, int);

void     i2free(int     **, int);       // int M
void     f2free(float   **, int);
void     d2free(double  **, int);
void     c2free(char    **, int);

// 3D arrays size LxMxN
int    ***i3malloc(int, int, int);      // int L, int M, int N
float  ***f3malloc(int, int, int);
double ***d3malloc(int, int, int);
char   ***c3malloc(int, int, int);

int    ***i3calloc(int, int, int);
float  ***f3calloc(int, int, int);
double ***d3calloc(int, int, int);
char   ***c3calloc(int, int, int);

void      i3free(int    ***, int, int); // int L, int M
void      f3free(float  ***, int, int);
void      d3free(double ***, int, int);
void      c3free(char   ***, int, int);

#endif // ZILTOID_MEMORY_H
