#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count, i;
int n = 10;
void search(int k, int a[]) {
    int f = 0;
    int l = n - 1;
    int m;
    count = 0;
    while (f <= l) {
        m = (f + l) / 2;
        count++;
        if (a[m] == k) {
            return;
        } else if (a[m] < k) {
            f = m + 1;
        } else {
            l = m - 1;
        }
    }
}

int main() {
    FILE *fp1, *fp2, *fp3, *fp4;
    int *a;
    system("rm b_best.txt");
    system("rm b_worst.txt");
    system("rm b_avg.txt");
    fp1 = fopen("b_best.txt", "a");
    fp2 = fopen("b_worst.txt", "a");
    fp3 = fopen("b_avg.txt", "a");
    fp4 = fopen("b_data.txt", "r");

    srand(time(0));

    int lower = 1000;
    int key;
    char ch;
    for (n = 10; n < 100; n = n + 10) {
        a = (int *)malloc(n * sizeof(int));
        i = 0;
        for (i = 0; i < n; i++) {
            a[i] = i + 1;
            while (!feof(fp4)) {
                ch = fgetc(fp4);
                printf("%c", ch);
            }
        }

        key = a[(n - 1) / 2];
        search(key, a);
        fprintf(fp1, "%d\t%d\n", n, count);

        key = a[0];
        search(key, a);
        fprintf(fp2, "%d\t%d\n", n, count);

        key = a[((n - 1) / 2 - 5)];
        search(key, a);
        fprintf(fp3, "%d\t%d\n", n, count);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
