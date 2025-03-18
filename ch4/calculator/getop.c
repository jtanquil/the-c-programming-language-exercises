#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }

  s[1] = '\0';

  /* Exercise 4-3. Given the basic framework, it's straightforward to 
  extend the calculator. Add the modulus (%) operator and provisions for 
  negative numbers. */
  /* to handle negative numbers:
      if c is the minus sign, check the next character
      if it's a number, start reading a negative number into s
      otherwise, treat c as the operator, check for other signs
  */
  i = 0;

  if (c == '-') {
    int nextchar = getch();

    if (isdigit(nextchar)) {
      ungetch(nextchar);
      s[i] = c;

      while (isdigit(s[++i] = c = getch()))
        ;
      
      if (c == '.')
        while (isdigit(s[++i] = c = getch()))
          ;

      s[i] = '\0';

      if (c != EOF)
        ungetch(c);
      
      return NUMBER;
    }
  } else if (!isdigit(c) && c != '.') {
    return c;     /* not a number */
  }
  
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')   /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}