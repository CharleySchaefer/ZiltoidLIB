#!/bin/bash

#===============================
# CONFIGURATION
includeFourier=1
includePolynomial=1
includeRandomNumbers=1
includeLinearAlgebra=1
#===============================

echo "COMPILING ZiltoidMath"
mkdir -p build
pushd build >/dev/null



if [ $includeFourier -eq 1 ]; then
  if gcc -fPIC -c ../Fourier/Fourier.c ; then
    echo "  Fourier compiled."
   else
    echo "Error: Failed to compile Fourier."
    exit 1
  fi
fi
if [ $includePolynomial -eq 1 ]; then
  if gcc -fPIC -c ../Polynomial/Polynomial.c ; then
    echo "  Polynomial compiled."
   else
    echo "Error: Failed to compile Polynomial."
    exit 1
  fi
fi
if [ $includeRandomNumbers -eq 1 ]; then
  if gcc -fPIC -c ../RandomNumbers/RandomNumbers.c ; then
    echo "  RandomNumbers compiled."
   else
    echo "Error: Failed to compile RandomNumbers."
    exit 1
  fi
fi
if [ $includeLinearAlgebra -eq 1 ]; then
  if gcc -fPIC -c ../LinearAlgebra/LinearAlgebra.c ; then
    echo "  LinearAlgebra compiled."
   else
    echo "Error: Failed to compile LinearAlgebra."
    exit 1
  fi
fi
if [ $includeLinearAlgebra -eq 1 ]; then
  if gcc -fPIC -c ../LinearAlgebra/DoolittleAlgorithm/DoolittleAlgorithm.c ; then
    echo "  DoolittleAlgorithm compiled."
   else
    echo "Error: Failed to compile DoolittleAlgorithm."
    exit 1
  fi
fi
if gcc -fPIC -c ../Mathematics.c ; then
  echo "  Mathematics compiled."
else
  echo "Error: Failed to compile Mathematics."
  exit 1
fi
if ar rcs libZiltoidMath.a LinearAlgebra.o Mathematics.o DoolittleAlgorithm.o Fourier.o Polynomial.o RandomNumbers.o
then
  echo "  libZiltoidMath.a created."
else
  echo "Error: failed to create library."
fi

popd >/dev/null
echo "FINISHED COMPILING ZiltoidMath"

