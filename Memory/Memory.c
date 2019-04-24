#include "Memory.h"

//===============================================
// 1D arrays
int    *i1malloc(int N)
{
  int *arr=(int*)malloc(N*sizeof(int));
  return arr;
}
float  *f1malloc(int N)
{
  float *arr=(float*)malloc(N*sizeof(float));
  return arr;
}
double *d1malloc(int N)
{
  double *arr=(double*)malloc(N*sizeof(double));
  return arr;
}
char   *c1malloc(int N)
{
  char *arr=(char*)malloc(N*sizeof(char));
  return arr;
}

int    *i1calloc(int N)
{
  int *arr=(int*)calloc(N, sizeof(int));
  return arr;
}
float  *f1calloc(int N)
{
  float *arr=(float*)calloc(N, sizeof(float));
  return arr;
}
double *d1calloc(int N)
{
  double *arr=(double*)calloc(N, sizeof(double));
  return arr;
}
char   *c1calloc(int N)
{
  char *arr=(char*)calloc(N, sizeof(char));
  return arr;
}


void i1free(int *arr1)
{
  if(arr1!=NULL)
  {
    free(arr1); arr1=NULL;
  }
}

void f1free(float *arr1)
{
  if(arr1!=NULL)
  {
    free(arr1); arr1=NULL;
  }
}
void d1free(double *arr1)
{
  if(arr1!=NULL)
  {
    free(arr1); arr1=NULL;
  }
}
void c1free(char *arr1)
{
  if(arr1!=NULL)
  {
    free(arr1); arr1=NULL;
  }
}

//===============================================
// 2D arrays
int    **i2malloc(int M, int N)
{
  int i;
  int **arr=(int**)malloc(M*sizeof(int*));
  for(i=0; i<M; i++)
    arr[i]=i1malloc(N);
  return arr;
}

float    **f2malloc(int M, int N)
{
  int i;
  float **arr=(float**)malloc(M*sizeof(float*));
  for(i=0; i<M; i++)
    arr[i]=f1malloc(N);
  return arr;
}

double    **d2malloc(int M, int N)
{
  int i;
  double **arr=(double**)malloc(M*sizeof(double*));
  for(i=0; i<M; i++)
    arr[i]=d1malloc(N);
  return arr;
}

char    **c2malloc(int M, int N)
{
  int i;
  char **arr=(char**)malloc(M*sizeof(char*));
  for(i=0; i<M; i++)
    arr[i]=c1malloc(N);
  return arr;
}

int    **i2calloc(int M, int N)
{
  int i;
  int **arr=(int**)malloc(M*sizeof(int*));
  for(i=0; i<M; i++)
    arr[i]=i1calloc(N);
  return arr;
}

float    **f2calloc(int M, int N)
{
  int i;
  float **arr=(float**)malloc(M*sizeof(float*));
  for(i=0; i<M; i++)
    arr[i]=f1calloc(N);
  return arr;
}

double    **d2calloc(int M, int N)
{
  int i;
  double **arr=(double**)malloc(M*sizeof(double*));
  for(i=0; i<M; i++)
    arr[i]=d1calloc(N);
  return arr;
}

char    **c2calloc(int M, int N)
{
  int i;
  char **arr=(char**)malloc(M*sizeof(char*));
  for(i=0; i<M; i++)
    arr[i]=c1calloc(N);
  return arr;
}


void i2free(int **arr2, int M)
{
  int i;
  if(arr2!=NULL)
  {
    for(i=0; i<M; i++)
    {
      i1free(arr2[i]);
    }
    free(arr2); arr2=NULL;
  }
}

void f2free(float **arr2, int M)
{
  int i;
  if(arr2!=NULL)
  {
    for(i=0; i<M; i++)
    {
      f1free(arr2[i]);
    }
    free(arr2); arr2=NULL;
  }
}

void d2free(double **arr2, int M)
{
  int i;
  if(arr2!=NULL)
  {
    for(i=0; i<M; i++)
    {
      d1free(arr2[i]);
    }
    free(arr2); arr2=NULL;
  }
}

void c2free(char **arr2, int M)
{
  int i;
  if(arr2!=NULL)
  {
    for(i=0; i<M; i++)
    {
      c1free(arr2[i]);
    }
    free(arr2); arr2=NULL;
  }
}


//===============================================
// 2D arrays
int    ***i3malloc(int L, int M, int N)
{
  int i;
  int ***arr=(int***)malloc(M*sizeof(int**));
  for(i=0; i<L; i++)
    arr[i]=i2malloc(M, N);
  return arr;
}

float    ***f3malloc(int L, int M, int N)
{
  int i;
  float ***arr=(float***)malloc(M*sizeof(float**));
  for(i=0; i<L; i++)
    arr[i]=f2malloc(M, N);
  return arr;
}

double    ***d3malloc(int L, int M, int N)
{
  int i;
  double ***arr=(double***)malloc(M*sizeof(double**));
  for(i=0; i<L; i++)
    arr[i]=d2malloc(M, N);
  return arr;
}

char    ***c3malloc(int L, int M, int N)
{
  int i;
  char ***arr=(char***)malloc(M*sizeof(char**));
  for(i=0; i<L; i++)
    arr[i]=c2malloc(M, N);
  return arr;
}

int    ***i3calloc(int L, int M, int N)
{
  int i;
  int ***arr=(int***)malloc(M*sizeof(int**));
  for(i=0; i<L; i++)
    arr[i]=i2calloc(M, N);
  return arr;
}

float    ***f3calloc(int L, int M, int N)
{
  int i;
  float ***arr=(float***)malloc(M*sizeof(float**));
  for(i=0; i<L; i++)
    arr[i]=f2calloc(M, N);
  return arr;
}

double    ***d3calloc(int L, int M, int N)
{
  int i;
  double ***arr=(double***)malloc(M*sizeof(double**));
  for(i=0; i<L; i++)
    arr[i]=d2calloc(M, N);
  return arr;
}

char    ***c3calloc(int L, int M, int N)
{
  int i;
  char ***arr=(char***)malloc(M*sizeof(char**));
  for(i=0; i<L; i++)
    arr[i]=c2calloc(M, N);
  return arr;
}




void i3free(int ***arr3, int L, int M)
{
  int i;
  if(arr3!=NULL)
  {
    for(i=0; i<L; i++)
    {
      i2free(arr3[i], M);
    }
    free(arr3); arr3=NULL;
  }
}

void f3free(float ***arr3, int L, int M)
{
  int i;
  if(arr3!=NULL)
  {
    for(i=0; i<L; i++)
    {
      f2free(arr3[i], M);
    }
    free(arr3); arr3=NULL;
  }
}

void d3free(double ***arr3, int L, int M)
{
  int i;
  if(arr3!=NULL)
  {
    for(i=0; i<L; i++)
    {
      d2free(arr3[i], M);
    }
    free(arr3); arr3=NULL;
  }
}

void c3free(char ***arr3, int L, int M)
{
  int i;
  if(arr3!=NULL)
  {
    for(i=0; i<L; i++)
    {
      c2free(arr3[i], M);
    }
    free(arr3); arr3=NULL;
  }
}
