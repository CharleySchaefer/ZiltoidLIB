#!/bin/bash

echo " COMPILE"
gcc -o Demo_QR.o Demo_QRdecomposition.c ../Mathematics.c -lm

echo " RUN"
./Demo_QR.o
