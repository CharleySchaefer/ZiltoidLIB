#!/bin/bash
# You must change your typesetting engine to, e.g., "xelatex" or
#! "lualatex"instead of "latex" or "pdflatex".

if [ 0 -eq 1  ] ; then
  rm create_standalone.pdf
  gnuplot GNUfig_standalone.plt
  latex figure.tex


  dvips figure.dvi -o figure.ps
  mv figure.ps figure.eps

  epslatex create_standalone.tex
  mv figure.eps Fig_PhaseDiagram.eps

  rm *.aux *.log  *.dvi *.log create_standalone.pdf create_standalone.out   figure-inc.eps figure.tex

else
  gnuplot plot_PhaseDiagram.plt
  pdflatex Eps2PDF.tex
 # mv test.eps Fig_PhaseDiagram.eps
  rm *.aux *.log Eps2PDF.pdf
  mv PhaseDiagram-eps-converted-to.pdf  PhaseDiagram.pdf
fi
