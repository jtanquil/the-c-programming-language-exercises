/* Write the function any(s1, s2), which returns the first location in the 
string s1 where any character from the string s2 occurs, or -1 if s1 contains 
no characters from s2. */

/*
loop through the characters s1[i] of s1:
for each character, loop through the characters s2[j] of s2:
if s1[i] == s2[j], return i

return -1
*/

#include <stdio.h>

#define CHAR_NOT_FOUND -1 /* s2 contains no characters in s1 */

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != '\0'; i++) {
    for(j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }

  return CHAR_NOT_FOUND;
}

void main() {
  printf("%d\n", any("abc", "abc")); // 0
  printf("%d\n", any("abc", "def")); // -1
  printf("%d\n", any("abc", "ece")); // 2
  printf("%d\n", any("abcdefgh", "3472dgjeci")); // 2
}