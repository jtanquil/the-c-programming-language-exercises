#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5
#define MAXLINELENGTH 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *p, char *pstart, int nlines);
void writelines(char *lineptr[], int nlines);

void _qsort(void *lineptr[], int sort_order, int lower, int directory, int left, int right,
           int (*comp)(void *, void *));
int numcmp(char *, char *);

int _getline(char *, int);

void str_lower(char *, char *);
void str_directory(char *, char *);

void main (int argc, char *argv[]) {
  int nlines, sort_order;
  int numeric = 0;
  int reverse = 0;
  int lower = 0;
  int directory = 0;
  char p[MAXLINELENGTH];

  /* Exercise 5-14. Modify the sort program to handle a -r flag, which
     indicates sorting in reverse (decreasing) order. Be sure that -r works
     with -n. */
  /* Exercise 5-15. Add the option -f to clearfold upper and lower case together, 
     so that case distinctions are not made during sorting; for example, a 
     and A compare equal. */
  /* Exercise 5-16. Add the -d ("directory order") option, which makes 
     comparisons only on letters, numbers and blanks. Make sure it works in 
     conjunction with -f. */
  // valid flags: n, r, f, d
  if (argc >= 2) {
    for (int j = 1; j < argc && argv[j][0] == '-'; j++) {
      for (int k = 1; argv[j][k] != '\0'; k++) {
        switch (argv[j][k]) {
          case 'r':
            reverse = 1;
            break;
          case 'n':
            numeric = 1;
            break;
          case 'f':
            lower = 1;
            break;
          case 'd':
            directory = 1;
            break;
        }
      }
    }
  } 

  // lowercase and directory order only makes sense if the sort is lex
  if (numeric == 1) {
    lower = 0;
    directory = 0;
  }

  sort_order = (reverse) ? -1 : 1;

  if ((nlines = readlines(lineptr, p, p, MAXLINES)) >= 0) {
    _qsort(lineptr, sort_order, lower, directory, 0, nlines - 1, 
      (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
  } else {
    printf("input too big to sort\n");
  }
}

void _qsort (void *v[], int sort_order, int lower, int directory, int left, int right,
            int (*comp)(void *, void *))
{
  printf("left: %d, right: %d\n", left, right);
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    int swap_result;

    if (lower) {
      char lower_str_i[strlen(v[i])];
      char lower_str_left[strlen(v[left])];

      str_lower(lower_str_i, v[i]);
      str_lower(lower_str_left, v[left]);

      swap_result = sort_order * (*comp)(lower_str_i, lower_str_left);
    } else {
      swap_result = sort_order * (*comp)(v[i], v[left]);
    }

    if (swap_result < 0)
      swap(v, ++last, i);
  }
  swap(v, left, last);
  _qsort(v, sort_order, lower, directory, left, last - 1, comp);
  _qsort(v, sort_order, lower, directory, last + 1, right, comp);
}

void str_lower(char * lower, char *str) {
  int i;

  for (i = 0; i < strlen(str); i++) {
    lower[i] = tolower(str[i]);
  }

  lower[i] = '\0';
}

void str_directory(char *directory_str, char *str) {
  int i, j;

  // strip everything that isn't a blank, a number or a character
  for (i = 0, j = 0; i < strlen(str); i++) {
    if ((tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == ' ') {
      directory_str[j] = str[i];
      j++;
    }
  }

  directory_str[j] = '\0';
}

int numcmp (char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2) 
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

void swap (void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int _getline (char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  } if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

int readlines(char *lineptr[], char *p, char *pstart, int maxlines) {
  int len, nlines;
  char line[MAXLINELENGTH];

  nlines = 0;
  while ((len = _getline(line, MAXLINELENGTH)) > 0)
    if (nlines >= maxlines ||  p - pstart > MAXLINELENGTH)
      return nlines;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p = p + len;
    }
  return nlines;
} 

void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}