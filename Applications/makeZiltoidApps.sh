#!/bin/bash

#===============================
# CONFIGURATION
cnf=1
ModuleName=ZiltoidApps
#===============================

echo "COMPILING $ModuleName"
mkdir -p bin
pushd bin >/dev/null



if [ $cnf -eq 1 ]; then
  if gcc -fPIC -c ../PrincipleMomentsOfInertia/PrincipleMomentsOfInertia.c ; then
    echo "  PrincipleMomentsOfInertia compiled."
   else
    echo "Error: Failed to compile PrincipleMomentsOfInertia."
    exit 1
  fi
fi

pushd ../ColumnStats > /dev/null
  ./compile_ColumnStats.sh > /dev/null
popd > /dev/null
mv ../ColumnStats/getColumnStats.o .



if ar rcs lib$ModuleName.a PrincipleMomentsOfInertia.o 
then
  echo "  lib$ModuleName.a created."
else
  echo "Error: failed to create $ModuleName module."
fi



popd >/dev/null
echo "FINISHED COMPILING $ModuleName"

