#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dfs(int v, int n, int mat[][n], int vis[]) {
    for (int i = 0; i < n; i++) {
        if (mat[v][i] == 1 && vis[i] == 0) {
            vis[i] = 1;
            printf("%d->", i);
            dfs(i, n, mat, vis);
        }
    }
}
void main() {
    int n, tm = 0, e, p, q, c = 0;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    tm = 0;
    int arr[n][n];
    int isvis[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("\nEnter the end vertices of %d edges(v1 v2) :\n ", e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &p, &q);
        arr[p][q] = 1;
    }
    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    c = 0;
    printf("displaying the connected componenets\n");
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            printf("\nnew connected graph is \n");
            c++;
            printf("%d->", i);
            dfs(i, n, arr, vis);
            printf("\n");
        }
    }
    if (c == 1) {
        printf("\nthe graph is connected\n");
    } else {
        printf("the graph is not connected\n");
    }
}