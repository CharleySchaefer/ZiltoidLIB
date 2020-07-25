#!/bin/bash

pth="../../.."
MainC="Demo_StructureFactorAndCorrelationFunction.c"
executable="StructureFactorAndCorrelationFunction.o"

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


# Compile
if ${CC} -o $executable $MainC $pth/Applications/StructureFactor/StructureFactor.c -L$pth -lZiltoidLIB -lm $debug ; then
  echo "  $executable compiled."
else
  echo "  compilation $executable failed."
fi

