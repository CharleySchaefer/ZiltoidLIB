#   Mathematics is part of ZiltoidLIB.
#   ZiltoidLIB: C library for physical modelling and simulation.
#   Copyright 2018, Charley Schaefer (charley.schaefer@york.ac.uk)
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#!/bin/bash

#===============================
# CONFIGURATION
includeFourier=1
includePolynomial=1
includeRandomNumbers=1
includeLinearAlgebra=1
includeErfInv=1
#===============================

arg=""
if [ $# -eq 1 ]; then
  arg=$1
  if [ $arg != "-g" ]; then
    echo "Unexpected argument $arg - exiting."
    exit 1
  fi
fi

echo "  >COMPILING ZiltoidMath"
mkdir -p build
pushd build >/dev/null



if [ $includeFourier -eq 1 ]; then
  if gcc -fPIC -c ../Fourier/Fourier.c $arg ; then
    echo "  Fourier compiled."
   else
    echo "Error: Failed to compile Fourier."
    exit 1
  fi
fi
if [ $includePolynomial -eq 1 ]; then
  if gcc -fPIC -c ../Polynomial/Polynomial.c $arg ; then
    echo "  Polynomial compiled."
   else
    echo "Error: Failed to compile Polynomial."
    exit 1
  fi
fi
if [ $includeRandomNumbers -eq 1 ]; then
  if gcc -fPIC -c ../RandomNumbers/RandomNumbers.c $arg ; then
    echo "  RandomNumbers compiled."
   else
    echo "Error: Failed to compile RandomNumbers."
    exit 1
  fi
fi
if [ $includeLinearAlgebra -eq 1 ]; then
  if gcc -fPIC -c ../LinearAlgebra/LinearAlgebra.c $arg ; then
    echo "  LinearAlgebra compiled."
   else
    echo "Error: Failed to compile LinearAlgebra."
    exit 1
  fi
fi
if [ $includeLinearAlgebra -eq 1 ]; then
  if gcc -fPIC -c ../LinearAlgebra/DoolittleAlgorithm/DoolittleAlgorithm.c $arg ; then
    echo "  DoolittleAlgorithm compiled."
   else
    echo "Error: Failed to compile DoolittleAlgorithm."
    exit 1
  fi
fi
if [ $includeErfInv -eq 1 ]; then
  if gcc -fPIC -c ../ErfInv/erfinv.c $arg ; then
    echo "  ErfInv compiled."
   else
    echo "Error: Failed to compile ErfInv."
    exit 1
  fi
fi
if gcc -fPIC -c ../Mathematics.c $arg ; then
  echo "  Mathematics compiled."
else
  echo "Error: Failed to compile Mathematics."
  exit 1
fi
if ar rcs libZiltoidMath.a LinearAlgebra.o Mathematics.o erfinv.o DoolittleAlgorithm.o Fourier.o Polynomial.o RandomNumbers.o
then
  echo "  libZiltoidMath.a created."
else
  echo "Error: failed to create library."
fi

popd >/dev/null
echo "  >FINISHED COMPILING ZiltoidMath"

