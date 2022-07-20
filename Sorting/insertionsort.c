#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;
void insertion(int arr[], int n) {
    count = 0;
    int i, j, v;
    for (i = 1; i <= n - 1; i++) {
        j = i - 1;
        v = arr[i];
        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }

        count++;
        arr[j + 1] = v;
    }
}
void insertionmain(int choice) {
    FILE *a;
    int *arr, i, j;
    srand(time(NULL));
    if (choice == 1)
        a = fopen("best.txt", "a");
    else if (choice == 2)
        a = fopen("worst.txt", "a");
    else
        a = fopen("avg.txt", "a");
    for (i = 10; i <= 100; i += 10) {
        arr = (int *)malloc(i * sizeof(int));
        if (choice == 1)
            for (j = 0; j < i; j++)
                arr[j] = j + 1;
        else if (choice == 2)
            for (j = 0; j < i; j++)
                arr[j] = i - j;
        else
            for (j = 0; j < i; j++)
                arr[j] = rand() % 100;
        insertion(arr, i);
        fprintf(a, "%d\t%d\n", i, count);
    }
    fclose(a);
}
void main() {
    int choice;
    system("rm -r *.txt");
    while (1) {
        printf("Press 1 for best case\n");
        printf("Press 2 for worst case\n");
        printf("Press 3 for avg case\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
        case 2:
        case 3:
            insertionmain(choice);
            break;
        default:
            exit(1);
        }
    }
}
