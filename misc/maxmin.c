#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
int min;
int count = 0;
int max;
int t1;
int t2;
int findminmax(int arr[], int l, int r) {

    if (l == r) {
        return arr[l];
    }
    t1 = findminmax(arr, l, (r + l) / 2);
    t2 = findminmax(arr, (r + l) / 2 + 1, r);
    count++;
    if (t1 > t2) {
        max = t1;
        min = t2;
    } else {
        max = t2;
        min = t1;
    }
}

void helper(int arr[], int n) {
    count = 0;
    int dummy;
    t1 = 0;
    t2 = 0;
    dummy = findminmax(arr, 0, n - 1);
}

void main() {
    FILE *a;
    FILE *b;
    int i, j;
    system("rm -r *.txt");
    a = fopen("input.txt", "a");
    b = fopen("output.txt", "a");
    for (i = x; i <= y; i = i + 10) {
        int *arr = (int *)malloc(i * sizeof(int));
        for (j = 0; j < i; j++) {
            arr[j] = rand() % 100;
            fprintf(a, "%d\t", arr[j]);
        }
        fprintf(a, "\n");
        findminmax(arr, 0, i - 1);
        fprintf(b, "%d\t%d\n", i, count);
    }
    fclose(a);
    fclose(b);
}