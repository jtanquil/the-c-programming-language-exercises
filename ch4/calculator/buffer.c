#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

static char buf[BUFSIZE];    /* buffer for ungetch */
static int bufp = 0;         /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {      
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) { 
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

/* Exercise 4-7. Write a routine ungets(s) that will push back an entire 
   string onto the input. Should ungets known about buf and bufp, or should it
   just use ungetch? */
/* ungets(s) can push an entire string onto the input by pushing one character
   onto it at a time with ungetch(s), so a naive implementation wouldn't need 
   to know about buf or bufp; that would become necessary when implementing 
   error handling in situations such as attemtping to push a string that is 
   longer than the number of spots left on the buffer - ungetch doesn't know
   the length of the string passed to ungets so ungets would need to check
   bufp to handle this case. */
/* pushes a string s onto the input */
void ungets(char s[]) {
  int i;

  /* if s is too long for the remaining buffer, don't push it */
  if (strlen(s) + bufp >= BUFSIZE) {
    printf("ungets: too many characters\n");
  } else {
    for(i = 0; s[i] != '\0'; i++) {
      ungetch(s[i]);
    }
  }
}