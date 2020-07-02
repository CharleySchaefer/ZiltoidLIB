#include "stdio.h"
#include "stdlib.h"
#include "../erfinv.h"
#include "../../../ZiltoidLIB.h" 
// compile: gcc main.c ../erfinv.c -lm
int main()
{
  int i;
  double p, y;
  for(i=-101; i<=101; i++) {
    p=i*0.01;
    y=(double)erfinv((long double)p);
    printf("%f %f\n", p, y);
  }

  return(0);
}
