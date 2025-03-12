/* Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with the 
n bits that begin at position p set to the rightmost n bits of y, leaving the 
other bits unchanged. */

/* 
  given x and y,
  mask the rightmost p bits of x: x & (~0 << p)
  get the rightmost n bits of y, shifted p - n bits to the left: (y & ~(~0 << n)) << (p - n)
  get the rightmost p - n bits of x: x & ~(~0 << p - n)
  return the inclusive OR of these three values
*/

#include <stdio.h>

unsigned setbits(int x, int p, int n, int y) {
  int left, middle, right;

  left = x & (~0 << p);
  middle = (y & ~(~0 << n)) << (p - n);
  right = x & ~(~0 << (p - n));

  return left | middle | right;
}

void main() {
  int x, p, n, y;
  x = 0707; // 111000111
  y = 067;  // 000110111

  printf("%d\n", setbits(x, 6, 3, y)); // 511 (111111111)
  printf("%d\n", setbits(x, 5, 3, y)); // 479 (111011111)
  printf("%d\n", setbits(x, 9, 4, y)); // 231 (011100111)
}