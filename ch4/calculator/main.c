#include <stdio.h>
#include <stdlib.h>   /* for atoff() */
#include <math.h>     /* for sin, exp, pow, etc */

#define MAXOP 100     /* max size of operator or operand */
#define NUMBER '0'    /* signal that a number was found */

enum { NOT_VAR, IS_VAR };
enum { NO_ASSIGNMENT, ASSIGNMENT };

int getop(char []);

void push(double, int);
double pop(int);
int get_index(int);

void assign(double, int);
double get(int);
double get_last(void);
void assign_last(double);

// void print(void);
// double top(void);
// void swap(void);
// void clear(void);
int top_var(void);

/* reverse Polish calculator */
int main() {
  int type, op1var, op2var;
  double op1, op2, result;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s), NOT_VAR);
        break;
      case '+':
        push(pop(NO_ASSIGNMENT) + pop(NO_ASSIGNMENT), NOT_VAR);
        break;
      case '*':
        push(pop(NO_ASSIGNMENT) * pop(NO_ASSIGNMENT), NOT_VAR);
        break;
      case '-':
        op2 = pop(NO_ASSIGNMENT);
        push(pop(NO_ASSIGNMENT) - op2, NOT_VAR);
        break;
      case '/':
        op2 = pop(NO_ASSIGNMENT);
        if (op2 != 0.0)
          push(pop(NO_ASSIGNMENT) / op2, NOT_VAR);
        else
          printf("error: zero divisor\n");
        break;
      /* Exercise 4-3. Given the basic framework, it's straightforward to 
      extend the calculator. Add the modulus (%) operator and provisions for 
      negative numbers. */
      case '%':
        op2 = pop(NO_ASSIGNMENT);
        if (op2 != 0.0)
          push((int) pop(NO_ASSIGNMENT) % (int) op2, NOT_VAR);
        else
          printf("error: zero modulus\n");
        break;
      case '\n':
        result = pop(NO_ASSIGNMENT);
        printf("\t%.8g\n", result);
        assign_last(result);
        break;
      /* Exercise 4-4. Add commands to print the top element of the stack without 
      popping it, to duplicate it, and to swap the top two elements. Add a command 
      to clear the stack. */
      /* commented out to use other ops/variables */
      // case 'p':
      //   print();
      //   break;
      // case 't':
      //   printf("returning the top of the stack: %f\n", top());
      //   break;
      // case 's':
      //   swap();
      //   break;
      // case 'c':
      //   clear();
      //   break;
      /* Exercise 4-5. Add access to library functions like sin, exp and pow. */
      case 'S':
        push(sin(pop(NO_ASSIGNMENT)), NOT_VAR);
        break;
      case 'C':
        push(cos(pop(NO_ASSIGNMENT)), NOT_VAR);
        break;
      case 'T':
        push(tan(pop(NO_ASSIGNMENT)), NOT_VAR);
        break;
      case 'E':
        push(exp(pop(NO_ASSIGNMENT)), NOT_VAR);
        break;
      case 'P':
        op2 = pop(NO_ASSIGNMENT);
        op1 = pop(NO_ASSIGNMENT);
        if ((op1 == 0 && op2 <= 0) || (op1 < 0 && rintf(op2) != op2)) {
          printf("error: domain error\n");
        } else {
          push(pow(op1, op2), NOT_VAR);
        }
        break;
      /* Exercise 4-6. Add commands for handling variables. Add a variable 
      for the most recently printed value. */
      /* call the most recently printed value x
         reading a value into x: (x 2 =, x y =)
          assign the right value into the left value, return right value
         using x in an expression: (x S, x 2 +, 2 x +)
          if an operator is the top character and x is read, then use the
          stored value of x */
      case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
      case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
      case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
      case 'v': case 'w': case 'x': case 'y': case 'z':
        push(get_index(type), IS_VAR);
        break;
      case '=':
        op2var = top_var();
        op2 = pop(NO_ASSIGNMENT);

        op1var = top_var();
        op1 = pop(ASSIGNMENT);

        if (!op1var) {
          printf("error: must assign to a variable\n");
          break;
        }

        if (op2var) {
          assign(get(op2), op1);
          push(get(op2), NOT_VAR);
        } else if (op2 == 'L') {
          assign(get_last(), op1);
          push(get_last(), NOT_VAR);
        } else {
          assign(op2, op1);
          push(op2, NOT_VAR);
        }
        break;
      case 'L':
        push(get_last(), NOT_VAR);
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}