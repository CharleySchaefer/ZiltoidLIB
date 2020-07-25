<img src="doc/ZiltoidLIB.png" alt="img" width="200"/>

## ABOUT

Collection of functions commonly encountered in C/C++ programs for physical modelling and simulation.
This library does not require external libraries, except for solving some eigenvalue problems (BLAS/LAPACK).

<sub>This software is freely distributed under the Apache 2.0 (Version 2.0, January 2004) license WITHOUT WARRANTY, see LICENSE.txt.</sub>


## FEATURES

### Modules

* Kinetic Monte Carlo  
  * Variable step size method  
* [LatticeLIB](https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/LatticeLIB) (both C/C++)  
  * Periodic and non-periodic simple cubic (sc) and hexagonal close packed (hcp) lattices  
  * Transformations (reflect, rotate), finding neighbours within cutoff radius.  
  * (in development) Structure to build custom lattices.  
* [Mathematics](https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/Mathematics) (both C/C++)  
  * Fourier (adapted from [RosettaCode](https://github.com/acmeism/RosettaCodeDatatree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C); for an efficient alternative see e.g. [fftw](http://www.fftw.org/))  
  * LUdecomposition (adapted from [lawliet89](https://github.com/lawliet89/DoolittleDeterminant))  
  * Polynomial (adapted from [uni-koeln](http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c))  
  * QR decomposition (adapted from [jcchurch](https://github.com/jcchurch/C-Linear-Algebra))  
  * Array statistics: min, max, abs, mean, variance, standard deviation  
  * (BLAS/LAPACK) Solve eigenvalue problem symmetric matrices  
* Numerical Methods (both C/C++)  
  * Interpolation  
  * Bisection method  
* Read Text Files (uses String Operations module) (both C/C++)  
  * Determine number of header lines, number of columns, number of data lines.  
  * Read rows and columns  
* String Operations (both C/C++)  
  * Read word from string, count words in a string.  

### Applications

* Statistics from file with column data
  * Header recognition
  * min/max, mean, variance, se of mean, median, quartiles
* ![Structure Factor](https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/Applications/StructureFactor/Demo) 
  * Fourier transform to Q space
  * Radial averaging in Q space
  * Radial correlation function
* Principle Moments of Inertia (uses Mathematics and BLAS/LAPACK)

<img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/Applications/StructureFactor/Demo/matrix.png" alt="drawing" width="215"/>  <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/Applications/StructureFactor/Demo/SF.png" alt="drawing" width="300"/>   <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/Applications/StructureFactor/Demo/CF.png" alt="drawing" width="300"/>


### Utils

* Gnuplot demo for producing .eps and .pdf format graphs:  
```sudo apt-get install gnuplot```  
* GNU Octave / Matlab scripts
```sudo apt-get install octave```  

## Installation / usage

**Download:**  
Download from ![here](https://github.com/CharleySchaefer/ZiltoidLIB), or clone  
```git clone https://github.com/CharleySchaefer/ZiltoidLIB```  

**Installation:**  

*Option 1 - Standard C/C++ without external dependencies):* The static library can be build for C without external dependencies using  
``` ./makeZiltoidLIB.sh ```  
or, equivalently, using  
``` ./makeZiltoidLIB.sh --gcc```  
For C++, the library can by build using  
``` ./makeZiltoidLIB.sh --g++```  

*Option 2 - Including external BLAS/LAPACK:* (linear algebra libraries)  
Install BLAS/LAPACK:  
```sudo apt-get install libblas-dev liblapack-dev```
Compile library:  
``` ./makeZiltoidLIB.sh --include-lapack```  

*Option 3 - Debugging (for development):*  
``` ./makeZiltoidLIB.sh -g```  
Debugging can be done e.g. using valgrind:
```sudo apt-get install valgrind```



**Usage:**  
Include the library in main.c or main.h of custom software using  
```#include "path-to-ziltoidlib/ZiltoidLIB.h"```  
Compile the software using  
```gcc main.c -Lpath-to-ziltoidlib -lZiltoidLIB -lm```



