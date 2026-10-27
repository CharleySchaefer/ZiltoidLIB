
#!/usr/bin/env bash

#   Applications is part of ZiltoidLIB.
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
echo "BUILDING ZiltoidApps"

##########################
# CONFIGURATION

cnf=1
ModuleName=ZiltoidApps

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

mkdir -p bin

##########################
# COMPILE APPLICATION MODULES

objects=()

if (( cnf )); then
    source="PrincipleMomentsOfInertia/PrincipleMomentsOfInertia.c"
    object="bin/PrincipleMomentsOfInertia.o"

    "$CC" "${CFLAGS[@]}" -c "$source" -o "$object"

    objects+=("$object")
    echo "  PrincipleMomentsOfInertia compiled."
fi

##########################
# BUILD STANDALONE UTILITIES

# These scripts have their own compiler options.
# Keep their existing argument conventions until reviewed.

(
    cd ColumnStats
    ./compile_ColumnStats.sh "--$CC"
)

mv ColumnStats/getColumnStats.o bin/

(
    cd StructureFactor/Demo
    ./compile_StructureFactor.sh "--$CC"
)

mv StructureFactor/Demo/StructureFactorAndCorrelationFunction.o bin/

##########################
# CREATE STATIC LIBRARY

if (( ${#objects[@]} == 0 )); then
    echo "Error: no ZiltoidApps library modules enabled." >&2
    exit 1
fi

rm -f "bin/lib${ModuleName}.a"

ar rcs "bin/lib${ModuleName}.a" "${objects[@]}"

echo
echo "lib${ModuleName}.a created successfully."
echo "FINISHED COMPILING ${ModuleName}"

