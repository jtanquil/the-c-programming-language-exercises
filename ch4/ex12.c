/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of 
iota; that is, convert an integer into a string by calling a recursive routine. */

/* 
  given an integer n,
  if it's -2^(wordsize - 1), then return itoa(n + 1) with the ones digit + 1,
  otherwise,
  if it's < 0 note this and switch its sign to positive

  if n >= 10, then call itoa(n / 10)

  otherwise, set the last element of s to n % 10 
  then add '\0' to the end (this is the new last element) 
  if n < 0, shift the elements of s and add a -
*/

#include <stdio.h>
#include <limits.h>

/* shifts the characters of s one space forward
   assumes that the length of s is >= 1 more than the number of characters in s
*/
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

    if (n >= 10) {
      itoa(n / 10, s);
    }

    for(i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
      ;
    }

    s[i++] = (n % 10) + '0';
    s[i] = '\0';

    if (sign < 0) {
      shift(s);
      s[0] = '-';
    }
  }
}

void main() {
  char s[30], t[30], u[30], v[30];

  itoa(INT_MIN, s);
  printf("%s\n", s);

  itoa(INT_MAX, t);
  printf("%s\n", t);

  itoa(0, u);
  printf("%s\n", u);

  itoa(-4416, v);
  printf("%s\n", v);
}