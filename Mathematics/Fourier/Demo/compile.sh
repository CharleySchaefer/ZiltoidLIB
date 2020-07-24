#!/bin/bash
CC=gcc # gcc or g++
LINKER=-lm
LIBS=../..
pushd $LIBS
  ./makeZiltoidMathLib.sh --$CC
popd

${CC} -Wall DemoFourier.c -L../.. -lZiltoidMath  ${LINKER} -o demoFourier


