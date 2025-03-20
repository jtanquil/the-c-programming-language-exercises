/* Exercise 4-13. Write a recursive version of the function reverse(s), which 
   reverses the string s in place.
*/

/*
  reverse(s, first, last)
  set first = 0, last = strlen(s) - 2 (assuming last character is '\0')

  if first < last,
  swap s[first] and s[last]
  reverse(s, first - 1, last + 1)
*/

#include <stdio.h>

void reverse(char s[], int first, int last) {
  int temp;

  if (first < last) {
    temp = s[first];
    s[first] = s[last];
    s[last] = temp;
    
    reverse(s, first + 1, last - 1);
  }
}

void main() {
  char a[] = "hello";

  reverse(a, 0, 4);
  printf("%s\n", a);

  char b[] = "banana";

  reverse(b, 0, 5);
  printf("%s\n", b);
}