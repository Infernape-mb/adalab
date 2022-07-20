// Analysis of Quick Sort Algorithm

#include <stdio.h>
#include <stdlib.h>
#define n 10

int partition(int a[], int l, int h, int *count) {
    int i = l + 1;
    int j = h, pivot = a[l];
    while (i <= j) {
        while (i <= h) {
            *count = *count + 1;
            if (a[j] <= pivot)
                break;
            j--;
        }
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        if ((i == j) && (a[j] == pivot)) {
            *count = *count + 1;
            return j;
        }
    }
    if (a[j] != a[l]) {
        int temp = a[j];
        a[j] = a[l];
        a[l] = temp;
    }
    return j;
}

void quicksort(int a[], int l, int h, int *count) {
    int s;
    if (l < h) {
        s = partition(a, l, h, count);
        quicksort(a, l, s - 1, count);
        quicksort(a, s + 1, h, count);
    }
}

void analysis(int ch) {
    FILE *fp;
    int *a, i, j, k;
    int count, x = 10;
    for (i = 10; i <= 100; i += 10) {
        a = (int *)malloc(sizeof(int) * i);
        if (ch == 1) {
            for (j = 0; j < i; j++)
                a[j] = x;
            fp = fopen("quickbest.txt", "a");
        }
        if (ch == 2) {
            for (j = 0; j < i; j++)
                a[j] = i + j + 10;
            fp = fopen("quickworst.txt", "a");
        } else if (ch == 3) {
            exit(0);
        }
        int l = 0;
        int h = i - 1;
        count = 0;
        printf("\n");
        for (j = 0; j < i; j++)
            printf("%d\t", a[j]);
        quicksort(a, l, h, &count);
        fprintf(fp, "%d\t%d\n", i, count);
        printf("\n");
        for (j = 0; j < i; j++)
            printf("%d\t", a[j]);
        fclose(fp);
    }
}

void main() {
    int ch;
    for (;;) {
        printf("\n1. Best case\n2. Worst case\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        analysis(ch);
    }
}
