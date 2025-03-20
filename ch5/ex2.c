/* Exercise 5-2. Write getfloat, the floating-point analog of getint. What type
   does getfloat return as its function value? */

/* getfloat still returns an int as its return value, to indicate whether it
   read in a valid float, or a non-float, from the input; it writes the floats 
   that it reads into an array of doubles via its parameter double *pf */

/* valid floating point representations: (+/-)(digits).(digits)(e/E)(integer) */

#include <stdio.h>
#include <ctype.h>
#include "buffer.c"

int getch(void);
void ungetch(int);

int getfloat(double *pf) {
  int c, sign, expsign, exp;

  /* skip white space */
  while (isspace(c = getch())) {
    ;
  }

  /* skip non-numbers */
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  /* read the sign */
  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') {
    c = getch();

    /* sign followed by a non-digit is also not a number */
    if (!isdigit(c)) {
      ungetch(c);
      return 0;
    }
  }

  /* read digits to the left of the decimal */
  for (*pf = 0; isdigit(c); c = getch()) {
    *pf = 10 * *pf + (c - '0');
  }

  /* check for a decimal */
  if (c == '.') {
    c = getch();

    /* decimal must be followed by numbers to be valid*/
    if (!isdigit(c)) {
      ungetch(c);
      return 1;
    } else {
      double k = 1;

      /* read digits to the right of the decimal */
      for (; isdigit(c); c = getch()) {
        k *= 10;
        *pf += (c - '0') / k;
      }
    }
  }

  /* multiply by the sign */
  *pf *= sign;

  /* check for exponent */
  if (c != 'e' && c != 'E') {
    ungetch(c);
    return 1;
  } else {
    c = getch();
  }

  /* read the exponent */
  if (c != '+' && c != '-') {
    ungetch(c);
    return 1;
  } else {
    expsign = (c == '-') ? -1 : 1;
    c = getch();
  }

  if (!isdigit(c)) {
    ungetch(c);
    return 1;
  }

  for (expsign = 0; isdigit(c); c = getch()) {
    expsign = 10 * expsign + (c - '0');
  }

  for (int k = 0; k < expsign; k++) {
    if (sign < 0) {
      *pf /= 10;
    } else {
      *pf *= 10;
    }
  }

  if (c != EOF) {
    ungetch(c);
  }

  return c;
}

void main() {
  int n;
  double array[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

  for (n = 0; n < 10 && getfloat(&array[n]) != EOF; n++) {
    ;
  }

  printf("---\n");

  for (n = 0; n < 10; n++) {
    printf("%g\n", array[n]);
  }
}