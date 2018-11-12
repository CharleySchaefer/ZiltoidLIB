#!/bin/bash


#================================================================
echo " "
echo "BUILDING ZILTOIDLIB"

includeZiltoidLapack=0 # default
for i in `seq 1 $#`
do
  if [ "${@:$i:1}" == "--includeZiltoidLAPACK" ]; then
    includeZiltoidLapack=1
  fi
done

if [ $includeZiltoidLapack -eq 1 ]; then
  echo "LAPACK-dependent functions: included"
else
  echo "LAPACK-dependent functions: excluded - to include, run $0 --includeZiltoidLAPACK"
fi
echo " "
#================================================================


rm build -r
mkdir -p build

pushd build  >/dev/null

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





if [ $includeZiltoidLapack -eq 1 ]
then
  echo " "
  echo "COMPILING ZILTOIDLAPACK"
  pushd ../Mathematics/LinearAlgebra/lapack  >/dev/null
    gcc -fPIC -c eigenproblem.c  
  popd >/dev/null
  cp ../Mathematics/LinearAlgebra/lapack/eigenproblem.o lapack_eigenproblem.o
  echo "  lapack_eigenproblem.o compiled"
  echo "FINISHED COMPILING ZILTOIDLAPACK"
  echo " "
fi

echo "  Extracting dependency-free modules in build:"
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



