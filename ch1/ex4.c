/* Exercise 1-4. Write a program to print the corresponding Celsius to 
Fahrenheit table. */

#include <stdio.h>

void main() {
  float celsius, fahr;
  int upper, lower, step;

  lower = -40;
  upper = 100;
  step = 4;

  celsius = lower;

  printf("Celsius Fahrenheit\n");

  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%7.0f %10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}