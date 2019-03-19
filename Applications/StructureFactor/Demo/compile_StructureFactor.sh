#!/bin/bash

pth="../../.."
MainC="Demo_StructureFactorAndCorrelationFunction.c"
executable="StructureFactorAndCorrelationFunction.o"

# Compile
if gcc -o $executable $MainC $pth/Mathematics/Fourier/Fourier.c $pth/Mathematics/Mathematics.c $pth/ReadTextFiles/ReadTextFiles.c $pth/StringOperations/StringOperations.c $pth/Applications/StructureFactor/StructureFactor.c -lm ; then
  echo "  $executable compiled."
else
  echo "  compilation $executable failed."
fi

