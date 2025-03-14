/* Exercise 3-2. Write a function escape(s, t) that converts characters like 
newline and tab into a visible escape sequence like \n and \t as it copies 
the string t to s. Use a switch. Write a function for the other direction as 
well, converting escape sequences into the real characters. */

/*
given strings s and t,
let i and j represent the current index of t and s (both set to 0)
for each i,
if t[i] is a normal character, copy it into s[j] and increment both by 1
if t[i] is an escape character, copy the literal into s[j] and s[j + 1]; 
increment i by 1 and j by 2 
*/

#include <stdio.h>

void escape(char s[], char t[]) {
  int i = 0, j = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        i++;
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        i++;
        break;
      case '\\':
        s[j++] = '\\';
        s[j++] = '\\';
        i++;
        break;
      case '\'':
        s[j++] = '\\';
        s[j++] = '\'';
        i++;
        break;
      case '\"':
        s[j++] = '\\';
        s[j++] = '\"';
        i++;
        break;
      default:
        s[j++] = t[i++];
        break;
    }
  }

  s[++j] = '\0';
}

/*
given strings s and t,
let i and j be the indices of t and s, respectively.
if t[i] is '\', then t[i + 1] is a "literal" escape character
write that escape character into s[j], incremement i by 2 and j by 1
otherwise, write t[i] into s[j] and incremement i and j by 1
*/

void unescape(char s[], char t[]) {
  int i = 0, j = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
      case '\\':
        switch (t[i + 1]) {
          case 'n':
            s[j] = '\n';
            break;
          case 't':
            s[j] = '\t';
            break;
          case '\\':
            s[j] = '\\';
            break;
          case '\'':
            s[j] = '\'';
            break;
          case '\"':
            s[j] = '\"';
            break;
        }
        i += 2;
        j++;
        break;
      default:
        t[i++] = s[j++];
        break;
    }
  }

  s[++j] = '\0';
}

void main () {
  /* s needs to have enough room else segfault */
  char t[] = "h\ni t\th\\e\'r\"e\n\t";
  char s[] = "                                 ";

  escape(s, t);
  printf("%s\n", s); 

  unescape(t, s);
  printf("%s\n", t);
}