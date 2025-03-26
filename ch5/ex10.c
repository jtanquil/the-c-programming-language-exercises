/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish 
   expression with the command line, where each operator or operand is a 
   separate argument. For example,
   
   expr 2 3 4 + *
   
   evalautes 2 * (3 + 4). */

/*
  store operands in a float array
  read the elements of argv:
  if it's a number, push it into the array
  if it's an operator,
  pop the last two elements of the array, 
  perform the operation,
  push the result back into the operand array
*/

#include <stdio.h>
#include <ctype.h>
#include <errno.h>

#define MAX_OPERANDS 100
#define NUMBER 0

double atof(char *s);

static double operands[MAX_OPERANDS];
static int next_op_index = 0;

/* stripped down version of getop */
int getop (char *s, double *d) {
  /* strip whitespace */
  while (*s == ' ' || *s == '\t') {
    s++;
  }

  if (*s == '-') {
    if (isdigit(*(s + 1))) {
      d = atof(s);
      return NUMBER;
    } else {
      return *s;
    }
  }
}

void main (int argc, char *argv[]) {
  double number;
  char *c;

  while (--argc > 0) {
    errno = 0;
    c = *++argv;
    number = atof(c);

    if (errno != 0) {
      printf("input error: input is not numeric\n");
    } else if (next_op_index >= MAX_OPERANDS) {
      printf("input error: too many operands\n");
    } else {
      operands[next_op_index] = number;
      next_op_index++;
    }
  }
}