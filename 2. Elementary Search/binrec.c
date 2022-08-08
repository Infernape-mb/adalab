// binary search
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 10
#define Y 100
int count = 0;

void binsearch(int arr[], int low, int high, int key) {
    int mid = low + (high - low) / 2;
    count++;
    if (arr[mid] == key)
        return;
    else if (arr[mid] > key)
        binsearch(arr, low, mid - 1, key);
    else
        binsearch(arr, mid + 1, high, key);
}

void helper(int arr[], int n, int key) {
    count = 0;
    binsearch(arr, 0, n - 1, key);
}

void binary(int choice) {
    FILE *fp1, *fp2;
    int i, j, temp, key, res, *arr;
    srand(time(NULL));
    if (choice == 1) {
        fp1 = fopen("bestin.txt", "a");
        fp2 = fopen("best.txt", "a");
    } else if (choice == 2) {
        fp1 = fopen("worstin.txt", "a");
        fp2 = fopen("worst.txt", "a");
    } else {
        fp1 = fopen("avgin.txt", "a");
        fp2 = fopen("avg.txt", "a");
    }

    for (i = X; i <= Y; i += 10) {
        arr = (int *)malloc(sizeof(int) * i);
        res = rand() % 100;
        for (j = 0; j < i; j++) {
            arr[j] = j + res;
            fprintf(fp1, "%d ", arr[j]);
        }
        fprintf(fp1, "\n");
        if (choice == 1) {
            key = arr[(i - 1) / 2];
        } else if (choice == 2) {
            key = arr[i - 1];
        } else {
            temp = rand() % (i - 1);
            key = arr[temp];
        }
        helper(arr, i, key);
        fprintf(fp2, "%d\t%d\n", i, count);
    }
    fclose(fp1);
    fclose(fp2);
}

void main() {
    for (int i = 1; i <= 3; i++) {
        binary(i);
    }
}
