<img src="doc/ZiltoidLIB.png" alt="img" width="200"/>

## ABOUT

Dependence-free C library of functions that are commonly encoutered in C programs for physical modelling and simulation.


## FEATURES

### Modules

* Mathematics
  * Fourier (adapted from [RosettaCode](https://github.com/acmeism/RosettaCodeDatatree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C))
  * LUdecomposition (adapted from [lawliet89](https://github.com/lawliet89/DoolittleDeterminant))
  * Polynomial (adapted from [uni-koeln](http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c))
  * QR decomposition (adapted from [jcchurch](https://github.com/jcchurch/C-Linear-Algebra))
  * Array statistics: min, max, abs, mean, variance, standard deviation 
  * (LAPACK dependence) Solve eigenvalue problem symmetric matrices
* Numerical Methods
  * Interpolation
  * Bisection method
* String Operations
  * Read word from string, count words in a string.
* Read Text Files (uses String Operations module)
  * Determine number of header lines, number of columns, number of data lines.
  * Read rows and columns
* Structure Factor (uses Mathematics module)
  * Fourier transform to Q space
  * Radial averaging in Q space
  * Radial correlation function
* Kinetic Monte Carlo 
  * Variable step size method

### Utils

* Gnuplot demo for producing .eps and .pdf format graphs 
* GNU Octave / Matlab scripts


## Installation

The main programs only require a **gcc compiler** without external dependences.
Modules may be build separately using a simple script, see e.g. *Mathematics/makeZiltoidMathLib.sh*, to create a library, e.g., *Mathematics/build/libZiltoidMath.a*.
To install all modules (except for *Structure Factor*, *Kinetic Monte Carlo*, and functions with external dependences), run the script *makeZiltoidMathLib.sh* which builds a single library in *build/libZiltoidLIB.a*. 





## Examples

![Demo](https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/StructureFactor/Demo) for reading a data file (without headers), representing a 2D lattice configuration, and calculating the structure factor and correlation function.

<img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/matrix.png" alt="drawing" width="215"/>  <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/SF.png" alt="drawing" width="300"/>   <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/CF.png" alt="drawing" width="300"/>
