#!/bin/bash

lib=../..
executable=getColumnStats.o

arg=""
if [ $# -eq 1 ]; then
  arg=$1
  if [ $arg != "-g" ]; then
    echo "Unexpected argument $arg - exiting."
    exit 1
  fi
fi

if gcc -o $executable get_column_stats_from_file.c -L$lib -lZiltoidLIB -lm $arg ; then
  echo "  $executable compiled."
else
  echo "  compilation $executable failed."
fi
