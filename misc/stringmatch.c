#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 100
#define y 1000

void searchpat(int choice) {
    int *arr;
    int i, j, k;
    FILE *inp;
    FILE *out;
    int count = 0, itr = 0;
    int ptrn[54];
    srand(time(NULL));
    for (k = x; k <= y; k = k + 100) {
        if (choice == 1) {
            inp = fopen("ibest.txt", "a");
            out = fopen("best.txt", "a");
        } else if (choice == 2) {
            inp = fopen("iworst.txt", "a");
            out = fopen("worst.txt", "a");
        } else {
            inp = fopen("iavg.txt", "a");
            out = fopen("avg.txt", "a");
        }
        arr = (int *)malloc(k * sizeof(int));
        if (choice == 1 || choice == 2) {
            for (i = 0; i < k - 1; i++) {
                arr[i] = 1;
                fprintf(inp, "%d\t", arr[i]);
            }
            arr[i] = 0;
            fprintf(inp, "%d\t", arr[k - 1]);
            if (choice == 1) {
                for (i = 0; i < 54; i++) {
                    ptrn[i] = arr[i];
                }
            } else {
                for (i = 0; i < 53; i++) {
                    ptrn[i] = 1;
                }
                ptrn[53] = 0;
            }
        } else {
            for (i = 0; i < k; i++) {
                arr[i] = rand() % 2;
                fprintf(inp, "%d\t", arr[i]);
            }
            fprintf(inp, "\n");
            for (i = 0; i < 54; i++) {
                ptrn[i] = rand() % 2;
            }
        }
        count = 0;
        for (i = 0; i < k - 54 + 1; i++) {
            for (j = 0; j < 54; j++) {
                count++;
                if (ptrn[j] != arr[i + j]) {
                    break;
                }
            }
            if (j == 54) {
                fprintf(inp, "\nfound pattern \n");
                break;
            }
        }
        fprintf(out, "%d\t%d\n", k, count);
        fclose(inp);
        fclose(out);
    }
}
int main() {
    int lp = 1, choice;
    system("rm -r *.txt");
    while (lp) {
        printf("ENter 1 for best case\n");
        printf("Enter 2 for worst case \n");
        printf("press 3 for avg case\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
        case 2:
        case 3:
            searchpat(choice);
            break;
        case 4:
            lp = 0;
        }
    }
}