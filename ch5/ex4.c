/* Write the function strend(s, t) which returns 1 if the string t occurs at
   the end of the string s, and zero otherwise. */

/*
  given strings s and t,
  get the lengths of s and t
  if t is longer than s, return 0
  we check the last (length of t) indices of s:
  start at the index s + (length of s - length of t)
    if *s != *t, return false
    otherwise, increment s and t and check again

    return 1
*/

#include <stdio.h>

int getlength(char *s) {
  int i;

  for (i = 1; *(s + i - 1) != '\0'; i++) {
    ;
  }

  return i;
}

int strend(char *s, char *t) {
  int i = getlength(s), j = getlength(t);

  if (i < j) {
    return 0;
  } else {
    s += i - j;

    while (*t != '\0') {
      if (*s++ != *t++) {
        return 0;
      }
    }

    return 1;
  }
}

void main() {
  char *a = "hello world";
  char *b = "world";
  char *c = "hello";
  char *d = "llo";
  char *e = "";

  printf("%d %d %d %d %d %d\n", 
    strend(a, b), strend(a, c), strend(a, d), strend(c, d), strend(a, e), strend(d, a));
}