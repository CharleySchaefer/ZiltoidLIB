#!/bin/bash

#===============================
# CONFIGURATION
includeVSSM=1
#===============================

echo "COMPILING ZiltoidKMC"
mkdir -p build
pushd build >/dev/null



if [ $includeVSSM -eq 1 ]; then
  if gcc -fPIC -c ../VSSM.c ; then
    echo "  VSSM compiled."
   else
    echo "Error: Failed to compile VSSM."
    exit 1
  fi
fi

if ar rcs libZiltoidKMC.a VSSM.o 
then
  echo "  libZiltoidKMC.a created."
else
  echo "Error: failed to create library."
fi



popd >/dev/null
echo "FINISHED COMPILING ZiltoidKMC"

