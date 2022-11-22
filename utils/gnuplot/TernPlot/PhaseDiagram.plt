#set terminal epslatex # postscript enhanced 18
#set output "ternplot.tex" # "ternary_gpl.eps"
set terminal tikz
set output "TeXfig.tex"

set bmargin 123
set lmargin 3
set rmargin 3
set tmargin 3
set size ratio 0.866
set yrange [0:0.866]
set xrange [0:1]
set noborder
set noxtics
set noytics

set label "\\Large Water" at 0.11, 0.6666*0.8660-0.11*0.6666*0.8660 rotate by 60 centre
set label "\\Large Rubisco" at 0.5, -0.14 centre
set label "\\Large Linker" at 0.91*1.0, 0.91*0.6*0.866 rotate by -60 centre

set label "0.0" at 0.0, -0.05 right
set label "0.2" at 0.2, -0.05 right
set label "0.4" at 0.4, -0.05 right
set label "0.6" at 0.6, -0.05 right
set label "0.8" at 0.8, -0.05 right
set label "1.0" at 1.0, -0.05 right

set label "0.0" at 1.05, 0.0*0.866 left
set label "0.2" at 0.95, 0.2*0.866 left
set label "0.4" at 0.85, 0.4*0.866 left
set label "0.6" at 0.75, 0.6*0.866 left
set label "0.8" at 0.65, 0.8*0.866 left
set label "1.0" at 0.55, 1.0*0.866 left

set label "1.0" at -0.03, 0.052 right
set label "0.8" at 0.07, 0.2252 right
set label "0.6" at 0.1700, 0.3984 right
set label "0.4" at 0.2700, 0.5716 right
set label "0.2" at 0.3700, 0.7448 right
set label "0.0"at 0.47,0.918 right

# Definition of line styles
set style line 1 lt 1 lw 3 pt -1 ps 1 lc rgb "black" # BORDER
set style line 2 lt 5 lw 1 pt -1 ps 1 lc rgb "grey"  # MINOR MESH
set style line 3 lt 5 lw 1 pt -1 ps 1 lc rgb "black" # MAJOR MESH
set style line 4 lt 1 lw 2 pt -1 ps 1 lc rgb "black" # TICS

