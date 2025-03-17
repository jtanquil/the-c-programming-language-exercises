/* Exercise 4-1. Write the function strrindex(s, t) which returns the position 
of the rightmost occurrence of t in s, of -1 if there is none. */

/*
given strings s and t,

let i and j track indices and s and t.

set i = end of s, iterate through the indices of s: for each i,
set j to be the end of t, and k = i
for each j, check if s[k] == t[j]; decrement both each iteration
if they strings match, return k

iterate until i < length of t - 1 (then it is impossible for t to be in s)

if failed to find a match, return -1

*/

#include <stdio.h>

int length(char s[]) {
  int i = 0;

  while (s[i] != '\0') {
    i++;
  }

  return i;
}

int strrindex(char s[], char t[]) {
  int i, j, k, l;

  i = length(s);
  j = length(t);

  for (; i > j - 1; i--) {
    k = i - 1;
    l = j - 1;

    while (l >= 0 && (s[k] == t[l])) {
      if (l == 0) {
        return k;
      }

      k--;
      l--;
    }
  }

  return (j > 0) ? -1 : length(s) - 1;
}

void main() {
  printf("%d\n", strrindex("test", "s")); // 2
  printf("%d\n", strrindex("test", "t")); // 3
  printf("%d\n", strrindex("test", "a")); // -1
  printf("%d\n", strrindex("best", "b")); // 0
  printf("%d\n", strrindex("best", "")); // 3
  printf("%d\n", strrindex("", "test")); // -1
  printf("%d\n", strrindex("", "")); // -1
  printf("%d\n", strrindex("test", "te")); // 0
}