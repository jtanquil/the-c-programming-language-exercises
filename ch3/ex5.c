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

void reverse(char s[]) {
  int temp, i;

  for (i = 0; i <= (strlen(s) - 1) / 2; i++) {
    temp = s[i];
    s[i] = s[strlen(s) - 1 - i];
    s[strlen(s) - 1 - i] = temp;
  }
}

void itob (int n, char s[], int b) {
  int i, sign;
  char digits[16] = 
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
  if (n == INT_MIN) {
    /* using the following observations:
      1) each positive integer n has a unique representation base b given by
         n = a_0 * b ^ 0 + a_1 * b ^ 1 + ... + a_k * b^k
         where a_0, ... a_k are in {0, 1, ... , b - 1}
      2) the corresponding representation for -n is also given by the same
         a_i, with a negative sign at the front
      3) it can be proven that if the "ones digit" a_0 of the representation 
         of 2^k - 1 (k > 0) is b - 1, then b must divide 2^k; this shows that
         for all other values of b, if k is the wordsize of int, then the
         minimum integer value -(2^(k - 1)) can be represented using the same
         trick as in ex4: taking the representation of 2^(k - 1) - 1 and adding
         a 1 to the ones digit.
       4) if b is a power of 2, then we can use the observation that for k > 0,
       2^k - 1 = 2^0 + 2^1 + ... + 2^(k - 1). If b = 2^j for some j, then dividing
       j into k gives us k = lj + r for some remainder 0 <= r < k. We can group
       the powers of 0, 1, ... k - 1 in the above expression:
       2^k - 1 = 1 + 2 + ... + 2^{j - 1} + 2^j + ... + 2^{2j - 1} + ... 
               = (2^j - 1) * 1 + (2^j - 1) * 2^j + ... 
               + (2^j - 1) * 2^((l - 1)j) + (2^r - 1) * 2^(lj)
        Adding 1 to both sides of this expression overflows the 1, 2^j, ... 2^(l - 1)j
        terms to 0 and changes the coefficient of the 2^(lj) term to 2^r. This gives the
        base b representation of -(2^(wordsize - 1)). 
      */

    int j, is_power_of_2;

    j = 0;

    while (b > pow(2, j)) {
      j++;
    }

    is_power_of_2 = (b % pow(2, j - 1) == 0);

    if (!is_power_of_2) {
      int ones_index;

      itob(n + 1, s, b);
      ones_index = (s[strlen(s) - 1] - '0') % 10;
      s[strlen(s) - 1] = digits[ones_index + 1];
    } else {
      int k;

      for (k = 0; n/2 <= -pow(2, k); k++) {
        ;
      }

      int r = k % j;
      printf("%d %d %d\n", k, j, r);
      int offset = 0;

      s[offset++] = '-';

      switch(b) {
        case 2:
          s[offset++] = '0';
          s[offset++] = 'b';
          break;
        case 8:
          s[offset++] = '0';
          break;
        case 16:
          s[offset++] = '0';
          s[offset++] = 'x';
          break;
      }

      s[offset] = digits[pow(2, r)];

      for (i = offset + 1; i <= k / j + offset; i++) {
        s[i] = '0';
      }

      s[i] = '\0';
    }
    ;
  } else {
    if ((sign = n) < 0) {
      n = -n;
    }

    i = 0;

    do {
      s[i++] = digits[n % b];
    } while ((n /= b) > 0);

    switch(b) {
      case 2:
        s[i++] = 'b';
        s[i++] = '0';
        break;
      case 8:
        s[i++] = '0';
        break;
      case 16:
        s[i++] = 'x';
        s[i++] = '0';
        break; 
    }

    if (sign < 0) {
      s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
  }
}

void main() {
  char s[32];

  itob(-3413, s, 16);
  printf("%s\n", s); // -0xD55
  itob(4416, s, 2);
  printf("%s\n", s); // 0b1000101000000
  itob(37, s, 8);
  printf("%s\n", s); // 045
  itob(-12345, s, 10);
  printf("%s\n", s); // -12345
  itob(0, s, 16);
  printf("%s\n", s); // 0x0
  itob(INT_MIN + 1, s, 10);
  printf("%s\n", s); // -2147483647 
  itob(INT_MIN, s, 10);
  printf("%s\n", s); // -2147483648
  itob(INT_MIN + 1, s, 7);
  printf("%s\n", s);
  itob(INT_MIN, s, 7);
  printf("%s\n", s);
  itob(INT_MIN + 1, s, 16);
  printf("%s\n", s);
  itob(INT_MIN, s, 16);
  printf("%s\n", s);
}