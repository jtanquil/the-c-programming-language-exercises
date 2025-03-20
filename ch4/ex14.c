/* Exercise 4-14. Define a macro swap(t, x, y) that interchanges two arguments 
   of type t. */

#include <stdio.h>

#define swap(t, x, y) (t) y, (t) x

void main() {
  int a = 3, b = 4;

  printf("%d %d\n", swap(int, a, b)); // 4 3
  printf("%d\n", (swap(int, a, b)));  // 3, demonstrates textual substitution w/macros
}