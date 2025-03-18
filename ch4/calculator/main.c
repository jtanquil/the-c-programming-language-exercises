#include <stdio.h>
#include <stdlib.h>   /* for atoff() */
#include <math.h>     /* for sin, exp, pow, etc */

#define MAXOP 100     /* max size of operator or operand */
#define NUMBER '0'    /* signal that a number was found */

int getop(char []);

void push(double);
double pop(void);
int get_index(int);

void assign(double, int);
double get(int);
double get_last(void);
void assign_last(double);

// void print(void);
// double top(void);
// void swap(void);
// void clear(void);

/* reverse Polish calculator */
int main() {
  int type;
  double op1, op2, result;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      /* Exercise 4-3. Given the basic framework, it's straightforward to 
      extend the calculator. Add the modulus (%) operator and provisions for 
      negative numbers. */
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int) pop() % (int) op2);
        else
          printf("error: zero modulus\n");
        break;
      case '\n':
        result = pop();
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
        push(sin(pop()));
        break;
      case 'C':
        push(cos(pop()));
        break;
      case 'T':
        push(tan(pop()));
        break;
      case 'E':
        push(exp(pop()));
        break;
      case 'P':
        op2 = pop();
        op1 = pop();
        if ((op1 == 0 && op2 <= 0) || (op1 < 0 && rintf(op2) != op2)) {
          printf("error: domain error\n");
        } else {
          push(pow(op1, op2));
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
        push(get_index(type));
        break;
      case '=':
        op2 = pop();
        op1 = pop();
        printf("%g %g\n", op1, op2);
        if (op1 < 0 || op1 > 'z' - 'a') {
          printf("error: must assign to a variable\n");
          break;
        }

        if (op2 >= 'a' && op2 <= 'z') {
          assign(get(op2), op1);
          push(get(op2));
        } else if (op2 == 'L') {
          assign(get_last(), op1);
          push(get_last());
        } else {
          assign(op2, op1);
          push(op2);
        }
        break;
      case 'L':
        push(get_last());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}