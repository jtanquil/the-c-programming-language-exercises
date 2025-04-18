#include <stdio.h>

/* count digits using an array, white space, other characters */
void main() {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; i++) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') { /* works since '0', ... '9' are ascending */
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("digits =");
  for (i = 0; i < 10; i++) {
    printf(" %d", ndigit[i]);
  }
  printf(", white space = %d, other = %d\n", nwhite, nother);
}