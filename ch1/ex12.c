/* Exercise 1-12. Write a program that prints its inputs one word per line. */

#include <stdio.h>

void main() {
  int c, state;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      printf("\n");
    } else {
      putchar(c);
    }
  }
}