/* Pointer-based version of getline from ch1 */

#include <stdio.h>

#define MAXLENGTH 50

int _getline(char *line) {
  int c;
  char *start;

  for (start = line; (line - start) < MAXLENGTH - 1 && (c = getchar()) != EOF && c != '\n'; line++) {
    *line = c;
  }

  if (c == '\n') {
    *line = c;
    line++;
  }

  *line = '\0';
  return (line - start);
}

void main() {
  int current_length;
  char line[MAXLENGTH];

  while ((current_length = _getline(line)) > 0) {
    printf("%s\n", line);
  }
}