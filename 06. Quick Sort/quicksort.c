#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        int i = l, j = r, p = i;
        while (i < j) {
            while (arr[i] <= arr[p]) {
                i++;
                count++;
            }
            while (arr[j] > arr[p]) {
                j--;
                count++;
            }
            if (i < j)
                swap(&arr[i], &arr[j]);
        }
        swap(&arr[j], &arr[p]);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }
}

void bestSwap(int *arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        bestSwap(arr, l, mid - 1);
        swap(&arr[l], &arr[mid]);
        bestSwap(arr, mid + 1, r);
    }
}

void main() {
    int n, i;
    int *arr;

    FILE *b, *w, *a;
    system("rm a.txt b.txt w.txt");
    b = fopen("b.txt", "a");
    w = fopen("w.txt", "a");
    a = fopen("a.txt", "a");

    for (n = 10; n < 1000; n += 10) {
        arr = (int *)malloc(n * sizeof(int));

        // Worst Case
        count = 0;
        for (i = 0; i < n; i++) {
            arr[i] = (i == 0) ? rand() % 100 : arr[i - 1] + rand() % 10;
        }
        quickSort(arr, 0, n - 1);
        fprintf(w, "%d\t%d\n", n, count);

        // Best Case
        count = 0;
        bestSwap(arr, 0, n - 1); // generating best case input array
        quickSort(arr, 0, n - 1);
        fprintf(b, "%d\t%d\n", n, count);

        // Average Case
        count = 0;
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }
        quickSort(arr, 0, n - 1);
        fprintf(a, "%d\t%d\n", n, count);
    }

    fclose(b);
    fclose(a);
    fclose(w);
}
