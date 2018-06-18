/*
  FSTD - FOURIER ANALYSIS

  PART OF CONTENT OWNED BY EXTERNAL PARTIES!

  Makes use of math.h, complex.h

  FUNCTIONS
  - DiscreteFT        - Discrete Fourier transform in 1D
  - DiscreteFT2       - Discrete Fourier transform in 2D (CONTAINS BUG FOR RECTANGULAR GRIDS!)
  - fft, ifft         - Fast Fourier Transform and Inverse Fast Fourier Transform in 1D
  - fft2, ifft2       - Fast Fourier Transform and Inverse Fast Fourier Transform in 2D
  - fft3, ifft3       - Fast Fourier Transform and Inverse Fast Fourier Transform in 2D
  - getPowerSpectrum  - Obtain power spectrum of 2D array
*/
//=====================================================================
void DiscreteFT( double *,  double *, double *, double *, int);
void DiscreteFT2(double **, double **, int, int);
void _fft( complex *,   complex *, int, int);
void fft(  complex *,   int);
void _ifft(complex *,   complex *, int, int);
void ifft( complex *,   int);
void fft2( complex **,  complex *, int, int);
void ifft2(complex **,  complex *, int, int);
void fft3( complex ***, complex *, int, int, int );
void ifft3(complex ***, complex *, int, int, int);
void getStructureFactor2D(int , int , double , double **, complex **, complex *, double *, double *, double *, double *);
int solvePoisson1D(complex*, double* , int, double, int);
int initialisePoissonWavenumber(double*, int, double);
void getPowerSpectrum1D(int, double, double *, double *, double *, double *, double *, double *, double *, double *, double *);
void getPowerSpectrum_int(int, double, int **, double **, double **, double *, double *, double *, double *);
void getPowerSpectrum(int, double, double **, double **, double **, double *, double *, double *, double *);
void getStructureFactor2D(int, int, double, double **, complex **, complex *, double *, double *, double *, double *);
//=====================================================================

/*====================================================== 
  Discrete Fourier transform
  Copyright (c) 2012 Nayuki Minase
  
  http://nayuki.eigenstate.org/page/how-to-implement-the-discrete-fourier-transform

 
  Computes the discrete Fourier transform (DFT) of the given vector.
  All the array arguments must have the same length.
 */
void DiscreteFT(double *inreal, double *inimag, double *outreal, double *outimag, int n) {
	int k;
	for (k = 0; k < n; k++) {  // For each output element 
		double sumreal = 0;
		double sumimag = 0;
		int t;
		for (t = 0; t < n; t++) {  // For each input element 
			sumreal +=  inreal[t]*cos(2*M_PI * t * k / n) + inimag[t]*sin(2*M_PI * t * k / n);
			sumimag += -inreal[t]*sin(2*M_PI * t * k / n) + inimag[t]*cos(2*M_PI * t * k / n);
		}
		outreal[k] = sumreal;
		outimag[k] = sumimag;
	}
}
/*-----------------------------------------------------------------------------------*/
/*
	Discrete Fourier Transform (DFT) in 2D
	Charley Schaefer 2013-08-29
	
	2D FT is performed by first doing the 1D DFT along the columns and then 
	subsequently doing the 1D DFT along the columns.

	NOTE: 
		The DFT is slower (~N^2) than the fast Fourier Transform (FFT)
	
	ARGUMENTS:
		pic_real, pic_imag: Real and imaginary parts of the 2D array.
							The output will be put in the same arrays.
		Nx, Ny:				Size of the array.
*/
void DiscreteFT2(double **pic_real, double **pic_im, int Nx, int Ny){

	if(Nx!=Ny)
		{printf("DiscreteFT2 contains bug for Nx!=Ny; Should be updated!\n"); exit(1);}
	
	int i,j,Nmax = (Ny>Nx ? Ny : Nx);
	double *arr_real, *arr_im, *out_real, *out_im;
	
	arr_real = (double*)malloc(Nmax*sizeof(double));
	arr_im = (double*)malloc(Nmax*sizeof(double));
	out_real = (double*)malloc(Nmax*sizeof(double));
	out_im = (double*)malloc(Nmax*sizeof(double));
	
	// Fourier transform
	// 1. rows
	for (i=0; i<Nx; i++){
		// Copy a row
		for ( j = 0; j < Nx; j++) { 
			 arr_real[j] = pic_real[i][j];
			 arr_im[j] = pic_im[i][j];
		  }
		// Fourier transform a row
		DiscreteFT(arr_real, arr_im, out_real, out_im, Nx);
		
		// Copy back
		for ( j = 0; j < Nx; j++) { 
			 pic_real[i][j] = out_real[j];
			 pic_im[i][j]   = out_im[j];
		  }
		}
	
	// 2. columns
	for (i=0; i<Ny; i++){
		// Copy a row
		for ( j = 0; j < Ny; j++) { 
			 arr_real[j] = pic_real[j][i];
			 arr_im[j] = pic_im[j][i];
		  }
		// Fourier transform a row
		DiscreteFT(arr_real, arr_im, out_real, out_im, Ny);
		
		// Copy back
		for ( j = 0; j < Ny; j++) { 
			 pic_real[j][i] = out_real[j];
			 pic_im[j][i]   = out_im[j];
		  }
		}
	}


