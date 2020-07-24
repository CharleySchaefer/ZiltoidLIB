# ZiltoidLIB: Mathematics

## PURPOSE
Small set of frequently encountered math functions without external dependencies. This C/C++ library is a module of [ZiltoidLIB](https://github.com/CharleySchaefer/ZiltoidLIB), which is freely distributed under the Apache 2.0 (Version 2.0, January 2004) license WITHOUT WARRANTY, see LICENSE.txt.

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


### Inverse Error Function

 * Adapted from C++ adaptation by [Lakshay Garg](https://github.com/lakshayg/erfinv)

## INSTALLATION

### Option 1: Dependency-free installation

**Compile**: Run the "makeZiltoidMathLib.sh" script  
``` ./makeZiltoidMathLib.sh ```  
By default, this script uses gcc to create a static library libZiltoidMath.a. 
Presently, a copy is kept in "build/libZiltoidMath.a".  
To compile using g++, run  
``` ./makeZiltoidMathLib.sh --g++```  
To use the -g flag for debugging, run  
``` ./makeZiltoidMathLib.sh -g``` or ``` ./makeZiltoidMathLib.sh --g++ -g```.

**Usage** (see Demo):  
Include the library in source code "#include "dir/Mathematics.h", and compile using
``` gcc sourcecode.c -Ldir/build -lZiltoidMath -lm ``` 
with "dir" the directory that contains Mathematics.h.


### Option 2: Using LAPACK

To make use of functions in the lapack directory, install lapack:  
``` (sudo) apt-get install libblas-dev liblapack-dev ```

Build the Mathematics library using the "makeZiltoidMathLib.sh" script as in Option 1.
Use the library as in Option 1, but when compiling the source code do  
``` gcc sourcecode.c -Ldir/build -lZiltoidMath -llapack -lm ``` 

## DEPENDENCIES
  No external dependencies, however, part of the code is modified from code that was developed elsewhere: 
  * Fourier:            https://github.com/acmeism/RosettaCodeDatatree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C
  * LUdecomposition:    https://github.com/lawliet89/DoolittleDeterminant
  * Polynomial:         http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c 
  * QRdecomposition     https://github.com/jcchurch/C-Linear-Algebra
