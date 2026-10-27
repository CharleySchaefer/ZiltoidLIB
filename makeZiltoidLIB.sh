
#!/usr/bin/env bash

set -euo pipefail

echo
echo "BUILDING ZILTOIDLIB"

##########################
# SETTINGS

CC=gcc
DEBUG=0
INCLUDE_LAPACK=0

CFLAGS=(-std=c11 -O2 -Wall -Wextra -Wpedantic -fPIC)

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
            echo "Use gcc compiler."
            ;;

        --g++)
            CC=g++
            echo "Use g++ compiler."
            ;;

        --include-lapack|--includeZiltoidLAPACK)
            INCLUDE_LAPACK=1
            ;;

        *)
            echo "Unknown option: $arg" >&2
            exit 1
            ;;
    esac
done

if (( DEBUG )); then
    CFLAGS=(-std=c11 -O0 -g -Wall -Wextra -Wpedantic -fPIC)
fi

if [[ "$CC" == "g++" ]]; then
    if (( DEBUG )); then
        CFLAGS=(-std=c++11 -O0 -g -Wall -Wextra -Wpedantic -fPIC)
    else
        CFLAGS=(-std=c++11 -O2 -Wall -Wextra -Wpedantic -fPIC)
    fi
fi

if (( INCLUDE_LAPACK )); then
    echo "LAPACK-dependent functions: included"
else
    echo "LAPACK-dependent functions: excluded"
    echo "To include them, run: $0 --include-lapack"
fi

##########################
# LOCATE PROJECT

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

##########################
# BUILD SUB-LIBRARIES

# These scripts use the original command-line conventions.
sub_args=()

if (( DEBUG )); then
    sub_args+=(-g)
fi

compiler_arg="--$CC"

build_module() {
    local directory="$1"
    local script="$2"
    shift 2

    echo
    echo "BUILDING $directory"

    (
        cd "$directory"
        "./$script" "$@"
    )
}

build_module LatticeLIB \
    makeLatticeLIB.sh \
    "${sub_args[@]}" "$compiler_arg"

build_module Mathematics \
    makeZiltoidMathLib.sh \
    "${sub_args[@]}" "$compiler_arg"

build_module NumericalMethods \
    makeZiltoidNumLib.sh \
    "${sub_args[@]}" "$compiler_arg"

build_module StringOperations \
    makeZiltoidStringsLib.sh \
    "${sub_args[@]}" "$compiler_arg"

build_module ReadTextFiles \
    makeZiltoidReadLib.sh \
    "${sub_args[@]}" "$compiler_arg"

build_module kMC \
    makeZiltoidKMC.sh \
    "${sub_args[@]}"

build_module Memory \
    makeZiltoidMemory.sh \
    "${sub_args[@]}"

build_module Applications \
    makeZiltoidApps.sh \
    "${sub_args[@]}" "$compiler_arg"

##########################
# PREPARE BUILD DIRECTORY

rm -rf build
mkdir -p build

cd build

##########################
# EXTRACT OBJECT FILES

archives=(
    ../kMC/build/libZiltoidKMC.a
    ../LatticeLIB/build/libLatticeLIB.a
    ../Mathematics/build/libZiltoidMath.a
    ../Memory/build/libZiltoidMemory.a
    ../NumericalMethods/build/libZiltoidNum.a
    ../StringOperations/build/libZiltoidStrings.a
    ../ReadTextFiles/build/libZiltoidRead.a
    ../Applications/bin/libZiltoidApps.a
)

for archive in "${archives[@]}"; do
    echo "Extracting: $archive"
    ar x "$archive"
done

##########################
# OPTIONAL LAPACK MODULE

if (( INCLUDE_LAPACK )); then
    echo
    echo "COMPILING ZILTOIDLAPACK"

    "$CC" "${CFLAGS[@]}" \
        -c ../Mathematics/LinearAlgebra/lapack/eigenproblem.c \
        -o lapack_eigenproblem.o

    echo "  lapack_eigenproblem.o compiled"
fi

##########################
# CREATE STATIC LIBRARY

echo
echo "Object files after compilation:"

objects=(./*.o)

if (( ${#objects[@]} == 0 )) || [[ ! -f "${objects[0]}" ]]; then
    echo "Error: no object files found." >&2
    exit 1
fi

for object in "${objects[@]}"; do
    echo "  - ${object#./}"
done

ar rcs libZiltoidLIB.a "${objects[@]}"

cp libZiltoidLIB.a ..

echo
echo "libZiltoidLIB.a created successfully."
echo "FINISHED BUILDING ZILTOIDLIB"

