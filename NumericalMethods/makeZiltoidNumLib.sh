#!/bin/bash

#===============================
# CONFIGURATION
includeInterpolation=1
includeBisection=1
#===============================

echo "COMPILING ZiltoidNum"
mkdir -p build
pushd build >/dev/null


if [ $includeInterpolation -eq 1 ]; then
  if gcc -fPIC -c ../Interpolation/Interpolation.c ; then
    echo "  Interpolation compiled."
   else
    echo "Error: Failed to compile Interpolation."
    exit 1
  fi
fi; 
if [ $includeBisection -eq 1 ]; then
  if gcc -fPIC -c ../Bisection/Bisection.c ; then
    echo "  Bisection compiled."
   else
    echo "Error: Failed to compile Bisection."
    exit 1
  fi
fi

if ar rcs libZiltoidNum.a Interpolation.o Bisection.o
then
  echo "  libZiltoidNum.a created."
else
  echo "Error: failed to create library."
fi

popd >/dev/null
echo "FINISHED COMPILING ZiltoidNum"

