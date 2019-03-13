#!/bin/bash

#===============================
# CONFIGURATION
cnf=1
ModuleName=ZiltoidApps
#===============================

echo "COMPILING $ModuleName"
mkdir -p build
pushd build >/dev/null



if [ $cnf -eq 1 ]; then
  if gcc -fPIC -c ../PrincipleMomentsOfInertia/PrincipleMomentsOfInertia.c ; then
    echo "  PrincipleMomentsOfInertia compiled."
   else
    echo "Error: Failed to compile PrincipleMomentsOfInertia."
    exit 1
  fi
fi

if [ $cnf -eq 1 ]; then
  if gcc -fPIC -c ../ColumnStats/get_column_stats_from_file.c ; then
    echo "  ColumnStats compiled."
   else
    echo "Error: Failed to compile ColumnStats."
    exit 1
  fi
fi

if ar rcs lib$ModuleName.a PrincipleMomentsOfInertia.o 
then
  echo "  lib$ModuleName.a created."
else
  echo "Error: failed to create $ModuleName module."
fi



popd >/dev/null
echo "FINISHED COMPILING $ModuleName"

