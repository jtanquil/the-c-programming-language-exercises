#include <stdio.h>

/* the parameter x is replaced by "z + 1", which is different from assignment
   to the value of the expression z + 1, so square(z + 1) will evaluate in the
   following way: square(z + 1) = z + 1 * z + 1 = 5 + 5 + 1 * 5 + 1 = 11 */
/* evaluation of expressions occurs after the expressions are "plugged in" */
#define square(x) x * x

/* putting a # in front of the parameter name in the replacement text expands 
   it into a quoted string with the parameter replaced by the actual argument */
#define quoted(name) printf(#name " value: %d\n", name)

/* putting ## in between two params in the replacement text concatenates the
   actual arguments, removing whitespace and the ## character */
#define paste(left, right) left ## right

void main() {
  int z = 5;
  char zz[] = "hi";

  printf("%d\n", square(z + 1)); // 11
  quoted(z + 1);                 // "z + 1 value: 6"
  printf("%s\n", paste(z, z));   // "hi" => paste(z, z) returns zz
}