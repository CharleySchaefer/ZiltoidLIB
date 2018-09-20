#include "Interpolation.h"

int find_boundary_indices(double *xarr, double *yarr, int N, double xint, int *indL, int *indU)
{
  int    nL=0, nU=N-1, n;
  double x, xL, xU; // upper and lower x values
  double f;
  if (xint<(xL=xarr[nL]) | xint>(xU=xarr[nU])) // extrapolation needed
    return(2);

  if(xint==xL)
  { *indL=0; *indU=0; }
  else if (xint==xU)
  { *indL=N-1; *indU=N-1; }
  else
  {
    // find nL and nU such that nU=nL+1 and xarr[nL]<=xint<=xarr[nU]
    while(nU-nL>1) 
    {
      n=(int)(nL+0.5*(float)(nU-nL));
      x=xarr[n];
      if((x<xL)|(x>xU)) // xarr not monotonically increasing!
        {printf("ERROR: entries of xarr should be monotonically increasing!\n"); return(0);}
      if (x==xint) // exact value found -> no interpolation needed -> done.
      {
        *indL=n;*indU=n;
        return(1);
      }
      else if (x>xint) // update upper value
      {
        nU=n;
        xU=x;
      }
      else if (x<xint) // update lower value
      {
        nL=n;
        xL=x;
      }
    }
    *indL=nL;
    *indU=nU;
  }
  return(1);
}

int interp1(double *xarr, double *yarr, int N, double xint, double *yint)
{
  int    nL=0, nU=N-1, n;
  double x, xL, xU; // upper and lower x values
  double f;
  if (xint<(xL=xarr[nL]) | xint>(xU=xarr[nU])) // extrapolation needed
    return(2);

  if(xint==xL)
    *yint=yarr[0];
  else if (xint==xU)
    *yint=yarr[N-1];
  else
  {
    if(!find_boundary_indices(xarr, yarr, N, xint, &nL, &nU))
    {
      printf("ERROR: find_boundary_indices() failed!\n"); 
      return(0);
    }

    // interpolate
    f=(xint-xarr[nL])/(xarr[nU]-xarr[nL]);
    *yint = (1-f)*yarr[nL] + f*yarr[nU];
  }
  return(1);
}