# Mesh of the phase diagram
set arrow 1 from 0.550000,0.779423 to 0.100000,0.000000 nohead linestyle 2
set arrow 2 from 0.550000,0.779423 to 0.450000,0.779423 nohead linestyle 2
set arrow 3 from 0.100000,0.000000 to 0.050000,0.086603 nohead linestyle 2
set arrow 4 from 0.550000,0.779423 to 0.560000,0.779423 nohead linestyle 4
set arrow 5 from 0.100000,0.000000 to 0.095000,-0.008660 nohead linestyle 4
set arrow 6 from 0.050000,0.086603 to 0.045000,0.095263 nohead linestyle 4
set arrow 7 from 0.600000,0.692820 to 0.200000,0.000000 nohead linestyle 3
set arrow 8 from 0.600000,0.692820 to 0.400000,0.692820 nohead linestyle 3
set arrow 9 from 0.200000,0.000000 to 0.100000,0.173205 nohead linestyle 3
set arrow 10 from 0.600000,0.692820 to 0.620000,0.692820 nohead linestyle 4
set arrow 11 from 0.200000,0.000000 to 0.190000,-0.017321 nohead linestyle 4
set arrow 12 from 0.100000,0.173205 to 0.090000,0.190526 nohead linestyle 4
set arrow 13 from 0.650000,0.606218 to 0.300000,0.000000 nohead linestyle 2
set arrow 14 from 0.650000,0.606218 to 0.350000,0.606218 nohead linestyle 2
set arrow 15 from 0.300000,0.000000 to 0.150000,0.259808 nohead linestyle 2
set arrow 16 from 0.650000,0.606218 to 0.660000,0.606218 nohead linestyle 4
set arrow 17 from 0.300000,0.000000 to 0.295000,-0.008660 nohead linestyle 4
set arrow 18 from 0.150000,0.259808 to 0.145000,0.268468 nohead linestyle 4
set arrow 19 from 0.700000,0.519615 to 0.400000,0.000000 nohead linestyle 3
set arrow 20 from 0.700000,0.519615 to 0.300000,0.519615 nohead linestyle 3
set arrow 21 from 0.400000,0.000000 to 0.200000,0.346410 nohead linestyle 3
set arrow 22 from 0.700000,0.519615 to 0.720000,0.519615 nohead linestyle 4
set arrow 23 from 0.400000,0.000000 to 0.390000,-0.017321 nohead linestyle 4
set arrow 24 from 0.200000,0.346410 to 0.190000,0.363731 nohead linestyle 4
set arrow 25 from 0.750000,0.433013 to 0.500000,0.000000 nohead linestyle 2
set arrow 26 from 0.750000,0.433013 to 0.250000,0.433013 nohead linestyle 2
set arrow 27 from 0.500000,0.000000 to 0.250000,0.433013 nohead linestyle 2
set arrow 28 from 0.750000,0.433013 to 0.760000,0.433013 nohead linestyle 4
set arrow 29 from 0.500000,0.000000 to 0.495000,-0.008660 nohead linestyle 4
set arrow 30 from 0.250000,0.433013 to 0.245000,0.441673 nohead linestyle 4
set arrow 31 from 0.800000,0.346410 to 0.600000,0.000000 nohead linestyle 3
set arrow 32 from 0.800000,0.346410 to 0.200000,0.346410 nohead linestyle 3
set arrow 33 from 0.600000,0.000000 to 0.300000,0.519615 nohead linestyle 3
set arrow 34 from 0.800000,0.346410 to 0.820000,0.346410 nohead linestyle 4
set arrow 35 from 0.600000,0.000000 to 0.590000,-0.017321 nohead linestyle 4
set arrow 36 from 0.300000,0.519615 to 0.290000,0.536936 nohead linestyle 4
set arrow 37 from 0.850000,0.259808 to 0.700000,0.000000 nohead linestyle 2
set arrow 38 from 0.850000,0.259808 to 0.150000,0.259808 nohead linestyle 2
set arrow 39 from 0.700000,0.000000 to 0.350000,0.606218 nohead linestyle 2
set arrow 40 from 0.850000,0.259808 to 0.860000,0.259808 nohead linestyle 4
set arrow 41 from 0.700000,0.000000 to 0.695000,-0.008660 nohead linestyle 4
set arrow 42 from 0.350000,0.606218 to 0.345000,0.614878 nohead linestyle 4
set arrow 43 from 0.900000,0.173205 to 0.800000,0.000000 nohead linestyle 3
set arrow 44 from 0.900000,0.173205 to 0.100000,0.173205 nohead linestyle 3
set arrow 45 from 0.800000,0.000000 to 0.400000,0.692820 nohead linestyle 3
set arrow 46 from 0.900000,0.173205 to 0.920000,0.173205 nohead linestyle 4
set arrow 47 from 0.800000,0.000000 to 0.790000,-0.017321 nohead linestyle 4
set arrow 48 from 0.400000,0.692820 to 0.390000,0.710141 nohead linestyle 4
set arrow 49 from 0.950000,0.086603 to 0.900000,0.000000 nohead linestyle 2
set arrow 50 from 0.950000,0.086603 to 0.050000,0.086603 nohead linestyle 2
set arrow 51 from 0.900000,0.000000 to 0.450000,0.779423 nohead linestyle 2
set arrow 52 from 0.950000,0.086603 to 0.960000,0.086603 nohead linestyle 4
set arrow 53 from 0.900000,0.000000 to 0.895000,-0.008660 nohead linestyle 4
set arrow 54 from 0.450000,0.779423 to 0.445000,0.788083 nohead linestyle 4

# Edges of the phase diagram
set arrow 55 from 0.000000,0.000000 to 1.000000,0.000000 nohead linestyle 1 front
set arrow 56 from -0.010000,-0.017321 to 0.000000,0.000000 nohead linestyle 4 back
set arrow 57 from 0.990000,-0.017321 to 1.000000,0.000000 nohead linestyle 4 back
set arrow 58 from 0.000000,0.000000 to 0.500000,0.866025 nohead linestyle 1 back
set arrow 59 from -0.010000,0.017321 to 0.000000,0.000000 nohead linestyle 4 front
set arrow 60 from 0.490000,0.883346 to 0.500000,0.866025 nohead linestyle 4 back
set arrow 61 from 0.500000,0.866025 to 1.000000,0.000000 nohead linestyle 1 back
set arrow 62 from 1.020000,0.000000 to 1.000000,0.000000 nohead linestyle 4 front
set arrow 63 from 0.520000,0.866025 to 0.500000,0.866025 nohead linestyle 4 back


xcoor(phiA, phiB, phiC)=(phiB+2*phiA)/(2*(phiA+phiB+phiC))
ycoor(phiA, phiB, phiC)= sqrt(3)*phiB/(2*(phiA+phiB+phiC))

# Plot
set style circle radius 0.01
set style fill transparent solid 0.01
set datafile missing
unset key # left width -10
plot 	"< gawk 'NR>1{print ($2+2*$1)/(2*($1+$2+$3)), sqrt(3)*$2/(2*($1+$2+$3))}' VolumeFractions.txt" notitle w p pt 6 ps 2 lw 3 lc rgb "red" 
