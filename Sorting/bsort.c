#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;
int n = 10;

void sort(int a[]) {
  count = 0;
  int i, j, temp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      count++;
      if (a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

int main() {
  FILE *fp1, *fp2;
  int *a;

  fp1 = fopen("bs_best.txt", "a");
  fp2 = fopen("bs_worstavg.txt", "a");

  srand(time(0));
  int i;

  // worst case scenario, reverse sorted order
  for (n = 100; n < 1000; n = n + 100) {
    a = (int *)malloc(n * sizeof(int));
    i = 0;
    while (i != n) {
      a[i] = n - i - 1;
      printf("%d\t", a[i]);
      i++;
    }
    sort(a);
    fprintf(fp2, "%d\t%d\n", n, count);
  }
  fclose(fp2);
  free(a);

  // best case scenario sorted order
  for (n = 100; n < 1000; n = n + 100) {
    a = (int *)malloc(n * sizeof(int));
    i = 0;
    while (i != n) {
      a[i] = i + 1;
      printf("%d\t", a[i]);
      i++;
    }
    sort(a);
    fprintf(fp1, "%d\t%d\n", n, count);
  }
  fclose(fp1);
}
