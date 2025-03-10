/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to 
use a function for conversion. */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float convert_fahr_to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}

int main() {
  float fahr;

  printf("Fahrenheit Celsius\n");
  for(fahr = LOWER; fahr < UPPER; fahr = fahr + STEP) {
    printf("%10.0f %7.1f\n", fahr, convert_fahr_to_celsius(fahr));
  }

  return 0;
}