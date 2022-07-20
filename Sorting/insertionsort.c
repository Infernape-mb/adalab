#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;
void insertion(int a[], int n) {
    count = 0;
    int i, j, v;
    for (i = 1; i <= n - 1; i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
            count++;
        }
        if (j == -1)
            continue;
        count++;
        a[j + 1] = v;
    }
}
void insertmain(int ch) {
    FILE *a;
    int i, j, *arr;
    srand(time(NULL));
    if (ch == 1)
        a = fopen("ins_best.txt", "a");
    else if (ch == 2)
        a = fopen("ins_worst.txt", "a");
    else
        a = fopen("ins_avg.txt", "a");
    for (i = 10; i < 100; i += 10) {
        arr = (int *)malloc(sizeof(int));
        if (ch == 1) {
            for (j = 0; j < i; j++)
                arr[j] = j + 1;
        } else if (ch == 2) {
            for (j = 0; j < i; j++)
                arr[j] = i - j;
        } else {
            for (j = 0; j < i; j++)
                arr[j] = rand() % 100;
        }
        insertion(arr, i);
        fprintf(a, "%d\t%d\n", i, count);
    }
    fclose(a);
}
void main() {
    int ch;
    printf("1.Best Case\n2.Worst Case\n3.Average Case\nEnter choice\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
    case 2:
    case 3:
        insertmain(ch);
        break;
    default:
        exit(1);
    }
}