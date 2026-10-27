
#!/usr/bin/env bash

# LatticeLIB is part of ZiltoidLIB.
# ZiltoidLIB: C library for physical modelling and simulation.
# Copyright 2018, Charley Schaefer
#
# Licensed under the Apache License, Version 2.0.
# See http://www.apache.org/licenses/LICENSE-2.0

set -euo pipefail

echo
echo "BUILDING LatticeLIB"

##########################
# SETTINGS

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
# COMPILE SOURCE FILES

sources=(
    LatticeCube/LatticeCube
    LatticeHCP/LatticeHCP
    NN/NN
)

objects=()

for source in "${sources[@]}"; do
    name="${source##*/}"
    object="build/${name}.o"

    "$CC" "${CFLAGS[@]}" \
        -c "${source}.c" \
        -o "$object"

    objects+=("$object")
    echo "  ${name} compiled."
done

##########################
# CREATE STATIC LIBRARY

rm -f build/libLatticeLIB.a

ar rcs build/libLatticeLIB.a "${objects[@]}"

echo "  libLatticeLIB.a created."
echo
echo "FINISHED COMPILING LatticeLIB"

