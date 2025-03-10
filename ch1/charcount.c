#include <stdio.h>

void main() {
  long count;

  for (count = 0; getchar() != EOF; ++count) 
    ; /* null statement needed since for loops require a body in C */
  
  printf("%ld\n", count);
}