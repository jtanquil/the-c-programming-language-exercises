/* Exercise 3-1. Our binary search makes two tests inside the loop, when one 
would suffice (at the price of more tests outside). Write a version with only 
one test inside the loop and measure the difference in run-time. */

/*
  change prototype to (int x, int v[], int low, int high)
  pass low/high params

  first set mid = (low + high) / 2, check if v[mid] == x
  else, it's not, go into the loop:

  if x < v[mid], then return binsearch(x, v, low, mid - 1)
  else, return binsearch(x, v, mid + 1, high)

  ...

  return -1
*/

#include <stdio.h>

int binsearch(int x, int v[], int low, int high) {
  int mid;

  mid = (low + high) / 2;

  if (x == v[mid]) {
    return mid;
  }

  while(low <= high) {
    if (x < v[mid]) {
      return binsearch(x, v, low, mid - 1);
    } else {
      return binsearch(x, v, mid + 1, high);
    }
  }

  return -1;
}

void main() {
  int v[5] = {1, 2, 3, 4, 5};
  int w[6] = {2, 4, 6, 8, 10, 12};

  printf("%d\n", binsearch(3, v, 0, 4)); // 2
  printf("%d\n", binsearch(10, w, 0, 5)); // 4
  printf("%d\n", binsearch(7, w, 0, 5)); // -1
  printf("%d\n", binsearch(0, v, 0, 4)); // -1
}