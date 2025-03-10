/* Exercise 1-17. Write a program to print all input lines that are longer 
than 80 characters. */

/*
while (char isn't EOF)
  get the line

  if (line is longer than 80 characters)
    print the line
*/

#include <stdio.h>

#define MIN_LINE_LENGTH 80    /* minimum line length to be printed */
#define MAXLENGTH 1000        /* maximum line length */

int getline_(char line[], int max_line_length);

void main() {
  int current_length;
  char current_line[MAXLENGTH];

  while ((current_length = getline_(current_line, MAXLENGTH)) > 0) {
    if (current_length > MIN_LINE_LENGTH) {
      printf("%s\n", current_line);

      /* after printing the current line, reset the elements of current_line */
      for (int i = 0; i < MAXLENGTH; i++) {
        current_line[i] = '\0';
      }
    }
  }
}

int getline_(char line[], int max_line_length) {
  int c, i;

  for (i = 0; i < max_line_length - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = '\n';
    i++;
  }

  line[i] = '\0';
  return i;
}