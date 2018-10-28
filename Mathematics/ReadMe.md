# ZiltoidLIB: Mathematics

## PURPOSE
Small set of frequently encountered math functions without external dependencies.

## FEATURES

### Scalar functions
Take absolute value, determine if an int is a power of 2.
Compare two scalars (minimum, maximum)

### Linear algebra 
 * Arrays 1D / vectors: Get minimum, maximum, mean, variance.
 * Arrays 2D / matrices: 
   general: gauss_jordan
   square:  eigenvalues and determinant via LUdecomposition and QRdecomposition 

### Analysis 
 * get roots of a polynomial (up to order 5)
 * Linear interpolation
 * Fourier transform

### Random numbers

 * Uniform integers, floats and doubles from interval 
 * Sampling normal distribution
 * Correlated noise

## DEPENDENCIES
  No external dependencies, however, part of the code is modified from code that was developed elsewhere: 
  * Fourier:            https://github.com/acmeism/RosettaCodeDatatree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C
  * LUdecomposition:    https://github.com/lawliet89/DoolittleDeterminant
  * Polynomial:         http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c 
  * QRdecomposition     https://github.com/jcchurch/C-Linear-Algebra
