<img src="doc/ZiltoidLIB.png" alt="img" width="200"/>

## ABOUT

Collection of functions commonly encoutered in C programs for physical modelling and simulation.
This library does not require external libraries, except for solving some eigenvalue problems (BLAS/LAPACK).


## FEATURES

### Modules

* Mathematics
  * Fourier (adapted from [RosettaCode](https://github.com/acmeism/RosettaCodeDatatree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C))
  * LUdecomposition (adapted from [lawliet89](https://github.com/lawliet89/DoolittleDeterminant))
  * Polynomial (adapted from [uni-koeln](http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c))
  * QR decomposition (adapted from [jcchurch](https://github.com/jcchurch/C-Linear-Algebra))
  * Array statistics: min, max, abs, mean, variance, standard deviation 
  * (BLAS/LAPACK) Solve eigenvalue problem symmetric matrices
* Numerical Methods
  * Interpolation
  * Bisection method
* String Operations
  * Read word from string, count words in a string.
* Read Text Files (uses String Operations module)
  * Determine number of header lines, number of columns, number of data lines.
  * Read rows and columns
* Kinetic Monte Carlo 
  * Variable step size method

### Applications
* Principle Moments of Inertia (uses Mathematics and BLAS/LAPACK)
* Structure Factor (uses Mathematics module)
  * Fourier transform to Q space
  * Radial averaging in Q space
  * Radial correlation function

### Utils

* Gnuplot demo for producing .eps and .pdf format graphs 
* GNU Octave / Matlab scripts

## System requirements and Installation

### Software dependencies:

* gcc compiler
* bash
* (optional) Postprocessing and other utilities:  
  * gnuplot: plotting of data. (see http://www.gnuplot.info)  
  * Matlab  / gnu octave to run .m scripts
* (optional) debugging: valgrind memcheck

### Versions the software has been tested on

* operating system: Linux clinux 3.16.0-7-amd64 #1 SMP Debian 3.16.59-1 (2018-10-03) x86_64 GNU/Linux  
* compiler: gcc version 4.9.2 (Debian 4.9.2-10+deb8u2)  
* using shell scripts: GNU bash, version 4.3.30(1)-release (x86_64-pc-linux-gnu)  
* plotting: gnuplot 4.6 patchlevel 6 
* debugging: valgrind-3.10.0  
* .m scripts: GNU Octave, version 4.0.0 (configured for "x86_64-unknown-linux-gnu")


### Installation / usage


**Installation:**  
Without BLAS/LAPACK functionality compile ZiltoidLIB by running:  
``` ./makeZiltoidLIB.sh ```  
With BLAS/LAPACK functionality compile ZiltoidLIB by running:  
``` ./makeZiltoidLIB.sh --include-lapack```


**Usage:**  
Include the library in main.c or main.h of custom software using  
```#include "path-to-ziltoidlib/ZiltoidLIB.h"```  
Compile the software using  
```gcc main.c -Lpath-to-ziltoidlib -lZiltoidLIB -lm```





## Examples

![Demo](https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/Applications/StructureFactor/Demo) for reading a data file (without headers), representing a 2D lattice configuration, and calculating the structure factor and correlation function.

<img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/Applications/StructureFactor/Demo/matrix.png" alt="drawing" width="215"/>  <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/Applications/StructureFactor/Demo/SF.png" alt="drawing" width="300"/>   <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/Applications/StructureFactor/Demo/CF.png" alt="drawing" width="300"/>
