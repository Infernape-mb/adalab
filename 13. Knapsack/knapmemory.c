#include <stdio.h>
#include <stdlib.h>

int T[10][10], V[10] = {0}, W[10] = {0};

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int knap(int i, int j) {
    int value;
    if (T[i][j] == -1) {
        if (j < W[i])
            value = knap(i - 1, j);
        else
            value = max(knap(i - 1, j), V[i] + knap(i - 1, j - W[i]));
        T[i][j] = value;
    }
    return T[i][j];
}

void main() {
    int n, m;
    printf("Enter num of items >> ");
    scanf("%d", &n);
    printf("Enter capacity of sack >> ");
    scanf("%d", &m);
    printf("Enter weight and value >>\n");
    for (int i = 1; i < n + 1; ++i)
        scanf("%d%d", &W[i], &V[i]);

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            if (i == 0 || j == 0)
                T[i][j] = 0;
            else
                T[i][j] = -1;
        }
    }

    printf("\nMaximum value of sack >> %d\n", knap(n, m));
    printf("TABLE --> \n");
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j)
            printf("%d\t", T[i][j]);
        printf("\n");
    }
    printf("\nComposition of sack >> \n");
    for (int i = n; i > 0; --i) {
        if (T[i][m] != T[i - 1][m]) {
            printf("%d  ", i);
            m = m - W[i];
        }
    }
}