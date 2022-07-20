// to analyse the order of growth of basic operation of the algorithm to find
// the solution of a polynomial
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    srand(time(0));
    int n = 10;
    int a[100];
    int sum = 0, i, j, count, num;
    float x;
    FILE *fp = NULL;

    fp = fopen("poly2.txt", "w");
    for (j = 0; j < 10; j++) {
        int p = 1;
        count = 0;
        num = j;
        x = j;
        for (i = 0; i <= num; i++)
            a[i] = rand() % 10;

        for (i = 1; i <= num; i++) {
            p = p * x;
            sum = sum + a[i] * p;
            count += 2;
        }
        fprintf("%d %d\n", num, count);
    }
    fclose(fp);
}