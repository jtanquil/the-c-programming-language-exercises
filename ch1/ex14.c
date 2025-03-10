/* Exercise 1-14. Write a program to print a histogram of the frequencies of 
different characters in its input. */

#include <stdio.h>

#define CHARACTER_ARRAY_LENGTH 128 /* corresponds to ASCII values */

void main() {
  int c;
  int character_counts[CHARACTER_ARRAY_LENGTH];

  while ((c = getchar()) != EOF) {
    character_counts[c]++;
  }

  printf("character character_count\n");
  for (int i = 0; i < CHARACTER_ARRAY_LENGTH; i++) {
    printf("         ");
    putchar(i);
    printf(" ");

    for (int j = 0; j < character_counts[i]; j++) {
      printf("|");
    }

    printf("\n");
  }
}