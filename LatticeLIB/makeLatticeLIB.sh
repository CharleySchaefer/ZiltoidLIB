#!/bin/bash


#================================================================
echo " "
echo "BUILDING LatticeLIB"

rm build -r
mkdir -p build

pushd build >/dev/null

if gcc -fPIC -c ../LatticeCube/LatticeCube.c ; then
  echo "  LatticeCube compiled."
 else
  echo "Error: Failed to compile LatticeCube."
  exit 1
fi

if gcc -fPIC -c ../LatticeHCP/LatticeHCP.c ; then
  echo "  LatticeHCP compiled."
 else
  echo "Error: Failed to compile LatticeHCP."
  exit 1
fi

if gcc -fPIC -c ../NN/NN.c ; then
  echo "  NN compiled."
 else
  echo "Error: Failed to compile NN."
  exit 1
fi

if ar rcs libLatticeLIB.a LatticeCube.o NN.o
then
  echo "  libLatticeLIB.a created."
else
  echo "Error: failed to create libLatticeLIB.a."
fi


popd >/dev/null

mv build/libLatticeLIB.a .

echo "FINISHED COMPILING LatticeLIB"
