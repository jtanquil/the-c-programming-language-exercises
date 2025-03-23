/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and 
   strncmp, which operate on at most the first n characters of their argument 
   strings. For example, strncpy(s, t, n) copies at most n characters of t to
   s. */

/*
  given two strings t and s, and an integer n,

  strncpy:
    if n is greater than the length of t, just copy t into s
    otherwise, copy *(t + i) into *(s + i) for i = 0, ... , n - 1

  strncat:
    if n is greater than the length of t, just concatenate t with s
    otherwise, add *(t + i) to the end of s for i = 0, ... , n - 1

  strncmp:
    for i = 0, ..., n - 1, and while (*(t + i) != '\0')
      if *(t + i) != *(s + i), then return *(s + i) - *(t + i), otherwise, return 0
*/

#include <stdio.h>

char * _strncpy(char *s, char *t, int n) {
  int i;

  for (i = 0; i < n && (*(s + i) = *(t + i)) != '\0'; i++) {
    ;
  }

  return s;
}

char * _strncat(char *s, char *t, int n) {
  int i, j;

  for (i = 0; *(s + i) != '\0'; i++) {
    ;
  }

  for (j = 0; j < n && *(t + j) != '\0'; j++) {
    *(s + i + j) = *(t + j);
  }

  return s;
}

int _strncmp(char *s, char *t, int n) {
  int i;

  for (i = 0; i < n && *(s + i) == *(t + i); i++) {
    if (*(s + i) == '\0') {
      return 0;
    }
  }

  if (*(t + i) == '\0') {
    return 0;
  } else {
    return *(s + i) - *(t + i);
  }
}

void main() {
  char s[10] = "hi there";
  char *t = "hello";

  printf("%s\n", _strncpy(s, t, 5));

  char u[12] = "hello";
  char *v = " world";

  printf("%s\n", _strncat(u, v, 7));

  printf("%d\n", _strncmp("hello", "helw", 4));
}