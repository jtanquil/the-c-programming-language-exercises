/* Exercise 1-8. Write a program to count blanks, tabs and newlines. */

#include <stdio.h>

void main() {
  int c, count;

  count = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ')
      count++;
  }

  printf("%d\n", count);
}