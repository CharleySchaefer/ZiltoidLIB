# LatticeLIB

## Purpose

Library for building lattices, dealing with (e.g., periodic) boundaries, and performing transformations of the lattice (e.g., rotations and reflections). 

This software is a module of [ZiltoidLIB](https://github.com/CharleySchaefer/ZiltoidLIB), which is freely distributed under the Apache 2.0 (Version 2.0, January 2004) license WITHOUT WARRANTY, see LICENSE.txt.

## Features

### Cuboid lattices (2D and 3D) 

**Data storage**  
Data is stored in linear array of length (NX * NY * NZ) in so-called row-major form:  
value at lattice site (x,y,z) is found in lattice at position/index (z + Nz * (y + Ny * x))  
translating between (x,y,z) and (index) is done using coor2ind and ind2coor functions.  
In 2D coor2ind_square/ind2coor_square and in 3D coor2ind_cube/ind2coor_cube  
The column-major alternative of storing data is provided in the source code, and is currently commented.

**Transformation**  

* Sparse matrix transformations  
* rotate (2-3 dimensions)  
* reflect (1-3 dimensions) 

**Analysis**  

* Nearest-neighbour (NN) N/S/E/W/U/D on periodic lattice  
* Nearest-neighbourhood: creating and analysing lists with displacements/relative positions.  
* Obtaining sites belonging in volume defined by (multiple) sphere(s) or sphere shell.  
* Get angle between three sites  

### Hexagonal lattices  

Under construction 


## System requirements and Installation

### Software dependencies:

* gcc compiler (no dependencies other than the standard C stdlib.h, stdio.h, math.h)
* bash (for installation script)

### Versions the software has been tested on

* operating system: Linux clinux 3.16.0-7-amd64 #1 SMP Debian 3.16.59-1 (2018-10-03) x86_64 GNU/Linux  
* compiler: gcc version 4.9.2 (Debian 4.9.2-10+deb8u2)  
* using shell scripts: GNU bash, version 4.3.30(1)-release (x86_64-pc-linux-gnu)


### Installation / usage


**Installation:**  
Run ```./makeLatticeLIB.sh``` to compile the static library *libLatticeLIB.a*.

**Usage:**  
In the *main.h* or *main.c* file of custom software, include the library using  
```#include "path-to-lib/LatticeLIB.h"```  
and compile the software using  
```gcc main.c -Lpath-to-lib -lLatticeLIB -lm```


