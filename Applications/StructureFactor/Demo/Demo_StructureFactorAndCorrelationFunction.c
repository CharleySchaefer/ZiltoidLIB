#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <unistd.h> // check if file exists
#include "../StructureFactor.h"
#include "../../../ReadTextFiles/ReadTextFiles.h"

int main(int argc, char *argv[])
{
  //-----------------------------------
  // DECLARE VARIABLES
  int i,j;


  // input
  int NX,NY;
  int Nheader, Ndata, verbose=1;
  double **Psi2D;


  // output
  int     Nbins;
  int     *counter;
  double  dx, sumf;
  complex *buff1D;
  complex **Psi2D_FT;
  double  *q_arr, *SF_arr;
  double  *R_arr;
  complex *C_arr;

  double Lx = 1.0;  /* Command-line specification of the domain size. */
  int Lx_set = 0;

  // READ ARGUMENTS FROM COMMAND LINE:
  i = 1;
  const char *fname = "config100.dat";
  if(argc<2)
  {
    printf("Usage: %s --file <file name>\n", argv[0]);
    return(-1);
  }

  while( i < argc ){
    const char *arg = argv[i];
    if( strcmp( arg, "--L" ) == 0 ){
      Lx = atof( argv[i+1] );
      Lx_set = 1;
      i += 2;
    }else if( strcmp( arg, "--file" ) == 0 ){
      fname = argv[i+1];
      if( access( fname, F_OK ) == -1 ) 
      {
        printf("Error: File \'%s\' does not exist!\n"); return(0);
      }
      i += 2;
    }else{
      printf( "Error parsing args! Arg \"%s\" not recognized!\n", arg );
      return -1;
    }
  }


  // VARIABLES DECLARED
  //-----------------------------------

  printf("\n#Demo StructureFactor\n");

  //-----------------------------------
  // READ MATRIX
  if(!analyse_data_file_properties( (char*)fname, &NX, &NY, &Nheader, &Ndata, verbose))
  {printf("Error: analyse_data_file_properties() failed!\n"); exit(1);}

  // allocate memory
  Psi2D=(double**)malloc(NX*sizeof(double*));
  for(i=0; i<NX; i++)
    Psi2D[i]=(double*)malloc(NY*sizeof(double));

  if(!readMatrix((char*)fname, Psi2D, NX, NY))
    {printf("Error: Failed to execute readMatrix()!\n"); return(0);}
  // MATRIX READ
  //-----------------------------------

  //-----------------------------------
  dx = 1.0;
  if( Lx_set ){
    dx = Lx / (NX-1);
  }
  Nbins  =(int)( (double)(NX<NY?NX:NY)/sqrt(2) ) - 1;
  counter=(    int*)malloc(          Nbins*sizeof(int    ));
  q_arr  =( double*)malloc(          Nbins*sizeof(double ));
  SF_arr =( double*)malloc(          Nbins*sizeof(double ));
  buff1D =(complex*)malloc(2*(NX>NY?NX:NY)*sizeof(complex));
  Psi2D_FT=(complex**)malloc(NX*sizeof(complex*));
  for(i=0; i<NX; i++)
    Psi2D_FT[i]=(complex*)malloc(NY*sizeof(complex));

  // Calculate radially averaged S(q)
  calculateStructureFactor2D(NX, NY, dx, Psi2D, Psi2D_FT, Nbins, buff1D, q_arr, SF_arr);

  // Calculate correlation function C(r)
  R_arr  =( double*)malloc(         (2*Nbins-1)*sizeof(double ));
  C_arr  =(complex*)malloc(         (2*Nbins-1)*sizeof(complex ));
  //free(buff1D);
  buff1D  =(complex*)malloc(         (2*Nbins-1)*sizeof(complex ));

  for (i=0; i<Nbins; i++)
    C_arr[i]=SF_arr[i];
  for (i=Nbins; i<(2*Nbins-1); i++)
    C_arr[i]=SF_arr[2*Nbins-1-i];

  dft(C_arr, buff1D, 2*Nbins-1  ); // Discrete Fourier transform (should actually be the inverse FT

  sumf=0.0;
  for (i=0; i<2*Nbins-1; i++)
    sumf+=creal( C_arr[i] );

  dx=2.0*M_PI/q_arr[Nbins-1];

  printf("%16s %16s %16s %16s\n", "#q", "S(q)", "R", "C(R)");
  for (i=0; i<Nbins; i++)
  {
    printf("%16e %16e %16e %16e\n", q_arr[i], SF_arr[i]/(NX*NY), dx*i, creal(buff1D[i])/sumf );
  }

  return(0);
}
