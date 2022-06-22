#!/bin/bash

datafile=$1
rootsdata=$2

plot="set terminal pngcairo enhanced
set output 'CF.png'

#set log x
set xlabel 'R'

#set log y
set ylabel 'C(R)'

set grid 

unset key

plot '$datafile' u 3:4 w l lt 1 lw 2 lc rgb '#AA4444',\
'$rootsdata' u 1:(\$1*0) w p pt 6 ps 1.5 lw 2 lc rgb 'black',\
'$rootsdata' u 2:(\$1*0) w p pt 6 ps 1.5 lw 2 lc rgb 'black',\
'$rootsdata' u 3:(\$4) w p pt 6 ps 1.5 lw 2 lc rgb 'black',\
'$rootsdata' u 5:(\$6) w p pt 6 ps 1.5 lw 2 lc rgb 'black'
"

printf "$plot" | gnuplot
