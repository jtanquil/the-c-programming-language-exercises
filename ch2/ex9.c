/* Exercise 2-9. In a two's complement number system, x &= (x - 1) deletes the 
rightmost 1-bit in x. Explain why. Use this observation to write a faster 
version of bitocunt. */

/* If the rightmost bit of x is at position n, then the bits from position 
1, ..., n - 1 are all 0. If x > 0, then x - 1 will have a 0 at position n and 
1s at position 1, ..., n - 1, so x & (x - 1) will flip the 1 at position n of 
x into a 0. If x < 0, in a two's complement system, x will have the same binary 
representation as an unsigned integer m in the range [2^(N - 1), 2^N - 1] where 
N is the number of bits in an integer, and x - 1 will have the same binary 
representation as the integer m - 1. Therefore, x & (x - 1) will still result 
in the rightmost 1 bit of x being flipped. */

#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x &= (x - 1)) {
    b++;
  }

  return b;
}

void main() {
  printf("%d\n", bitcount(0707u)); // 6
  printf("%d\n", bitcount(04375u)); // 8
}