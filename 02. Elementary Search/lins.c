#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count, i, n;

int search(int k, int a[]) {
    count = 0;
    for (i = 0; i < n; i++) {
        count++;
        if (a[i] == k) {
            return i;
        }
    }
}

int main() {
    FILE *fp1, *fp2, *fp3;
    int *a;
    int lower = 1000;
    int upper = 2000;
    int key;

    system("rm l_best.txt");
    system("rm l_worst.txt");
    system("rm l_avg.txt");

    fp1 = fopen("l_best.txt", "a");
    fp2 = fopen("l_worst.txt", "a");
    fp3 = fopen("l_avg.txt", "a");

    srand(time(0));

    for (n = 10; n < 100; n = n + 10) {
        a = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            a[i] = (rand() % (upper - lower + 1)) + lower;
            printf("%d\t", a[i]);
        }
        printf("\n\n");
        // best case
        key = a[0];
        search(key, a);
        fprintf(fp1, "%d\t%d\n", n, count);

        // worst case
        key = a[n - 1];
        search(key, a);
        fprintf(fp2, "%d\t%d\n", n, count);

        // average case
        key = a[n / 2];
        search(key, a);
        fprintf(fp3, "%d\t%d\n", n, count);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
