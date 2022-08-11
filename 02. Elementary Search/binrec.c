#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void binarySearch(int *arr, int key, int l, int h) {
    count++;
    if (l <= h) {
        int mid = (h + l) / 2;
        if (arr[mid] == key)
            return;
        else if (arr[mid] > key)
            binarySearch(arr, key, l, mid - 1);
        else
            binarySearch(arr, key, mid + 1, h);
    }
}

void main() {
    int n, i, key;
    int *arr;

    srand(time(0));
    FILE *b, *w, *a;
    system("rm b.txt w.txt a.txt");

    b = fopen("b.txt", "a");
    w = fopen("w.txt", "a");
    a = fopen("a.txt", "a");

    for (n = 10; n < 1000; n += 10) {
        arr = (int *)malloc(n * sizeof(int));

        arr[0] = rand() % 100;
        for (i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + rand() % 100;
        }

        // Best Case
        count = 0;
        key = arr[(n - 1) / 2] = 9999;
        binarySearch(arr, key, 0, n - 1);
        fprintf(b, "%d\t%d\n", n, count);

        // Worst Case
        count = 0;
        key = 5555;
        binarySearch(arr, key, 0, n - 1);
        fprintf(w, "%d\t%d\n", n, count);

        // Average Case
        count = 0;
        key = rand() % 100;
        binarySearch(arr, key, 0, n - 1);
        fprintf(a, "%d\t%d\n", n, count);
    }

    fclose(b);
    fclose(w);
    fclose(a);
}
