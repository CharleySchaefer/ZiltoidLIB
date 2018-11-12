#!/bin/bash

echo "COMPILE"
gcc -o demo_eigenvalues_real_symmetric_matrix.o demo_eigenvalues_real_symmetric_matrix.c ../eigenproblem.c -lm -llapack

echo "RUN"
./demo_eigenvalues_real_symmetric_matrix.o
