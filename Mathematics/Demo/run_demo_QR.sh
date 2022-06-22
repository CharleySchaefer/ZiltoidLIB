#!/bin/bash

echo " COMPILE"
#gcc -o Demo_QR.o Demo_QRdecomposition.c ../Mathematics.c -lm

gcc -o demo_d1intersection_sorted.o demo_d1intersection_sorted.c -L../build -lZiltoidMath -lm
gcc -o Demo_QR.o Demo_QRdecomposition.c -L../build -lZiltoidMath -lm

echo " RUN"
./Demo_QR.o
./demo_d1intersection_sorted.o
