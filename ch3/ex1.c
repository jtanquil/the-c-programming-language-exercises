/* Exercise 3-1. Our binary search makes two tests inside the loop, when one 
would suffice (at the price of more tests outside). Write a version with only 
one test inside the loop and measure the difference in run-time. */

[1, 2, 3, 4, 5]

/*
while (low < high) {
  mid = (low + high) / 2;
  (x < v[mid]) ? high = mid - 1 : low = mid + 1;
}

return (x == v[mid]) ? mid : -1;
*/

x: 3 (index 2)
low: 0, 2, 2
high: 4, 4, 2
mid: 2, 3

x: 4 (index 3)
low: 0, 2, 3, 3
high: 4, 4, 4, 4
mid: 2, 3, 3