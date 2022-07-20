#include <stdio.h>
#include <stdlib.h>
int a[20][20], visited[20], n;

void dfs(int v) {
    int i;
    visited[v] = 1;
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            printf("\n%d->%d", v, i);
            dfs(i);
        }
    }
}

void connect() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            count++;
        }
    }
    if (count == n) {
        printf("\nGraph is connected");
    } else {
        printf("\nGraph is not connected");
    }
}

int main() {
    int i, j;
    int start;
    printf("enter the number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) // Setup
    {
        visited[i] = 0;
    }
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter the starting vertex:");
    scanf("%d", &start);
    dfs(start);
    printf("\n");
    connect();
}