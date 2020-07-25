#!/bin/bash

lib=../..
executable=getColumnStats.o

CC=gcc # default
arg=""
debug=""

for n in "$@" ; do
  if [ $n == "-g" ]; then
    echo "  Debugging mode."
    debug="-g"
  elif [ $n == "--gcc" ]; then
    echo "  Using gcc"
    CC=gcc
  elif [ $n == "--g++" ]; then
    echo "  Using g++"
    CC=g++
  fi
done

if ${CC} -o $executable get_column_stats_from_file.c -L$lib -lZiltoidLIB -lm $debug ; then
  echo "  $executable compiled."
else
  echo "  compilation $executable failed."
fi
