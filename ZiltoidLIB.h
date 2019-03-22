#ifndef ZiltoidLIB_LOADED
  #define ZiltoidLIB_LOADED 1

  #include <stdio.h>
  #include <stdlib.h>

  #include <string.h> // used by ReadTextFiles
  #include <math.h>

  #ifndef MAX_LINE_WIDTH
    #define MAX_LINE_WIDTH 25000
  #endif
  #ifndef MAX_STR_L
    #define  MAX_STR_L 200
  #endif

  #include "kMC/VSSM.h"
  #include "Mathematics/Mathematics.h"
  #include "LatticeLIB/LatticeLIB.h"
  #include "NumericalMethods/NumericalMethods.h"
  #include "ReadTextFiles/ReadTextFiles.h"
  #include "StringOperations/StringOperations.h"

  #include "Applications/StructureFactor/StructureFactor.h"
  #include "Applications/PrincipleMomentsOfInertia/PrincipleMomentsOfInertia.h"
#endif
