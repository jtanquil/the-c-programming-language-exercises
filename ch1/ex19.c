/* Exercise 1-19. Write a function reverse(s) that reverses the character 
string s. Use it to write a program that reverses its input one line at a 
time. */

/*
  given a string s, of length l (>= 2)
  at index i, swap s[i] and s[l - 2 - i] (leave \0 alone)
*/

#include <stdio.h>

#define MAXLENGTH 1000

int getline_(char line[], int max_line_length);
void reverses(char s[]);

void main() {
  int current_length;
  char current_line[MAXLENGTH];

  while ((current_length = getline_(current_line, MAXLENGTH)) > 0) {
    reverses(current_line);

    printf("%s", current_line);

    for (int i = 0; i < MAXLENGTH; i++) {
      current_line[i] = '\0';
    }
  } 
}

int getline_(char line[], int max_line_length) {
  int c, i;

  for (i = 0; i < max_line_length - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    i++;
  }

  line[i] = '\0';
  return i;
}

void reverses(char s[]) {
  int i, j, line_length;
  line_length = 0;

  /* first find the \n char */
  for (i = 0; i < MAXLENGTH; i++) {
    if (s[i] == '\n') {
      line_length = i;
      break;
    }
  }

  /* then reverse the characters of the string, leaving the \0 alone */
  for (i = 0; i <= (line_length - 1) / 2 ; i++) {
    j = s[i];
    s[i] = s[line_length - 1 - i];
    s[line_length - 1 - i] = j;
  }
}
