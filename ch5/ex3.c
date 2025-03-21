/* Exercise 5-3. Write a pointer version of the function strcat that we showed 
   in Chapter 2: strcat(s, t) copies the string t to the end of s. */

/*
  given pointers to strings s and t,
  increment the pointer to s until *s = '\0'
  then until *t = '\0', assign *s = *t and increment s and t
  write '\0' into s so the string's valid
*/

#include <stdio.h>

void _strcat(char *s, char *t) {
  while (*s != '\0') {
    s++;
  }

  while (*t != '\0') {
    *s = *t;
    s++;
    t++;
  }
  
  *s = '\0';
}

void main() {
  /* doing this to reinforce the difference between character arrays and
     pointers to character arrays; we're writing into s but are just moving
     through the character array that t points to
  */
  char s[11] = "hello ";
  char *t = "world";

  _strcat(s, t);

  printf("%s\n", s);
}