/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of 
iota; that is, convert an integer into a string by calling a recursive routine. */

/* 
  given an integer n,
  if it's -2^(wordsize - 1), then return itoa(n + 1) with the ones digit + 1,
  otherwise,
  if it's < 0 note this and switch its sign to positive
  if it's < 10 add the ones digit to the front of the string
  otherwise, shift the string elements by 1 and invoke itoa(n / 10)
  if the noted sign is negative, then shift the string elements and add a negative
*/

#include <stdio.h>
#include <limits.h>

void shift(char s[]) {
  int i;

  for(i = 0; s[i] != '\0'; i++) {
    ;
  }

  for(; i >= 0; i--) {
    s[i + 1] = s[i];
    s[i] = s[i - 1];
  }
}

void itoa(int n, char s[]) {
  int i, sign;

  if (n == INT_MIN) {
    itoa(n + 1, s);

    for (i = 0; s[i] != '\0'; i++) {
      ;
    }

    s[i - 1] = s[i - 1] + ('1' - '0');
  } else {
    sign = (n < 0) ? -1 : 1;
    n = (sign < 0) ? -n : n;

    if (n < 10) {
      ;
    }
  }
}

void main() {
  char s[33] = "                                ";

  itoa(INT_MIN, s);
  printf("%s\n", s);
}