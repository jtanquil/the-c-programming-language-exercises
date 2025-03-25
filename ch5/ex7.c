/* Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
   rather than calling alloc to maintain storage. How much faster is the program? */

  #include <stdio.h>
  #include <string.h>

  #define MAXLINES 5
  #define MAXLINELENGTH 5000

  #define MAXLEN 1000

  char *lineptr[MAXLINES];

  int readlines(char *lineptr[], char *p, char *pstart, int nlines);
  void writelines(char *lineptr[], int nlines);

  void qsort(char *lineptr[], int left, int right);

  int _getline(char *, int);
  
  /* sort input lines */
  int main () {
    int nlines;
    char p[MAXLINELENGTH];

    if ((nlines = readlines(lineptr, p, p, MAXLINES)) >= 0) {
      writelines(lineptr, nlines);
      qsort(lineptr, 0, nlines - 1);
      writelines(lineptr, nlines);
      return 0;
    } else {
      printf("error: input too big to sort\n");
      return 1;
    }
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
    char line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
      if (nlines >= maxlines ||  p - pstart > MAXLINELENGTH)
        return -1;
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
      printf("%s\n", i, lineptr[i]);
    }
  }

  void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
      return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
      if (strcmp(v[i], v[left]) < 0)
        swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
  }

  void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
  }