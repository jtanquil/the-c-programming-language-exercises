/* Pointer-baesd version of reverse from ch3 */

#include <stdio.h>

void reverse(char *s) {
  int i, j, temp;

  i = 0;

  while (*(s + i) != '\0') {
    i++;
  }

  for (j = 0; j <= (i - 1) / 2; j++) {
    temp = *(s + j);
    *(s + j) = *(s + i - 1 - j);
    *(s + i - 1 - j) = temp;
  }
}

void main() {
  char s[12] = "hello world";
  char t[] = "racecar";
  char u[] = "";

  reverse(s);
  printf("%s\n", s);

  reverse(t);
  printf("%s\n", t);

  reverse(u);
  printf("%s\n", u);
}