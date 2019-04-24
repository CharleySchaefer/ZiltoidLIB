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

arg=""
if [ $# -eq 1 ]; then
  arg=$1
  if [ $arg != "-g" ]; then
    echo "Unexpected argument $arg - exiting."
    exit 1
  fi
fi

echo "  >COMPILING ZiltoidMemory"
mkdir -p build
pushd build >/dev/null




if gcc -fPIC -c ../Memory.c $arg ; then
  echo "  Memory.c compiled."
else
  echo "Error: Failed to compile Memory.c."
  exit 1
fi

if ar rcs libZiltoidMemory.a Memory.o
then
  echo "  libZiltoidMemory.a created."
else
  echo "Error: failed to create library."
fi

popd >/dev/null
echo "  >FINISHED COMPILING ZiltoidMemory"

