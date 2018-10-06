#!/bin/bash

pth="../.."
MainC="Demo_StructureFactorAndCorrelationFunction.c"
executable="StructureFactorAndCorrelationFunction"

# Compile
echo "  Compiling $executable"
gcc -o $executable $MainC $pth/Fourier/Fourier.c $pth/Mathematics/Mathematics.c $pth/ReadTextFiles/ReadTextFiles.c $pth/StringOperations/StringOperations.c $pth/StructureFactor/StructureFactor.c -lm

# Run
echo "  Running ./$executable --file config100.dat > config100_SFCF.out"
./$executable --file config100.dat > config100_SFCF.out

# Plot (requires gnuplot installed)
echo "  Calling gnuplot:"
echo "    Running ../../utils/gnuplot/plotMatrix.sh config100.dat"
../../utils/gnuplot/plotMatrix.sh config100.dat

echo "    Running ./plotSF.sh config100_SFCF.out"
./plotSF.sh config100_SFCF.out

echo "    Running ./plotCF.sh config100_SFCF.out"
./plotCF.sh config100_SFCF.out

echo "  Done"








