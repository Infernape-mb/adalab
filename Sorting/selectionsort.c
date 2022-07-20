#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selection(int arr[], int n) {
    int i, j, min, count = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            count++;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[j];
        arr[j] = temp;
    }
    return count;
}

void main() {
    int i, *arr, n, count;
    FILE *fp1, *fp2, *fp3;
    srand(time(0));

    // system("rm s_best.txt");
    // system("rm s_avg.txt");
    // system("rm s_worst.txt");

    for (n = 100; n <= 1000; n += 100) {
        arr = (int *)malloc(n * sizeof(int));

        // Best Case
        for (i = 0; i < n; i++)
            arr[i] = i + 1;
        fp1 = fopen("s_best.txt", "a");
        count = selection(arr, n);
        fprintf(fp1, "%d\t%d\n", n, count);
        fclose(fp1);

        // Average case
        for (i = 0; i < n; i++)
            arr[i] = rand() % 1000;
        fp2 = fopen("s_avg.txt", "a");
        count = selection(arr, n);
        fprintf(fp2, "%d\t%d\n", n, count);
        fclose(fp2);

        // Worst case
        for (i = 0; i < n; i++)
            arr[i] = n - i;
        fp3 = fopen("s_worst.txt", "a");
        count = selection(arr, n);
        fprintf(fp3, "%d\t%d\n", n, count);
        fclose(fp3);
    }
}
