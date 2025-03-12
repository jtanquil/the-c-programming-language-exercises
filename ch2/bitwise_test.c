/* Testing the behavior of bitwise operators. */

#include <stdio.h>

void main() {
  int n = 255;                // 0.....11111111 as a signed integer

  printf("%d\n", n & 06);      // 6 (11111111 & 00000110)
  printf("%d\n", n | 0400);    // 511 (11111111 | 100000000)
  printf("%d\n", n ^ 01);      // 254 (11111111 ^ 00000001)
  printf("%d\n", n << 2);     // 1020 (shifts to 1111111100)
  printf("%d\n", n >> 2);     // 63 (shifts to 111111)
  printf("%d\n", ~n + 1);     // -255 (shifts to 1111...00000001 due to twos complement representation)
}