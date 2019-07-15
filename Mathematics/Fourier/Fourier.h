#ifndef FOURIER_H
  #define FOURIER_H  1

  #include <complex.h>
  #include <math.h>
  #ifndef M_PI
    #define M_PI 3.14159265358979323846264338327950288419716939937510582097494459230781
  #endif

  // Discrete Fourier transform
  void  dft(    complex double *,  complex double *, int);
  void  dft2(   complex double **, complex double *, int,  int);

  // Fast Fourier transform (1D) Adapted from RosettaCodeData https://github.com/acmeism/RosettaCodeData/tree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C
  void  fft(    complex double *, complex double *, int);
  void  fft_emb(complex double *, complex double *, int, int);
  void ifft(    complex double *, complex double *, int);
  void ifft_emb(complex double *, complex double *, int, int);

  // Fast Fourier transform (2D) - uses 1D version
  void  fft2( complex double **, complex double *, int, int);
  void ifft2( complex double **, complex double *, int, int);

  // Fast Fourier transform (3D) - uses 1D version
  void  fft3(complex double ***, complex double *, int, int, int);
  void ifft3(complex double ***, complex double *, int, int, int);
#endif

