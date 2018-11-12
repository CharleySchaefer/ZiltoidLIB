#!/bin/bash

#===============================
# CONFIGURATION
includeReadTextFiles=1
#===============================

echo "COMPILING ZiltoidRead"
mkdir -p build
pushd build >/dev/null


if [ $includeReadTextFiles -eq 1 ]; then
  if gcc -fPIC -c ../ReadTextFiles.c ; then
    echo "  ReadTextFiles compiled."
   else
    echo "Error: Failed to compile ReadTextFiles."
    exit 1
  fi
fi

if ar rcs libZiltoidRead.a ReadTextFiles.o
then
  echo "  libZiltoidRead.a created."
else
  echo "Error: failed to create library."
fi

popd >/dev/null
echo "FINISHED COMPILING ZiltoidRead"

