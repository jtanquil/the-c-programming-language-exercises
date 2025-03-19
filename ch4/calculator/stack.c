#include <stdio.h>
#include "calc.h"

#define MAXVAL 100    /* maximum depth of val stack */

static int sp = 0;           /* next free stack position */
static double val[MAXVAL];   /* value stack */
static int isvar[MAXVAL];    /* stack indicating whether the corresponding element of
                         val[] represents a variable */

int get_index(int);
double get(int);

/* push: push f onto value stack, and whether or not it represents a variable
         onto the isvar stack */
void push(double f, int representsvar) {
  if (sp < MAXVAL) {
    val[sp] = f;
    isvar[sp] = representsvar;
    sp++;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/* pop: pop and return top value from stack if the corresponding value doesn't
   represent a variable, and the value of the variable if it is */
double pop(int poptype) {
  if (sp > 0)
    if (isvar[--sp] == NOT_VAR) {
      return val[sp];
    } else if (isvar[sp] == IS_VAR) {
      if (poptype == NO_ASSIGNMENT) {
        return get(val[sp]);
      } else {
        return val[sp];
      }
    } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* Exercise 4-4. Add commands to print the top element of the stack without 
popping it, to duplicate it, and to swap the top two elements. Add a command 
to clear the stack. */

/* print: print the top of the stack */
void print(void) {
  if (sp > 0) {
    printf("%f\n", val[sp - 1]);
  } else {
    printf("error: stack empty\n");
  }
}

/* top: retrieves a copy of the top element without popping it */
double top(void) {
  if (sp > 0) {
    return val[sp - 1];
  } else {
    printf("error: stack empty\n");
  }
}

/* swap: swaps the top two elements of the stack */
void swap(void) {
  double temp;
  int tempvar;
  
  if (sp > 1) {
    temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;

    tempvar = isvar[sp - 1];
    isvar[sp - 1] = isvar[sp - 2];
    isvar[sp - 2] = tempvar;
  } else {
    printf("error: not enough elements in the stack\n");
  }
}

/* clear: clears the stack */
void clear(void) {
  printf("clearing the stack\n");
  sp = 0;
}

/* top_var: returns the end of the variable indicator stack isvar */
int top_var(void) {
  return isvar[sp - 1];
}