/* Extend atof to handle scientific notation of the form 123.45e-6 where a 
floating-point number may be followed by e or E and an optionally signed 
exponent. */

/*
after processing the sign and digits to the left/right of the decimal,
check for an exponent ('e' or 'E')
if there is one,
set exponent = 10 and power,
if there's a sign '-', read the next integer int as -int, else +int
return the normal result * pow(exponent, power)
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++) {
    ;
  }

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  double result = sign * val / power;

  if (s[i] == '\0') {
    return result; 
  }

  if (s[i] == 'e' || s[i] == 'E') {
    int exp_sign, exp;
    i++;

    exp_sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
      i++;
    }

    for (exp = 0; isdigit(s[i]); i++) {
      exp = 10 * exp + (s[i] - '0');
    }

    return result * pow(10, exp_sign * exp);
  }
}

void main() {
  printf("%f\n", atof("-123.45")); // "-123.45"
  printf("%f\n", atof("-123.45e6"));
  printf("%f\n", atof("-123.45E-6"));
  printf("%f\n", atof("1e308"));
}