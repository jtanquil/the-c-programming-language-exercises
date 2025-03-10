/* Exercise 1-9. Write a progrma to copy its input to its output, replacing 
each string of one or more blanks by a single blank. */

#include <stdio.h>

#define IN 1     /* currently in a sequence of blanks */
#define OUT 0    /* not in a sequence of blanks */

void main() {
  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      state = IN;
    } else if (state == IN) {
      state = OUT;
      printf(" ");
    }

    if (c != ' ') {
      putchar(c);
    }
  }
}