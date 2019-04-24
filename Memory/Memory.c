#include "Memory.h"

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
