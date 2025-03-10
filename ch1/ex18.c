/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each 
line if input, and to delete entirely blank lines. */

/*
while (input isn't eof i.e. line length is 0)
  for each line:
      go through the line
      when encountering end of line '\n':
        go through the string until encountering non-whitespace char
        put \0 after it
      return the line length
  if the line is blank, don't print it
  otherwise, print it
*/

#include <stdio.h>

#define MAXLENGTH 1000
#define BLANKLINE -1      /* used to indicate when an entire line is blank */

int getline_(char line[], int max_line_length);

void main() {
  int current_length;
  char current_line[MAXLENGTH];

  while ((current_length = getline_(current_line, MAXLENGTH)) != 0) {
    if (current_length != BLANKLINE) {
      printf("line: %slength (trailing whitespace removed): %d\n", current_line, current_length);
    } else {
      printf("blank line removed\n");
    }

    /* reset current_line */
    for (int i = 0; i < MAXLENGTH; i++) {
      current_line[i] = '\0';
    }
  }
}

int getline_(char line[], int max_line_length) {
  int c, i;

  for(i = 0; i < max_line_length - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }

  /* remove trailing whitespace before adding newline */
  while(line[i - 1] == ' ' || line[i - 1] == '\t') {
    line[i] = '\0';
    i--;
  }

  if (c == '\n') {
    line[i] = c;
    i++;
  }

  /* if the line is blank, line[0] will be '\n', in this case return -1 */
  if (line[0] == '\n') {
    return BLANKLINE;
  } else {
    line[i] = '\0';
    return i;
  }
}