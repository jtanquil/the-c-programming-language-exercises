#include <stdio.h>
#include <stdlib.h>   /* for atoff() */

#define MAXOP 100     /* max size of operator or operand */
#define NUMBER '0'    /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void print(void);
double top(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
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
        printf("\t%.8g\n", pop());
        break;
      /* Exercise 4-4. Add commands to print the top element of the stack without 
      popping it, to duplicate it, and to swap the top two elements. Add a command 
      to clear the stack. */
      case 'p':
        print();
        break;
      case 't':
        printf("returning the top of the stack: %f\n", top());
        break;
      case 's':
        swap();
        break;
      case 'c':
        clear();
        break;
      default:
        printf("error: unknown comman %s\n", s);
        break;
    }
  }
  return 0;
}