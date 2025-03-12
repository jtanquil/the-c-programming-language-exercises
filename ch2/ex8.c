/* Exercise 2-8. Write a function rightrot(x, n) that returns the value of the 
integer x rotated to the right by n bit positions. */

/*
  assuming that x is positive...
  example: rotate 10101 by 1 => 11010, rotate 100000 by 3 => 000100
  assume that n is less than m = floor(log_2 x.) + 1 since rotations are equivalent mod m
  m should also be the number of non-sign bits of x
  a rightward rotation by n bits will swap the rightmost n bits and the leftmost m - n bits:

  given an integer x,
    mask all but the n rightmost bits and shift m - n bits to the left
    mask the n rightmost bits and shift n bits to the right

    return the OR of the two
*/

#include <stdio.h>

/* masks the p rightmost bits of x */
unsigned maskright(int x, int p) {
  return x & (~0 << p);
}

/* masks everything but the p rightmost digits of x */
unsigned maskleft(int x, int p) {
  return x & ~(~0 << p);
}

/* find number of bits needed to represent a positive integer x */
int numbits(int x) {
  int bits = 0, product = 1;

  for (; x > product; bits++) {
    product = 2 * product;
  }

  return bits;
}

unsigned rightrot(int x, int n) {
  int m = numbits(x);
  int left = maskleft(x, n) << m - n;
  int right = maskright(x, n) >> n;
  return left | right;
}

void main() {
  printf("%d\n", rightrot(025 /* 10101 */, 1));   // 26 (11010)
  printf("%d\n", rightrot(040 /* 100000 */, 3));  // 4 (000100)
}