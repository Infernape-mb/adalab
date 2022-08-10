#include <stdio.h>
#include <stdlib.h>

int a[20][20], visited[20], q[20], i, j, n, f = 0, r = -1, acyclic = 1;

void bfs(int v) {
    for (i = 1; i <= n; i++) {
        if (a[v][i] && visited[i]) {
            acyclic = 0;
            printf("%d->%d\n", v, i);
        }
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
            printf("%d->%d\n", v, i);
        }
    }
    if (r >= f) {
        visited[q[r]] = 1;
        bfs(q[f++]);
    }
}

void connectandcyclic() {
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
    if (acyclic) {
        printf("\nGraph is acyclic");
    } else {
        printf("\nGraph is cyclic");
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
    visited[start] = 1;
    bfs(start);
    connectandcyclic();
}