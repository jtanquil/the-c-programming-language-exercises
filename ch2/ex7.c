/* Exercise 2-7. Write a function invert(x, p, n) that returns x with the n 
bits that begin at position p inverted (i.e. 1 changed into a 0 and vice 
versa), leaving the others unchanged. */

/*
given an integer x,
  get x with the p rightmost bits masked: 
    x & (~0 << p)
  invert x, then mask everything to the left of p and right of p - n: 
    ~x & (~0 << (p - n)) & ~(~0 << p))
  mask everything but the p - n rightmost bits of x: 
    x & ~(~0 << (p - n))

  return the inclusive OR of these
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

/* inverts the bits of x from p -> (p - n) */
unsigned invert(int x, int p, int n) {
  int left, right, middle;

  left = maskright(x, p);
  middle = maskright(maskleft(~x, p), p - n);
  right = maskleft(x, p - n);

  return left | middle | right;
}

void main() {
  int x = 0707;     // 111000111
  int y = 07;       // 111

  printf("%d\n", invert(x, 6, 3)); // 511 (111111111)
  printf("%d\n", invert(y, 3, 3)); // 0 (000)
}