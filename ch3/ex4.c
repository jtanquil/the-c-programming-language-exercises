/* Exercise 3-4. In a two's complement number representation, our version of 
itoa does not handle the largest negative number, that is, the value of n equal 
to -(2^(wordsize - 1)). Explain why not. Modify it to print that value 
correctly, regardless on the machine on which it runs. */

/*
In a two's complement number representation, it is possible to represent
-(2^(wordsize - 1)) as an integer but not its negative, 2^(wordize - 1), so 
in the itoa function, flipping the sign of n won't work if n is 
-(2^(wordsize - 1)).

To represent this number, first note that the ones digit for powers of 2 will
either be 1 (only for 2^0), 2, 4, 8 or 6. In particular, 2^k % 10 != 0 or 9.
If n = -(2^(wordsize - 1)), then consider n + 1: since the ones digit of n is
either 2, 4, 8 or 6, the ones digit of n + 1 will either be 1, 3, 7 or 5, and
all subsequent digits of n + 1 will the same as that of n. This means the 
string representation of n can be obtained by taking the string representation
of n + 1 and replacing its ones digit, say j, with the digit j + 1.
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[]) {
  int temp, i;

  for (i = 0; i < (strlen(s) - 1) / 2; i++) {
    temp = s[i];
    s[i] = s[strlen(s) - 1 - i];
    s[strlen(s) - 1 - i] = temp;
  }
}

void itoa(int n, char s[]) {
  int i, sign;
  
  if (n == INT_MIN) {
    itoa(n + 1, s);

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
    s[i] = '\0';
    reverse(s);
  }
}

void main () {
  char s[33] = "";

  itoa(-2576, s);
  printf("%s\n", s);

  itoa(INT_MIN, s);
  printf("%s\n", s);

  itoa(INT_MAX, s);
  printf("%s\n", s);
}