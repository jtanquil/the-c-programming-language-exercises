/* Write the function itob(n, s, b) that converts the integer n into a base b 
character representation in the string s. In particular, itoa(n, s, 16) formats 
n as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>
#include <limits.h>

int pow(int base, int exponent) {
  int product = 1;

  while (exponent > 0) {
    product *= base;
    exponent--;
  }

  return product;
}

void itob (int n, char s[], int b) {
  int i, j, sign;
  char digits[16] = 
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  // issues with handling cases |n| >= INT_MAX / b
  if (n == INT_MIN) {
    /* using the following observations:
      1) each positive integer n has a unique representation base b given by
         n = a_0 * b ^ 0 + a_1 * b ^ 1 + ... + a_k * b^k
         where a_0, ... a_k are in {0, 1, ... , b - 1}
      2) the corresponding representation for -n is also given by the same
         a_i, with a negative sign at the front
      3) it can be proven that if the "ones digit" a_0 of the representation 
         of 2^k (k > 0) is b - 1, then b must divide 2^k; in particular, for 
         k = wordsize of int, this places restrictions on the coefficients a_i
         that let us do the same trick in exercise 4: finding the base b
         representation of -2^k + 1, adding 1 to the ones digit, and adding a
         negative sign in front. */
    // itob(n + 1, s, b);

    // s[strlen(s) - 1] = s[strlen(s) - 1] + ('1' - '0');
  } else {
    if ((sign = n) < 0) {
      n = -n;
    }

    j = 0;

    if (sign < 0) {
      s[j++] = '-';
    }

    switch (b) {
      case 2:
        s[j++] = '0';
        s[j++] = 'b';
        break;
      case 8:
        s[j++] = '0';
        break;
      case 16:
        s[j++] = '0';
        s[j++] = 'x';
        break;
    }

    if (n == 0) {
      s[j++] = '0';
    }

    i = 0;

    while (n > pow(b, i)) {
      i++;
    }

    /* start the base b representation with i - 1 */
    i--;

    for (; i >= 0; j++, i--) {
      int a = 0;

      while (n >= a * pow(b, i)) {
        a++;
      }

      s[j] = digits[a - 1];
      n -= (a - 1) * pow(b, i);
    }

    s[j] = '\0';
  }
}

void main() {
  char s[32];

  itob(-3413, s, 16);
  printf("%s\n", s); // -0xD55
  itob(4416, s, 2);
  printf("%s\n", s); // 0v1000101000000
  itob(37, s, 8);
  printf("%s\n", s); // 045
  itob(-12345, s, 10);
  printf("%s\n", s); // -12345
  itob(0, s, 16);
  printf("%s\n", s); // 0x0
}