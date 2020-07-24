#   StringOperations is part of ZiltoidLIB.
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
includeStringOperations=1
#===============================

CC=gcc # default
arg=""
debug=""

echo "  >COMPILING ZiltoidStrings"
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




mkdir -p build
pushd build >/dev/null


if [ $includeStringOperations -eq 1 ]; then
  if ${CC} -Wall -fPIC -c ../StringOperations.c $debug ; then
    echo "  StringOperations compiled."
   else
    echo "Error: Failed to compile StringOperations."
    exit 1
  fi
fi

if ar rcs libZiltoidStrings.a StringOperations.o
then
  echo "  libZiltoidStrings.a created."
else
  echo "Error: failed to create library."
fi

popd >/dev/null

cp build/*.a .
echo "  >FINISHED COMPILING ZiltoidStrings"

