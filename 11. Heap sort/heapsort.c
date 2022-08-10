#include <stdio.h>
#include <stdlib.h>

int count = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    ++count;
    while (left < n && arr[largest] < arr[left])
        largest = left;
    while (right < n && arr[largest] < arr[right])
        largest = right;

    if (i != largest) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void heap(int arr[], int n) {
    for (int i = n / 2 - 1; i > -1; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > -1; --i) {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

void main() {
    FILE *a, *b, *w;
    system("rm avg.txt;   rm worst.txt;   rm best.txt");
    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for (int n = 10; n <= 100; n += 10) {
        int arr[n];

        // best case
        for (int i = 0; i < n; ++i)
            arr[i] = n - i;
        heap(arr, n);
        fprintf(b, "%d  %d\n", n, count);
        count = 0;

        // worst case
        for (int i = 0; i < n; ++i)
            arr[i] = i;
        heap(arr, n);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;

        // avg case
        for (int i = 0; i < n / 2; ++i)
            arr[i] = rand() % 100;
        heap(arr, n);
        fprintf(a, "%d  %d\n", n, count);
        count = 0;
    }
    fclose(a);
    fclose(b);
    fclose(w);
    system("gnuplot -p -c plot.txt");
}