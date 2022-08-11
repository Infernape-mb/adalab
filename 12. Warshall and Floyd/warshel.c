#include <stdio.h>
#include <stdlib.h>
int n;
void warshel(int a[][n]) {
    // completed calulating d0 matrix;
    // we are usign a as a previous  matrix and current as a current matrix
    for (int k = 0; k < n; k++) {
        int current[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                current[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
        // updating the previous before loosing current
        // to mainting the space complexity of v square only
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                a[u][v] = current[u][v];
            }
        }
    }
}
int main() {
    printf("Enter the order of a matrix \n");
    scanf("%d", &n);
    int a[n][n];
    printf("ENter the adjacence matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The input matrix is \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    warshel(a);

    printf("The transitive closure matrix is \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}