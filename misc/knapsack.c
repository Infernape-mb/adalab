/* A Naive recursive implementation
of 0-1 Knapsack problem */
#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be
// put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] =
                    max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

// Driver program to test above function
int main() {
    int n, W;
    int val[20];
    int wt[20];

    printf("Enter the total number of items");
    scanf("%d", &n);

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
    n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}