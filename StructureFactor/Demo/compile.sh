#!/bin/bash

pth="../.."
MainC="Demo_StructureFactorAndCorrelationFunction.c"
executable="StructureFactorAndCorrelationFunction"

gcc -o $executable $MainC $pth/Fourier/Fourier.c $pth/Mathematics/Mathematics.c $pth/ReadTextFiles/ReadTextFiles.c $pth/StringOperations/StringOperations.c $pth/StructureFactor/StructureFactor.c -lm


