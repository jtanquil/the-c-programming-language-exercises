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
#include <stdlib.h>
#include <ctype.h>

#define MAX_OPERANDS 100
#define NUMBER 0
#define INVALID_INPUT -1

static double operands[MAX_OPERANDS];
static int next_op_index = 0;

/* stripped down version of getop */
int getop (char *s) {
  /* strip whitespace */
  while (*s == ' ' || *s == '\t') {
    s++;
  }

  if (*s == '-') {
    if (isdigit(*(s + 1))) {
      return NUMBER;
    }
  }

  if 
    (*s == '+' || *s == '-' || *s == '*' || *s == '/') {
      if (*(s + 1) != '\0') {
        return INVALID_INPUT;
      } else {
        return *s;
      }
  } else if (!isdigit(*s)) {
    return *s;
  } else {
    return NUMBER;
  }
}

void main (int argc, char *argv[]) {
  double op1, op2, res;
  char *c;
  
  while (--argc > 0) {
    c = *++argv;

    switch (getop(c)) {
      case NUMBER:
        if (next_op_index >= MAX_OPERANDS) {
          printf("input error: too many operands\n");
        } else {
          operands[next_op_index] = atof(c);
          next_op_index++;
        }
        break;
      case INVALID_INPUT:
        printf("input error: arguments must be numbers or operators (+, -, \'*\', /)\n");
        break;
      case '+':
        res = operands[(next_op_index--) - 1] + operands[(next_op_index--) - 1];
        operands[next_op_index++] = res;
        break;
      case '-':
        op2 = operands[(next_op_index--) - 1];
        op1 = operands[(next_op_index--) - 1];
        operands[next_op_index++] = op1 - op2;
        break;  
      case '*':
        res =  operands[(next_op_index--) - 1] * operands[(next_op_index--) - 1];
        operands[next_op_index++] = res;
        break;
      case '/':
        op2 = operands[(next_op_index--) - 1];
        op1 = operands[(next_op_index--) - 1];
        operands[next_op_index++] = op1 / op2;
        break;
    }    
  }
  printf("The result is: %f\n", operands[next_op_index - 1]);
}