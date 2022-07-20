#include <stdio.h>
#include <stdlib.h>

void gcd1(int m, int n) {
  int rem, gcd, count = 0;
  while (n != 0) {
    count++;
    rem = m % n;
    m = n;
    n = rem;
  }
  gcd = m;
  printf("The gcd is %d\n", gcd);
  printf("The count is %d\n", count);
}

void gcd2(int m, int n) {
  int rem, gcd, count = 0;
  while (m != n) {
    count++;
    if (m > n)
      m = m - n;
    else
      n = n - m;
  }
  printf("The gcd is %d\n", gcd);
  printf("The count is %d\n", count);
}

void gcd3(int m, int n) {
  int min, temp1, temp2, count = 0, gcd;
  if (m > n)
    min = n;
  else
    min = m;

  while (min != 1) {
    temp1 = m % min;
    count++;
    if (temp1 == 0) {
      temp2 = n % min;
      count++;
    }
    if (temp2 == 0) {
      gcd = min;
      break;
    }
    min--;
  }
  gcd = min;
  printf("The gcd is %d\n", gcd);
  printf("The count is %d\n", count);
}

void main() {
  int m, n;
  printf("Enter m:");
  scanf("%d", &m);
  printf("Enter n:");
  scanf("%d", &n);
  if (m < 0 || n < 0) {
    printf("Invalid Input\n");
    exit(0);
  }
  gcd1(m, n);
  gcd2(m, n);
  gcd3(m, n);
}
