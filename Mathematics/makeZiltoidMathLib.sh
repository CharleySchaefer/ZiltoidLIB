#!/usr/bin/env bash

#   Mathematics is part of ZiltoidLIB.
#   ZiltoidLIB: C library for physical modelling and simulation.
#   Copyright 2018, Charley Schaefer (c.schaefer@leeds.ac.uk)
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

set -euo pipefail

echo
echo "BUILDING ZiltoidMath"

##########################
# CONFIGURATION

includeFourier=1
includePolynomial=1
includeRandomNumbers=1
includeLinearAlgebra=1
includeErfInv=1

CC=gcc
DEBUG=0

##########################
# PARSE ARGUMENTS

for arg in "$@"; do
    case "$arg" in
        -g|--debug)
            DEBUG=1
            echo "Debugging mode."
            ;;
        --gcc)
            CC=gcc
            echo "Using gcc."
            ;;
        --g++)
            CC=g++
            echo "Using g++."
            ;;
        *)
            echo "Unknown option: $arg" >&2
            exit 1
            ;;
    esac
done

##########################
# COMPILER FLAGS

if [[ "$CC" == "g++" ]]; then
    STANDARD="-std=c++11"
else
    STANDARD="-std=c11"
fi

if (( DEBUG )); then
    CFLAGS=("$STANDARD" -O0 -g -Wall -Wextra -Wpedantic -fPIC)
else
    CFLAGS=("$STANDARD" -O2 -Wall -Wextra -Wpedantic -fPIC)
fi

##########################
# BUILD DIRECTORY

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

mkdir -p build

##########################
# SOURCE FILES

sources=()

if (( includeFourier )); then
    sources+=(Fourier/Fourier.c)
fi

if (( includePolynomial )); then
    sources+=(Polynomial/Polynomial.c)
fi

if (( includeRandomNumbers )); then
    sources+=(RandomNumbers/RandomNumbers.c)
fi

if (( includeLinearAlgebra )); then
    sources+=(
        LinearAlgebra/LinearAlgebra.c
        LinearAlgebra/DoolittleAlgorithm/DoolittleAlgorithm.c
    )
fi

if (( includeErfInv )); then
    sources+=(ErfInv/erfinv.c)
fi

# Always include the main Mathematics module.
sources+=(Mathematics.c)

##########################
# COMPILE SOURCE FILES

objects=()

for source in "${sources[@]}"; do
    name="${source##*/}"
    name="${name%.c}"
    object="build/${name}.o"

    "$CC" "${CFLAGS[@]}" \
        -c "$source" \
        -o "$object"

    objects+=("$object")

    echo "  ${name} compiled."
done

##########################
# CREATE STATIC LIBRARY

rm -f build/libZiltoidMath.a

ar rcs build/libZiltoidMath.a "${objects[@]}"

cp build/libZiltoidMath.a .

echo
echo "libZiltoidMath.a created successfully."
echo "FINISHED COMPILING ZiltoidMath"

