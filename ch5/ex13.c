/* Exercise 5-13. Write the program tail, which prints the last n lines of its
  input. By default, n is 10, let us ssay, but it can be changed by an optional
  argument, so that tail -n prints the last n lines. The program should behave
  rationally no matter how unreasonable the input or the value of n. Write the
  program so it makes the best use of available storage; lines should be stored
  as in the sorting program of Section 5.6, not in a two-dimensional array of
  fixed size.  */

/*
  tail -n

  output: given lines input1 input2 ... inputm, print

  inputm
  input(m - 1)
  ...
  input(m - n + 1)

  store the input in a character ptr with a max size (say 10000)
  therefore n must be <= 10000 as well
  also define an array of character pointers with the same max size

  while input is != EOF
    check if the character ptr has too many lines
      if not, read a line (until hitting \n)
      add the address of the line (where the line begins) to the array
      increment line counter by 1 and the ptr address by the length of the line

  print the last n lines of the input (or until the 1st line, whichever comes first)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINELENGTH 10000
#define MAXLINES MAXLINELENGTH

int _getline(char *, int);
int atoi(char *s);

void main(int argc, char *argv[]) {
  int nlines, len, str_index, n;
  char s[MAXLINELENGTH];
  char line[MAXLINELENGTH];
  char *lineptr[MAXLINES];

  nlines = 0;
  str_index = 0;

  if (argc > 1 && argv[1][0] == '-' && isdigit(argv[1][1])) {
    n = atoi(argv[1] + 1);
  } else {
    if (argc > 1) {
      printf("usage: tail -n\n");
      printf("-n sets the number of lines from the tail to be read (optional, 10 by default)\n");
      printf("setting n to 10.\n");
    }

    n = 10;
  } 

  while((len = _getline(line, MAXLINELENGTH)) > 0) {
    if (nlines >= MAXLINES || str_index >= MAXLINELENGTH) {
      break;
    } else {
      line[len - 1] = '\0';
      strcpy(s + str_index, line);
      lineptr[nlines++] = s + str_index;
      str_index += len;
    }
  }
  
  printf("output:\n");

  for (int i = 1; i <= n && nlines - i > 0; i++) {
    printf("%s\n", lineptr[nlines - i]);
  }
}

int _getline (char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  } if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}