//-----------------------------------------------------------------------------------
/*
	Fast Fourier Transform (FFT) in 1D
	http://rosettacode.org/wiki/Fast_Fourier_transform#C 2014-04-02
	
	2D FT is performed by first doing the 1D DFT along the columns and then 
	subsequently doing the 1D DFT along the columns.

	NOTE: 
		Requires complex.h library
*/
void _fft(complex *buf, complex *out, int n, int step)
{
  int i;
	if (step < n) 
	{
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);
 
		for ( i = 0; i < n; i += 2 * step)
		{
			complex t = cexp(-I * M_PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}


void fft(complex *buf, int n)
{
	int	i;
	complex out[n];
	for ( i = 0; i < n; i++) out[i] = buf[i];
 
	_fft(buf, out, n, 1);
}

void _ifft(complex *buf, complex *out, int n, int step)
{
	int	i;
	if (step < n) 
	{
		_ifft(out, buf, n, step * 2);
		_ifft(out + step, buf + step, n, step * 2);
 
		for ( i = 0; i < n; i += 2 * step)
		{
			complex t = cexp(+I * M_PI * i / n) * out[i + step];
			buf[i / 2]     = 0.5*(out[i] + t);
			buf[(i + n)/2] = 0.5*(out[i] - t);
		}
	}
}
void ifft(complex *buf, int n)
{
	int	i;
	complex out[n];
	for ( i = 0; i < n; i++) out[i] = buf[i];
 
	_ifft(buf, out, n, 1);
}


/*-----------------------------------------------------------------------------------*/
/*
	Fast Fourier Transform (DFT) in 2D
	Charley Schaefer 2013-08-29
	
	2D FT is performed by first doing the 1D FFT along the rows and then 
	subsequently doing the 1D FFT along the columns.

	NOTE: 
		The DFT is slower (~N^2) than the fast Fourier Transform (FFT)
	
	ARGUMENTS:
		pic_real, pic_imag: Real and imaginary parts of the 2D array.
							The output will be put in the same arrays.
		Nx, Ny:				Size of the array.
*/
void fft2(complex **arr2, complex *buf, int Nx, int Ny)
{
	
	int i,j;
	
	// Fourier transform
	// 1. rows
	for (i=0; i<Nx; i++)
	{
		// Copy a row
		for ( j = 0; j < Ny; j++) 
			 buf[j] = arr2[i][j];
			 
		// Fourier transform a row
		fft(buf, Ny);
		
		// Copy back
		for ( j = 0; j < Ny; j++) 
			 arr2[i][j] = buf[j];
	}
	
	// 2. columns
	for (i=0; i<Ny; i++)
	{
		// Copy a row
		for ( j = 0; j < Nx; j++) 
			 buf[j] = arr2[j][i];
		  
		// Fourier transform a row
		fft(buf, Nx);
		
		// Copy back
		for ( j = 0; j < Nx; j++) 
			 arr2[j][i] = buf[j];
	}
}

void ifft2(complex **arr2, complex *buf, int Nx, int Ny)
{
	
	int i,j;
	
	// Fourier transform
	// 1. rows
	for (i=0; i<Nx; i++)
	{
		// Copy a row
		for ( j = 0; j < Ny; j++) 
			 buf[j] = arr2[i][j];
			 
		// Fourier transform a row
		ifft(buf, Ny);
		
		// Copy back
		for ( j = 0; j < Ny; j++) 
			 arr2[i][j] = buf[j];
	}
	
	// 2. columns
	for (i=0; i<Ny; i++)
	{
		// Copy a row
		for ( j = 0; j < Nx; j++) 
			 buf[j] = arr2[j][i];
		  
		// Fourier transform a row
		ifft(buf, Nx);
		
		// Copy back
		for ( j = 0; j < Nx; j++) 
			 arr2[j][i] = buf[j];
	}
}

	
/*-----------------------------------------------------------------------------------*/
/*
	Fast Fourier Transform (DFT) in 3D
	Charley Schaefer 2013-08-29
	
	2D FT is performed by first doing the 1D FFT along the rows and then 
	subsequently doing the 1D FFT along the columns.

	NOTE: 
		The DFT is slower (~N^2) than the fast Fourier Transform (FFT)
	
	ARGUMENTS:
		pic_real, pic_imag: Real and imaginary parts of the 2D array.
							The output will be put in the same arrays.
		Nx, Ny:				Size of the array.
*/
void fft3(complex ***arr3, complex *buf, int Nx, int Ny, int Nz)
{
	
	int i,j,k;
	
	for(j=0; j<Ny;j++)
		for(k=0; k<Nz;k++)
		{
		for(i=0; i<Nx; i++)
			buf[i] = arr3[i][j][k];
		fft(buf, Nx);
		for(i=0; i<Nx; i++)
			arr3[i][j][k] = buf[i];
		}
	for(i=0; i<Nx; i++)
		for(k=0; k<Nz;k++)
		{
		for(j=0; j<Ny;j++)
			buf[j] = arr3[i][j][k];
		fft(buf, Ny);
		for(j=0; j<Ny;j++)
			arr3[i][j][k] = buf[j];
		}	
	for(j=0; j<Ny;j++)
		for(i=0; i<Nx; i++)
		{
		for(k=0; k<Nz;k++)
			buf[k] = arr3[i][j][k];
		fft(buf, Nz);
		for(k=0; k<Nz;k++)
			arr3[i][j][k] = buf[k];
		}
}
void ifft3(complex ***arr3, complex *buf, int Nx, int Ny, int Nz)
{
	
	int i,j,k;
	
	for(j=0; j<Ny;j++)
		for(k=0; k<Nz;k++)
		{
		for(i=0; i<Nx; i++)
			buf[i] = arr3[i][j][k];
		ifft(buf, Nx);
		for(i=0; i<Nx; i++)
			arr3[i][j][k] = buf[i];
		}
	for(i=0; i<Nx; i++)
		for(k=0; k<Nz;k++)
		{
		for(j=0; j<Ny;j++)
			buf[j] = arr3[i][j][k];
		ifft(buf, Ny);
		for(j=0; j<Ny;j++)
			arr3[i][j][k] = buf[j];
		}	
	for(j=0; j<Ny;j++)
		for(i=0; i<Nx; i++)
		{
		for(k=0; k<Nz;k++)
			buf[k] = arr3[i][j][k];
		ifft(buf, Nz);
		for(k=0; k<Nz;k++)
			arr3[i][j][k] = buf[k];
		}
}
	
	
//----------------------------------------------------------------------------------------------------------------------------------
/*
  getStructureFactor2D

  Calculate structure factor of a 2D field


  ARGUMENTS:
  array2D is the NXxNY array of which the power spectrum is calculated. Entries: 
    * Either doubles that represent the value of an order parameter
        Each element in this case represents a volume/area with some concentration / order parameter.
    * Or integers of value -1, 0, 1, 2; 2 is converted to -1 in the script
        1 then represents a site occupied by particle A and -1 occupied by particle B
        See Krishnan, Jaiwal & Puri, JCP 139, 174705 (2013)

  NX, NY and should be a power of 2

  dx is the grid spacing
	Buffers are used for Fourier transform.
	-> buffer2Da, buffer2Db : 2D arrays of size N x N 
	-> buffer1Da, buffer1Db : 1D arrays of length N*N/4

  Memory requirements of the buffers depends on NX and NY.

  (q, SF): Arrays of length Nmin*Nmin/4, with Nmin = min(NX, NY).
    q:  wavelength       (output)
    SF: Structure factor (output)
*/
void getStructureFactor2D(int NX, int NY, double dx, double **array2D, complex **buff2D, complex *buff1D, double *buffer1Da, double *buffer1Db, double *q, double *SF)
{
  int i,j,count;
  int Nmin=minimum_int(NX,NY);
  double x,y, **array2DFTre, **array2DFTim, *q0, *SF0, a, b, 
         fac=2.0*M_PI/(dx*Nmin);

  q0 = buffer1Da;
  SF0 = buffer1Db;

  for(i=0; i<NX; i++)
    for(j=0; j<NY; j++)
      buff2D[i][j] = (array2D[i][j]==1 ? 1 : (array2D[i][j]==2 ? -1 : array2D[i][j]) ); 

  fft2(buff2D, buff1D, NX, NY);

  count=0;
  for(i=0; i<Nmin/2; i++)
  {
    for(j=0; j<Nmin/2; j++)
    {
      q0[count] = fac*sqrt(i*i+j*j);
      a=creal(buff2D[i][j]);
      b=cimag(buff2D[i][j]);
      SF0[count] = ( a*a + b*b );					
      count++;
    }
  }
  mergesortUf2(q0, SF0, Nmin*Nmin/4);
  Histogram(q0, SF0, q, SF, Nmin*Nmin/4, (int)(1.0*Nmin/sqrt(2)));
}
	
	
//----------------------------------------------------------------------------------------------------------------------------------
/*
	getPowerSpectrum - Charley Schaefer 2013-11-22
	
	array2D is the NxN array of which the power spectrum is calculated.
	dx is the grid spacing
	
	Buffers are used for Fourier transform.
	-> buffer2Da, buffer2Db : 2D arrays of size N x N 
	-> buffer1Da, buffer1Db : 1D arrays of length N*N/4
	
	IMPROVEMENTS TO BE DONE:
	1. Fast Fourier transform instead of direct Fourier transform
	

*/
void getPowerSpectrum(int N, double dx, double **array2D, double **buffer2Da, double **buffer2Db, double *buffer1Da, double *buffer1Db, double *q, double *SF)
{
	int i,j,count;
	double x,y, **array2DFTre, **array2DFTim, *q0, *SF0;
	array2DFTre = buffer2Da;
	array2DFTim = buffer2Db;
	q0 = buffer1Da;
	SF0 = buffer1Db;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			array2DFTre[i][j] = array2D[i][j]; 
			array2DFTim[i][j] = 0.0; 
		}
	DiscreteFT2(array2DFTre, array2DFTim, N, N); // Obtain 2D Fourier transform
	count=0;
	for(i=0; i<N/2; i++){
		x = 2.0*M_PI*i/(dx*N);	
		for(j=0; j<N/2; j++){
			y = 2.0*M_PI*j/(dx*N);
			q0[count] = sqrt(x*x+y*y);
			SF0[count] = sqrt( array2DFTre[i][j]*array2DFTre[i][j] + array2DFTim[i][j]*array2DFTim[i][j] );					
			count++;
			}
		}
	mergesortUf2(q0, SF0, N*N/4);
	Histogram(q0, SF0, q, SF, N*N/4, (int)(1.0*N/sqrt(2)));
}


void getPowerSpectrum_int(int N, double dx, int **array2D, double **buffer2Da, double **buffer2Db, double *buffer1Da, double *buffer1Db, double *q, double *SF)
{
	int i,j,count;
	double x,y, **array2DFTre, **array2DFTim, *q0, *SF0;
	array2DFTre = buffer2Da;
	array2DFTim = buffer2Db;
	q0 = buffer1Da;
	SF0 = buffer1Db;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			array2DFTre[i][j] = 1.0*array2D[i][j]; 
			array2DFTim[i][j] = 0.0; 
		}
	DiscreteFT2(array2DFTre, array2DFTim, N, N); // Obtain 2D Fourier transform
	count=0;
	for(i=0; i<N/2; i++){
		x = 2.0*M_PI*i/(dx*N);	
		for(j=0; j<N/2; j++){
			y = 2.0*M_PI*j/(dx*N);
			q0[count] = sqrt(x*x+y*y);
			SF0[count] = sqrt( array2DFTre[i][j]*array2DFTre[i][j] + array2DFTim[i][j]*array2DFTim[i][j] );					
			count++;
			}
		}
	mergesortUf2(q0, SF0, N*N/4);
	Histogram(q0, SF0, q, SF, N*N/4, (int)(1.0*N/sqrt(2.0)));
}

