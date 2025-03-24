/* Pointer-baesd version of atoi from ch 2 */

#include <stdio.h>

int atoi (char *s) {
  int sign = 1, n = 0;

  if (*s == '-') {
    sign = -1;
    s++;
  }

  for (; *s >= '0' && *s <= '9'; s++) {
    n = 10 * n + (*s - '0');
  }

  return n * sign;
}

void main () {
  char s[] = "256";
  char t[] = "-935434424";

  printf("%d\n", atoi(s));
  printf("%d\n", atoi(t));
}