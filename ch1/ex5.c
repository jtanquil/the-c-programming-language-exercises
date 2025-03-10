/* Exercise 1.5. Modify the temperature conversion program to print the table 
in reverse order, that is, from 300 degrees to 0. */

/* Including symbolic constants */

#include <stdio.h>

#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit of table */
#define STEP 20     /* step size */

void main() {
  int fahr;

  printf("Fahrenheit Celsius\n");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    printf("%10d %7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}