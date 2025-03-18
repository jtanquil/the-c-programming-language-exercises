/* Exercise 4-6. Add commands for handling variables. Add a variable 
for the most recently printed value. */
      
#include <stdio.h>

#define NUM_VARS 26       /* number of possible stored variables */

double vars[NUM_VARS];    /* array that stores variables */
int used_vars[NUM_VARS];  /* array that tracks which variables are used */
double last;              /* special variable that tracks the most recently
                             printed value */

int get_index(int varname) {
  return varname - 'a';
}

/* assign: assigns a value to the variable */
void assign(double val, int index) {
  if (index >= 0 && index < NUM_VARS) {
    vars[index] = val;
    used_vars[index] = 1;
  } else {
    printf("out of bounds error\n");
  }
}

/* get: gets the value from the given variable */
double get(int index) {
  if (used_vars[index]) {
    return vars[index];
  } else {
    printf("variable %c currently not being used\n", index + 'a');
  }
}

/* get_last: returns the value of last */
double get_last(void) {
  return last;
}

/* assign_last: assigns a value to last */
void assign_last(double val) {
  last = val;
}
