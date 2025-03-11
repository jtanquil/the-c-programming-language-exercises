/* Exercise 2-3. Write the function htoi(s), which converts a string of 
hexadecimal digits (including an optional 0x of 0X) into its equivalent 
integer value. The allowable digits are 0 through 9, a through f, and A 
through F. */

/*

given a string s representing a hexadecimal digit,

first set n = 0,

if the first two characters are 0x or 0X, skip them
otherwise, for each character s[i]:
if it's 0-9, add s[i] - '0', if it's a-f add (10 + s[i] - 'a'), 
if it's A-F add (10 + s[i] - 'A')

n = 16 * n + (contribution of s[i] digit)

*/

#include <stdio.h>
#include <string.h>

#define HEXADECIMAL_BASE 16

int htoi(char s[]) {
  int n, i;
  n = 0;

  if (strlen(s) >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i = 2;
  } else {
    i = 0;
  }

  for (; i < strlen(s); i++) {
    int current_digit;

    if (s[i] >= '0' && s[i] <= '9') {
      current_digit = s[i] - '0';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      current_digit = 10 + s[i] - 'A';
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      current_digit = 10 + s[i] - 'a';
    }

    n = HEXADECIMAL_BASE * n + current_digit;
  }

  return n;
}

void main() {
  printf("%d\n", htoi("0xFfF")); // 4095
  printf("%d\n", htoi("aBC")); // 2748
  printf("%d\n", htoi("0123")); // 291
  printf("%d\n", htoi("0XEEE")); // 3822
}