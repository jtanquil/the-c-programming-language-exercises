/* Pointer-based version of getop, getch, ungetch from ch4 */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define NUMBER 0

char buf[BUFSIZE];
int bufp = 0;

int getch (void) {
  return (bufp > 0) ? *(buf + --bufp) : getchar();
}

void ungetch (int c) {
  if (bufp > BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    *(buf + bufp++) = c;
  }
}

int getop (char *s) {
  int i, c;

  while ((*s = c = getch()) == ' ' || c == '\t') {
    ;
  }

  *(s + 1) = '\0';

  i = 0;

  if (c == '-') {
    int nextchar = getch();

    if (isdigit(nextchar)) {
      ungetch(nextchar);
      *s = c;

      while (isdigit(*(++s) = c = getch()))
        ;

      if (c == '.') {
        while (isdigit(*(++s) = c = getch()))
          ;
      }

      *s = '\0';

      if (c != EOF)
        ungetch(c);

      return NUMBER;
    }
  } else if (!isdigit(c) && c != '.') {
    return c;
  }
  
  if (isdigit(c))
    while (isdigit(*(++s) = c = getch()))
      ;
  
  if (c == '.')
    while (isdigit(*(++s) = c = getch()))
      ;

  *s = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

void main() {
  char s[30];

  while (getop(s) != EOF) {
    printf("%s\n", s);
  }
}