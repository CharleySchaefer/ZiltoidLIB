

#include "StructureFactor.h"

//----------------------------------------------------------------------------------------------------------------------------------
/*
  Calculate radially averaged structure factor of a 2D order parameter


  INPUT
    > Psi2D is the NX x NY array of which the power spectrum is calculated. Entries: 
       * Either doubles that represent the value of an order parameter
        Each element in this case represents a volume/area with some 
        concentration / order parameter.
      * Or integers of value -1, 0, 1, 2; 2 is converted to -1 in the script
        1 then represents a site occupied by particle A and -1 occupied by particle B
        See Krishnan, Jaiwal & Puri, JCP 139, 174705 (2013)
    > NX, NY should be powers of 2
    > dx is the grid spacing

  OUPUT: two (double) arrays of length Nbins
    q:  wavelength       (output)
    SF: Structure factor (output)


  MEMORY BUFFERS
    Psi2D:  complex NX x NY
    buff1D: complex length 2*min(NX, NY)  >>>> NOTE THE FACTOR TWO <<<<
*/
int calculateStructureFactor(int NX, int NY, double dx, double **Psi2D, complex **Psi2D_FT, int Nbins, complex *buff1D, double *q_arr, double *SF)
{
  int i,j, ind;
  int Nmin=(NX<NY ? NX : NY);
  double a, b, q,
         dq=2.0*M_PI/(dx*Nmin), dq_binned,// qmax=sqrt(2.0)*M_PI*Nmin;
         qmax=2.0*M_PI*(Nbins)/(sqrt(2.0)*((Nmin/2-1))*dx);
  int *counter;

  dq_binned=qmax/(Nbins-1); // dq in output file

  // Initialise output
  for(i=0; i<Nbins; i++)
  {
    q_arr[i]=dq_binned*i;
    SF[i]=0.0;
  }

  // Obtain 2D fast Fourier transform (FFT)
  for(i=0; i<NX; i++)
    for(j=0; j<NY; j++)
      Psi2D_FT[i][j] = (Psi2D[i][j]==1 ? 1 : (Psi2D[i][j]==2 ? -1 : Psi2D[i][j]) ); 


  fft2(Psi2D_FT, buff1D, NX, NY);

  // Take square of the FFT and average radially
  counter=(int*)buff1D;
  for(i=0; i<Nbins; i++)
    counter[i]=0;

  for(i=0; i<Nmin/2; i++)
  {
    for(j=0; j<Nmin/2; j++)
    {
      q = sqrt(i*i+j*j);
      ind=(int)((double)q/(sqrt(2)));
      a=creal(Psi2D_FT[i][j]);
      b=cimag(Psi2D_FT[i][j]);
      SF[ind] += ( a*a + b*b );
      counter[ ind]++;
    }
  }

  // normalise
  for(i=0; i<Nbins; i++)
    SF[i] = (counter[i]==0 ? 0.0 : SF[i]/counter[i]);

  return(1);
}
