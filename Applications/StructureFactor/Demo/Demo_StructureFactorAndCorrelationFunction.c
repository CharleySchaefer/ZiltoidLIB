#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <unistd.h> // check if file exists
#include "../StructureFactor.h"
//#include "../../../ReadTextFiles/ReadTextFiles.h"
#include "../../../ZiltoidLIB.h"

int main(int argc, char *argv[])
{
  //-----------------------------------
  // DECLARE VARIABLES
  int i,j;


  // input
  int NX,NY;
  int Nheader, Ndata, verbose=0;
  double **Psi2D;


  // output
  int     Nbins;
  int     *counter;
  int stretchmatrix=0;
  double  dx,dy, sumf;
  double _Complex *buff1D;
  double _Complex **Psi2D_FT;
  double  *q_arr, *SF_arr;
  double  *R_arr;
  double _Complex *C_arr;

  double Lx = 1.0, Ly = 1.0;  /* Command-line specification of the domain size. */
  int Lx_set = 0, Ly_set = 0;

  // READ ARGUMENTS FROM COMMAND LINE:
  i = 1;
  const char *fname = "config100.dat";
  if(argc<2)
  {
    printf("Usage: %s --file <file name> [options]\n", argv[0]);
    printf("file: plain text row/column data representing a matrix.\n");
    printf("      This demo assumes periodic boundaries and calculates the.\n");
    printf("      structure factor and correlation function.\n");
    printf("\nOptions:\n");
    printf("  --Lx <value>:      set physical length scale in x direction.\n");
    printf("  --Ly <value>:      set physical length scale in y direction.\n");
    printf("  --stretch-matrix: interpolate square Nx x Ny to Nx' x Ny', with Nx'=2^(nx) >= Nx and Ny'=2^(ny) >= Ny.\n");
    printf("  For demo, see ZiltoidLIB/Applications/StructureFactor/Demo, and run\n");
    printf("            ./demo_StructureFactor.sh.\n");
    return(-1);
  }

  while( i < argc ){
    const char *arg = argv[i];
    if( strcmp( arg, "--Lx" ) == 0 ){
      Lx = atof( argv[i+1] );
      Lx_set = 1;
      i += 2;
    } else if( strcmp( arg, "--Ly" ) == 0 ){
      Ly = atof( argv[i+1] );
      Ly_set = 1;
      i += 2;
    }else if( strcmp( arg, "--file" ) == 0 ){
      fname = argv[i+1];
      if( access( fname, F_OK ) == -1 ) 
      {
        printf("Error: File \'%s\' does not exist!\n", fname); return(0);
      }
      i += 2;
    }else if( strcmp( arg, "--stretch-matrix" ) == 0 ){
      stretchmatrix=1;
      i += 1;
    }else{
      printf( "Error parsing args! Arg \"%s\" not recognized!\n", arg );
      return -1;
    }
  }


  // VARIABLES DECLARED
  //-----------------------------------

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
 /* if(NX!=NY)
  {printf("Error: non-square matrices not yet implemented.\n") ; return(-1);}
*/
  double **Psi2D_stretched=Psi2D;
  if(stretchmatrix)
  {
    int NX_old=NX, NY_old=NY;
     
    NX=1;
    while (NX<NX_old)
      NX*=2;
    NY=1;
    while (NY<NY_old)
      NY*=2;
   // NY=NX;
    if (NX!=NX_old && NY!=NY_old)
    {
      Psi2D_stretched=(double**)malloc(NX*sizeof(double*));
      for(i=0; i<NX; i++)
        Psi2D_stretched[i]=(double*)malloc(NY*sizeof(double));

      stretch_matrix(0, Psi2D, NX_old, NY_old, Psi2D_stretched, NX, NY);
    }
  }

  /* Grid spacing */
  dx = 1.0;
  if( Lx_set ){
    dx = Lx / (NX);
  }
  dy = 1.0;
  if( Ly_set ){
    dy = Ly / (NY);
  }
  Nbins  =(int)(    0.5*sqrt(( (NX*NX)+(NY*NY) ) )   ); // - 1;
  counter=(    int*)malloc(          Nbins*sizeof(int    ));
  q_arr  =( double*)malloc(          Nbins*sizeof(double ));
  SF_arr =( double*)malloc(          Nbins*sizeof(double ));
  buff1D =(double _Complex*)malloc(2*(NX>NY?NX:NY)*sizeof(double _Complex));
  Psi2D_FT=(double _Complex**)malloc(NX*sizeof(double _Complex*));
  for(i=0; i<NX; i++)
    Psi2D_FT[i]=(double _Complex*)malloc(NY*sizeof(double _Complex));

  // Calculate radially averaged S(q)
  //calculateStructureFactor2D(    NX, NY, dx,     Psi2D_stretched, Psi2D_FT, Nbins, buff1D, q_arr, SF_arr);
  calculateStructureFactor2Drect(NX, NY, dx, dy, Psi2D_stretched, Psi2D_FT, Nbins, buff1D, q_arr, SF_arr);

  // Calculate correlation function C(r)
  R_arr  =( double*)malloc(         (2*Nbins-1)*sizeof(double ));
  C_arr  =(double _Complex*)malloc(         (2*Nbins-1)*sizeof(double _Complex ));
  free(buff1D);
  buff1D  =(double _Complex*)malloc(         (2*Nbins-1)*sizeof(double _Complex ));

  for (i=0; i<Nbins; i++)
    C_arr[i]=SF_arr[i];
  for (i=Nbins; i<(2*Nbins-1); i++)
    C_arr[i]=SF_arr[2*Nbins-1-i];

  dft(C_arr, buff1D, 2*Nbins-1  ); // Discrete Fourier transform (should actually be the inverse FT

  sumf=0.0;
  for (i=0; i<2*Nbins-1; i++)
    sumf+=creal( C_arr[i] );

  double dr=2.0*M_PI/q_arr[Nbins-1];

  printf("%16s %16s %16s %16s\n", "#q", "S(q)", "R", "C(R)");
  for (i=0; i<Nbins; i++)
  {
    printf("%16e %16e %16e %16e\n", q_arr[i], SF_arr[i]/(NX*NY), dr*i, creal(buff1D[i])/sumf );
  }

  // Free memory
  for(i=0; i<NX; i++)
  {
    free(Psi2D_FT[i]);        Psi2D_FT[i]=NULL;
    free(Psi2D_stretched[i]); Psi2D_stretched[i]=NULL;
  }
  free(Psi2D_FT);
  free(Psi2D_stretched);
  free(counter);
  free(q_arr);
  free(SF_arr);
  free(buff1D);
  free(R_arr);
  free(C_arr);


  return(0);
}
