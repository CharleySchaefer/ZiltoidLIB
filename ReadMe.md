![image](doc/ZiltoidLIB.png)

## ABOUT

Dependency-free C library of functions that are commonly encoutered in C programs for physical modelling and simulation.


## FEATURES

### Modules

* Reading (data) files
* Interpretation of strings
* Generating random numbers
* Mathematical methods
  

### Utils

* Gnuplot demo for producing .eps and .pdf format graphs 
* GNU Octave / Matlab scripts


## Installation

The main programs only require a **gcc compiler** without external dependencies.
The library does include code developed elsewhere:
  * Fourier:            https://github.com/acmeism/RosettaCodeDatatree/948b86eafab0e034330a3b6c31617370c6cca2fc/Task/Fast-Fourier-transform/C
  * LUdecomposition:    https://github.com/lawliet89/DoolittleDeterminant
  * Polynomial:         http://van-der-waals.pc.uni-koeln.de/quartic/quintic_C.c 
  * QRdecomposition     https://github.com/jcchurch/C-Linear-Algebra

In demos, **bash** scripts and **gnuplot** may be used. 


## Examples

![Demo](https://github.com/CharleySchaefer/ZiltoidLIB/tree/master/StructureFactor/Demo) for reading a data file (without headers), representing a 2D lattice configuration, and calculating the structure factor and correlation function.

<img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/matrix.png" alt="drawing" width="215"/>  <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/SF.png" alt="drawing" width="300"/>   <img src="https://raw.githubusercontent.com/CharleySchaefer/ZiltoidLIB/master/StructureFactor/Demo/CF.png" alt="drawing" width="300"/>
