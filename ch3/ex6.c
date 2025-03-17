/* Write a version of itoa that accepts three arguments instead of two. The 
third argument is a minimum field width; the converted number must be padded 
with blanks on the left if necessary to make it wide enough. */

/*
  after itoa gets the digits the sign, but before reversing the string, if 
  the length is less than the minimum field length, pad with spaces until it
  reaches the minimum field length; then add '\0' and reverse
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[]) {
  int temp, i;

  for (i = 0; i <= (strlen(s) - 1) / 2; i++) {
    temp = s[i];
    s[i] = s[strlen(s) - 1 - i];
    s[strlen(s) - 1 - i] = temp;
  }
}

void itoa(int n, char s[], int minfield) {
  int i, sign;
  
  if (n == INT_MIN) {
    itoa(n + 1, s, minfield);

    /* find the ones digit and subtract 1 from it */
    int k;

    for(k = 0; s[k] != '\0'; k++) {
      ;
    }

    s[k - 1] = s[k - 1] + ('1' - '0');
  } else {
    if ((sign = n) < 0) {
      n = -n;
    }
    i = 0;
    do {
      s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
      s[i++] = '-';
    }

    while (i < minfield) {
      s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
  }
}

void main () {
  char s[50] = "";

  itoa(-2576, s, 40);
  printf("%s\n", s);

  itoa(INT_MIN, s, 40);
  printf("%s\n", s);

  itoa(INT_MAX, s, 40);
  printf("%s\n", s);
}