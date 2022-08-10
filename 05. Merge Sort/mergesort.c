#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Mergesort(int arr[], int l, int r) {
    if (r > l) {
        int m = l + (r - l) / 2;
        Mergesort(arr, l, m);
        Mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void main() {
    srand(time(0));
    int n, i, *arr;
    FILE *a, *b, *w;
    system("rm best.txt");
    system("rm avg.txt");
    system("rm worst.txt");
    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for (n = 100; n <= 1000; n += 100) {
        arr = (int *)malloc(sizeof(int) * n);

        // BEST case -> array already sorted
        for (i = 0; i < n; i++)
            arr[i] = i;
        Mergesort(arr, 0, n - 1);
        fprintf(b, "%d  %d\n", n, count);
        count = 0;

        // Worst case -> even index -> even num dec
        // odd index -> odd num incre
        for (i = 0; i < n; i++) {
            if (i % 2 == 0)
                arr[i] = n - i;
            else
                arr[i] = i;
        }
        Mergesort(arr, 0, n - 1);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;

        // Average case -> half random numbers and half sorted
        for (i = 0; i < n; i++)
            arr[i] = (i > n / 2) ? i + 1 : rand() % 100;
        Mergesort(arr, 0, n - 1);
        fprintf(a, "%d  %d\n", n, count);
        count = 0;
    }

    fclose(w);
    fclose(a);
    fclose(b);
}