void getPowerSpectrum1D(int NGRID, double dx, double *array1D, double *buffer1Da, double *buffer1Db, double *buffer1Dc, double *buffer1De, double *buffer1Df, double *buffer1Dd, double *q, double *R)
{
	int i,j,count;
	double x,y, *array1DFTre, *array1DFTim, *q0, *R0;
	array1DFTre = buffer1Da;
	array1DFTim = buffer1Db;
	q0 = buffer1Dc;
	R0 = buffer1Dd;
	
	for(i=0; i<NGRID; i++)
		{
			buffer1De[i] = array1D[i]; 
			buffer1Df[i] = 0.0; 
		}
	DiscreteFT(buffer1De, buffer1De, array1DFTre, array1DFTim, NGRID); // Obtain 2D Fourier transform
	count=0;
	for(i=0; i<NGRID/2; i++){
		x = 2.0*M_PI*i/(dx*NGRID);	
//		for(j=0; j<N/2; j++){
//			y = 2.0*M_PI*j/(dx*N);
			q0[count] = sqrt(x*x);
			R0[count] = sqrt( array1DFTre[i]*array1DFTre[i] + array1DFTim[i]*array1DFTim[i] );					
			count++;
	//		}
		}
	mergesortUf2(q0, R0, NGRID/2);
	Histogram(q0, R0, q, R, NGRID/2, NGRID/2);
}

/*------------------------------------------------------------------------------------------
  Get array "ksqi" of length Nx with -1/|k|^2, with k=2Pi/L the maximum value of the wavenumber.
  Array is symmetric around index 0.
*/
int initialisePoissonWavenumber(double*ksqi, int Nx, double L)
{
  int i;

  ksqi[0]=1.0; 
  for (i=1; i<Nx/2+1; i++)
  {
    ksqi[i]    = (2*PI/L)*i; // wave number
    ksqi[i]    =-1.0/(ksqi[i]*ksqi[i]);  // Inverse Square
    ksqi[Nx-i] = ksqi[i];                     // mirror
  }
  return(1);
}

int solvePoisson1D(complex* f, double* ksqi, int Nx, double L, int init)
{
  int i;
  // initialise
  if(init==1)
    if(!( initialisePoissonWavenumber(ksqi, Nx, L) ))
      {printf("ERROR: Failed to execute initialisePoissonWavenumber()!\n"); exit(1);}   

  // Fourier transform
  fft(f, Nx);

  // Solve Poisson equation in Fourier space
  for (i=0; i<Nx; i++)
    f[i]*=ksqi[i];

  // inverse Fourier transform
  ifft(f, Nx);
  return(1);
}


