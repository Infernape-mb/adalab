/* A Naive recursive implementation
of 0-1 Knapsack problem */
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be
// put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                K[i][j] = 0;
            } else if (j >= wt[i - 1]) {
                K[i][j] =
                    max(K[i - 1][j], K[i - 1][j - wt[i - 1]] + val[i - 1]);
            } else {
                K[i][j] = K[i - 1][j];
            }
        }
    }
    return K[n][W];
}

// Driver program to test above function
int main() {
    int n, W;
    int *val;
    int *wt;

    printf("Enter the total number of items");
    scanf("%d", &n);
    val = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    printf("Enter the capacity of the knapsack");
    scanf("%d", &W);

    printf("Enter weight of %d items in ascending order", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    printf("Enter value of %d items in the same order", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    printf("The maximum value that can be carried in the bag is %d",
           knapSack(W, wt, val, n));

    return 0;
}