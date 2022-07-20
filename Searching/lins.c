#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count, i;
int n = 10;
void search(int k, int a[]) {
    count = 0;

    for (i = 0; i < n; i++) {
        count++;
        if (a[i] == k) {
            return;
        }
    }
}

int main() {
    FILE *fp1, *fp2, *fp3;
    int *a;
    system("rm l_best.txt");
    system("rm l_worst.txt");
    system("rm l_avg.txt");
    fp1 = fopen("l_best.txt", "a");
    fp2 = fopen("l_worst.txt", "a");
    fp3 = fopen("l_avg.txt", "a");
    srand(time(0));
    int lower = 1000;
    int upper = 2000;
    int key;
    for (n = 10; n < 100; n = n + 10) {
        a = (int *)malloc(n * sizeof(int));
        i = 0;
        for (i = 0; i < n; i++) {
            a[i] = (rand() % (upper - lower + 1)) + lower;
            printf("%d\t", a[i]);
        }
        key = a[0];
        search(key, a);
        fprintf(fp1, "%d\t%d\n", n, count);

        key = a[n - 1];
        search(key, a);
        fprintf(fp2, "%d\t%d\n", n, count);

        key = a[n / 2];
        search(key, a);
        fprintf(fp3, "%d\t%d\n", n, count);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
