/* Pointer-based version of itoa from ch3 */

#include <stdio.h>
#include <limits.h>

/* shifts i indices of s (*s - i), ..., *(s - 1), *s) to the right by 1 */
void shift(int i, char *s) {
  int j;

  for (j = 0; j < i; j++) {
    *(s + i - j) = *(s + i - j - 1);
  }
}

void itoa(int n, char *s) {
  int i, sign;

  i = 0;

  if (n == INT_MIN) {
    itoa(n + 1, s);

    /* find the ones digit and subtract 1 from it */
    while (*s != '\0') {
      s++;
    } 

    *(s - 1) = *(s - 1) + 1;
  } else {
    n = ((sign = n) < 0) ? -n : n;

    do {
      shift(i++, s);
      *s = n % 10 + '0';
    } while ((n /= 10) > 0);
  }

  if (sign < 0) {
    shift(i++, s);
    *s = '-';
  }

  *(s + i) = '\0';
}

void main () {
  char s[33] = "";

  itoa(-2576, s);
  printf("%s\n", s);

  itoa(INT_MIN, s);
  printf("%s\n", s);

  itoa(INT_MAX, s);
  printf("%s\n", s);
}