#!/bin/bash

pth="../../.."
MainC="Demo_StructureFactorAndCorrelationFunction.c"
executable="StructureFactorAndCorrelationFunction.o"

# Compile
CC=gcc # default
arg=""
debug=""

for n in "$@" ; do
  if [ $n == "-g" ]; then
    echo "  Debugging mode."
    debug="-g"
  elif [ $n == "--gcc" ]; then
    echo "  Using gcc"
    CC=gcc
  elif [ $n == "--g++" ]; then
    echo "  Using g++"
    CC=g++
  fi
done

echo "  Compiling $executable"
./compile_StructureFactor.sh --$CC $debug

inputfile=psi_example.dat
LX=10.0
LY=10.0

# Run
echo "  Running ./$executable"
./$executable --file $inputfile --stretch-matrix --Lx $LX --Ly $LY > psi_example.out

# Plot (requires gnuplot installed)
echo "  Calling gnuplot:"
echo "    Running ../../utils/gnuplot/plotMatrix.sh psi_example.dat"
$pth/utils/gnuplot/plotMatrix.sh $inputfile

echo "    Running ./plotSF.sh psi_example.out"
./plotSF.sh psi_example.out

echo "    Running ./plotCF.sh psi_example.out"
./plotCF.sh psi_example.out

echo "  Done"








