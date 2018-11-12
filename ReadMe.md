![image](doc/ZiltoidLIB.png)

## ABOUT

Dependency-free C library of functions that are commonly encoutered in C programs for physical modelling and simulation.


## FEATURES

### Modules

* Mathematics
  * Fourier (adapted from [RosettaCode](https://github.com/acmeism/RosettaCodeDatatree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C))
  * LUdecomposition (adapted from [lawliet89](https://github.com/lawliet89/DoolittleDeterminant))
  * Polynomial (adapted from [uni-koeln](http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c))
  * QR decomposition (adapted from [jcchurch](https://github.com/jcchurch/C-Linear-Algebra))
* Numerical Methods
  * Interpolation
  * Bisection method
* String Operations
  * Read word from string, count words in a string.
* Read Text Files
  * Determine number of header lines, number of columns, number of data lines.
  * Read rows and columns
* Structure Factor
  * Fourier transform to Q space
  * Radial averaging in Q space
  * Radial correlation function
* kMC 
  * Variable step size method

### Utils

* Gnuplot demo for producing .eps and .pdf format graphs 
* GNU Octave / Matlab scripts


## Installation

The main programs only require a **gcc compiler** without external dependencies.


In demos, **bash** scripts and **gnuplot** may be used. 


## Examples

![Demo](https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/StructureFactor/Demo) for reading a data file (without headers), representing a 2D lattice configuration, and calculating the structure factor and correlation function.

<img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/matrix.png" alt="drawing" width="215"/>  <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/SF.png" alt="drawing" width="300"/>   <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/CF.png" alt="drawing" width="300"/>
