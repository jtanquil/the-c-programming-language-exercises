#include <stdio.h>

#define MAXVAL 5    /* maximum depth of val stack */

int sp = 0;           /* next free stack position */
double val[MAXVAL];   /* value stack */

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
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
  
  if (sp > 1) {
    printf("swapping %f at index %d and %f at index %d\n", val[sp - 1], sp - 1, val[sp - 2], sp - 2);
    temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;
  } else {
    printf("error: not enough elements in the stack\n");
  }
}

/* clear: clears the stack */
void clear(void) {
  printf("clearing the stack\n");
  sp = 0;
}