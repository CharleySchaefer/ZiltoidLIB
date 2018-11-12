#!/bin/bash

#===============================
# CONFIGURATION
includeStringOperations=1
#===============================

echo "COMPILING ZiltoidStrings"
mkdir -p build
pushd build >/dev/null


if [ $includeStringOperations -eq 1 ]; then
  if gcc -fPIC -c ../StringOperations.c ; then
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
echo "FINISHED COMPILING ZiltoidStrings"

