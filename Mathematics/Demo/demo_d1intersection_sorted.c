#include "stdio.h"
#include "stdlib.h"
#include "../Mathematics.h"

int main(int argc, char *argv[])
{
  int arr1[]={1, 3,4, 5,7,8};
  int n1=6;
  int arr2[]={5,6, 8,9,10};
  int n2=5;
  
  int arr3[10];
  int n3=0;
  
  /* Run */
  d1sorted_intersection(arr1, n1, arr2, n2, arr3, &n3);
  
  /*check result */
  printf("Expected output: arr3=[ 5 8 ]\n");
  printf("Result:          arr3=[");
  int i;
  for (i=0; i<n3; i++)
    printf("%2d", arr3[i]);
  printf(" ]\n");
  
  if (n3==2){
    if (arr3[0]==5 && arr3[1]==8) {
      printf("Success: d1sorted_intersection() generated the expected outcome.\n");
    } else{
      printf("Error: unexpected array values\n");
    }
  } else {
    printf("Error: unexpected array length.\n");
  }
  
  return(0);
}
