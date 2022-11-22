# LICENSE  
This software part of ZiltoidLIB (https://github.com/CharleySchaefer/ZiltoidLIB) and is freely distributed under the Apache 2.0 (Version 2.0, January 2004) license WITHOUT WARRANTY, see LICENSE.txt.  

# DEPENDENCIES  
 * gnuplot  
 * LaTeX (for eps to pdf conversion)  
 * Arial font  
 * running unix commands (bash/shell script). Some packages are available for windows to do this (putty, cygwin, bash for windows, etc.)

# USAGE
  1. Data must be stored in VolumeFractions.txt  
  2. An .eps figure is be generated by the command  
    
      `gnuplot plot_PhaseDiagram.plt`  
        
  3. The .eps figure is converted to .pdf using latex by the command  
    
      `pdflatex Eps2PDF.tex`  
        
  4. Steps 2 & 3 + deleting rubbish files are combined by the command  
    
      `./mkfig.sh`
