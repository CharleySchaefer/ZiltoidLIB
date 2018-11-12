#!/bin/bash

mkdir -p build

pushd build  >/dev/null

echo " "
echo "BUILDING ZILTOIDLIB"
pushd ../Mathematics  >/dev/null
./makeZiltoidMathLib.sh
popd  >/dev/null  # BACK TO ZILTOID/BUILD 
echo " "

pushd ../NumericalMethods  >/dev/null
./makeZiltoidNumLib.sh
popd  >/dev/null # BACK TO ZILTOID/BUILD
echo " "

pushd ../StringOperations  >/dev/null
./makeZiltoidStringsLib.sh
popd  >/dev/null # BACK TO ZILTOID/BUILD
echo " "

pushd ../ReadTextFiles  >/dev/null
./makeZiltoidReadLib.sh
popd  >/dev/null # BACK TO ZILTOID/BUILD
echo " "

echo "  Extracting modules in build:"
ar x ../Mathematics/build/libZiltoidMath.a
ar x ../NumericalMethods/build/libZiltoidNum.a
ar x ../StringOperations/build/libZiltoidStrings.a
ar x ../ReadTextFiles/build/libZiltoidRead.a

for file in `find *.o`
do
  echo "    "$file
done 

ar rcs libZiltoidLIB.a *.o

popd  >/dev/null # BACK TO ZILTOID
cp build/libZiltoidLIB.a .
echo "  libZiltoidLIB.a created"

echo "FINISHED BUILDING ZILTOIDLIB"
echo " "
