/* Exercise 2-1. Write a program to determine the ranges of char, short, int, 
and long variables, both signed and unsigned, by printing appropriate values 
from standard headers and from direct computation. Harder if you compute them: 
determine the ranges of the various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

void main() {
  printf("The range of an unsigned char is: 0 to %.0f\n", pow(2, CHAR_BIT) - 1);
  printf("The range of a signed char is: %.0f to %.0f\n", 
    -pow(2, CHAR_BIT - 1), pow(2, CHAR_BIT - 1) - 1);

  printf("The range of an unsigned short is: 0 to %.0f\n", pow(2, MB_LEN_MAX) - 1);
  printf("The range of a signed short is: %.0f to %.0f\n", 
    -pow(2, MB_LEN_MAX - 1), pow(2, MB_LEN_MAX - 1) - 1);

  printf("The range of an unsigned int is: 0 to %.0f\n", pow(2, MB_LEN_MAX * 2) - 1);
  printf("The range of a signed int is: %.0f to %.0f\n", 
    -pow(2, MB_LEN_MAX * 2 - 1), pow(2, MB_LEN_MAX * 2 - 1) - 1);

  printf("The range of an unsigned long is: 0 to %.0f\n", pow(2, MB_LEN_MAX * 4) - 1);
  printf("The range of a signed long is: %.0f to %.0f\n", 
    -pow(2, MB_LEN_MAX * 4 - 1), pow(2, MB_LEN_MAX * 4 - 1) - 1);

  printf("The range of a float is: %.10e to %.10e\n", FLT_MIN, FLT_MAX);
  printf("The range of a double is: %.10e to %.10e\n", DBL_MIN, DBL_MAX);
}