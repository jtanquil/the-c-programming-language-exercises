/* Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes 
each character in s1 that matches any character in the string s2. */

/*
set i = j = 0;

for the character s[i] in s1,
loop through the characters in s2,
if the current character doesn't match any character in s2,
 then copy it to s[j] and increment j
increment i each iteration
*/

#include <stdio.h>

#define IN 1    /* the character is in s2 */
#define OUT 0   /* the character isn't in s2 */

void squeeze(char s1[], char s2[]) {
  int i, j, k, is_in_s2;
  for (i = j = 0; s1[i] != '\0'; i++) {
    is_in_s2 = OUT;

    for(k = 0; s2[k] != '\0'; k++) {
      if (s2[k] == s1[i]) {
        is_in_s2 = IN;
        break;
      }
    }

    if (!is_in_s2) {
      s1[j++] = s1[i];
    }
  }

  s1[j] = '\0';
}

void main() {
  char s1[] = "abc";
  char s2[] = "bcd";

  squeeze(s1, s2);
  printf("%s\n", s1); // "a"

  char s3[] = "abc";
  char s4[] = "123";

  squeeze(s3, s4);
  printf("%s\n", s3); // "abc"
}