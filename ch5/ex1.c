#include <stdio.h>
#include <ctype.h>
#include "buffer.c"

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint (int *pn) {
  int c, sign;

  /* skip white space */
  while (isspace(c = getch())) {
    ;
  }

  /* it's not a number or a sign */
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') {
    c = getch();

    /* Exercise 5-1. As written, getint treats a + or - not followed by a digit 
       as a valid representation of zero. Fix it to push a character back on the 
       input. */
    if (!isdigit(c)) {
      ungetch(c);
      return 0;
    }
  }

  /* get digits from input */
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + (c - '0');
  }

  *pn *= sign;

  if (c != EOF) {
    ungetch(c);
  }

  return c;
}

void main() {
  int n, array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (n = 0; n < 10 && getint(&array[n]) != EOF; n++) {
    ;
  }

  printf("---\n");

  for (n = 0; n < 10; n++) {
    printf("%d\n", array[n]);
  }
}