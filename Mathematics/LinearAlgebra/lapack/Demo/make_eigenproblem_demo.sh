#!/bin/bash
CC=gcc # tested for both gcc and g++

echo "COMPILE"
${CC}  -Wall -o demo_eigenvalues_real_symmetric_matrix.o demo_eigenvalues_real_symmetric_matrix.c ../eigenproblem.c ../../LinearAlgebra.c -lm -lblas -llapack

echo "RUN"
./demo_eigenvalues_real_symmetric_matrix.o
