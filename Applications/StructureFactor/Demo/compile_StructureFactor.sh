#!/bin/bash

pth="../../.."
MainC="Demo_StructureFactorAndCorrelationFunction.c"
executable="StructureFactorAndCorrelationFunction.o"

arg=""
if [ $# -eq 1 ]; then
  arg=$1
  if [ $arg != "-g" ]; then
    echo "Unexpected argument $arg - exiting."
    exit 1
  fi
fi

# Compile
if gcc -o $executable $MainC $pth/Applications/StructureFactor/StructureFactor.c -L$pth -lZiltoidLIB -lm $arg ; then
  echo "  $executable compiled."
else
  echo "  compilation $executable failed."
fi

