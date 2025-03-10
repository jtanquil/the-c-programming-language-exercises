/* Exercise 1-16. Revise the main routine of the longest-line progra, so it 
will correctly print the length of arbitrarily long input lines, and as much 
as possible of the text. */

#include <stdio.h>

#define MAXLINE 1000      /* max input line size */

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;                /* current line length */
  int max;                /* max length currently seen */
  char line[MAXLINE];     /* current line */
  char longest[MAXLINE];  /* longest line saved here */

  max = 0;
  while ((len = getline_(line, MAXLINE)) > 0) { /* getline passed ptr to line */
    if (len > max) {
      max = len;
      copy(longest, line); /* copy passed ptrs to longest and line */
    }
  }

  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

/* getline_: reads a line into s, returns its length */
int getline_(char s[], int lim) {
  int c, i;

  /* read characters from input into s until EOF or newline */
  for (i = 0; /* i < lim - 1 && */ (c = getchar()) != EOF && c != '\n'; i++) {
    if (i < MAXLINE - 1) {
      s[i] = c;
    }
  }

  /* add to char length for newline */
  if (c == '\n') {
    s[i] = c;
    i++;
  }

  /* add EOF as the last character */
  if (i < MAXLINE - 1) {
    s[i] = '\0';
  } else {
    s[MAXLINE - 1] = '\0';
  }

  return i;
}

/* copy: copies from into to, assuming to is large enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;

  while((to[i] = from[i]) != '\0') {
    i++;
  }
}