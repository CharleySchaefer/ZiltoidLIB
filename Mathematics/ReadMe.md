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
  square:  LUdecomposition, eigenvalues, determinant 

### Analysis 
* get roots of a polynomial (up to order 5)

* Linear interpolation

* Fourier transform
  
## DEPENDENCIES
  None. Part of the code is modified from code that was developed elsewhere: 
  * DoolittleAlgorithm: https://github.com/lawliet89/DoolittleDeterminant/
  * Polynomial:         http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c 
  * Fourier:            https://github.com/acmeism/RosettaCodeData/tree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C
