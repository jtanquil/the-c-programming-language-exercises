/* Exercise 1-13. Write a program to print a histogram of the lengths of words 
in its input. It is easy to draw the histogram with the bars horizontal; a 
vertical orientation is more challenging. */

#include <stdio.h>

#define MAX_LENGTH 15     /* max word length */

void main() {
  int c, current_word_length;
  int word_lengths[MAX_LENGTH];

  current_word_length = 0;

  for (int i = 0; i < MAX_LENGTH; i++) {
    word_lengths[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (current_word_length > 0 && current_word_length <= MAX_LENGTH) {
        word_lengths[current_word_length - 1]++;
      }

      current_word_length = 0;
    } else {
      current_word_length++;
    }
  }

  /* add the last word */
  if (current_word_length > 0 && current_word_length <= MAX_LENGTH) {
    word_lengths[current_word_length - 1]++;
  }

  printf("word_length count\n");
  for (int i = 0; i < MAX_LENGTH; i++) {
    printf("%11d ", i + 1);

    for(int j = 0; j < word_lengths[i]; j++) {
      printf("|");
    }

    printf("\n");
  }
}