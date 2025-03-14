/* Exercise 3-3. Write a function expand(s1, s2) that expands shorthand 
notations like a-z in the string s1 into the equivalent complete list 
abc...xyz in s2. Allow for letters of either case and digits, and be 
prepared to handle cases like a-b-c a-z0-9 and -a-z. Arrange that a leading 
or trailing - is taken literally. */

/*
given a string s1, consisting of letters and digits delimited by dashes -,
read any leading dashes into s2,
find the last non-dash char in s1 and set iteration to end there
keep track of whether or not we're in a character range with a variable inrange
keep track of the first/last characters in a range 
when encountering a non-dash character, flip inrange
if flipping inrange to on, then set the first character
if flipping inrange to off, set the last character, then add that range of characters to s2
when encountering a dash, if inrange is off, then the last character (assume it's a nondash)
begins a new range; set inrange to on and set the first character
read any trailing dashes into s2
*/

#include <stdio.h>
#include <string.h>

enum { OUT_OF_RANGE, IN_RANGE };

void expand(char s1[], char s2[]) {
  int i, j, k, currently_in_range;
  char first_char, last_char;

  for (i = 0, j = 0; s1[i] == '-'; i++, j++) {
    s2[j] = s1[i];
  }

  for (k = 0; s1[strlen(s1) - 1 - k] == '-'; k++) {
    ;
  }

  currently_in_range = OUT_OF_RANGE;

  while (i < (strlen(s1) - k)) {
    if (s1[i] != '-') {
      if (!currently_in_range) {
        first_char = s1[i];
        currently_in_range = IN_RANGE;
      } else {
        int m;
        last_char = s1[i];
        currently_in_range = OUT_OF_RANGE;

        for (m = 0; m <= last_char - first_char; m++) {
          s2[j + m] = first_char + m;
        }

        j += m;
      } 
    } else {
        if (!currently_in_range) {
          first_char = last_char;
          currently_in_range = IN_RANGE;
        }
    }

    i++;
  }

  for (int l = 0; l < k; l++) {
    s2[j++] = '-';
  }

  s2[++j] = '\0';
}

void main() {
  char a[31];

  expand("--a-z--", a);
  printf("%s\n", a); /* "--abcdefghijklmnopqrstuvwxyz--" */

  char b[5];
  expand("a-b-c", b);
  printf("%s\n", b); /* "abbc" */

  char c[100];
  expand("-a-z0-9A-Z----", c);
  printf("%s\n", c); 
}