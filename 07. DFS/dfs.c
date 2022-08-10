#include <stdio.h>
#include <stdlib.h>

int cyclic = 0, n;
int *vis, graph[20][20];

void dfs(int cur, int parent) {
    printf("%d  ", cur);
    vis[cur] = 1;

    for (int i = 0; i < n; ++i) {
        if (graph[cur][i]) {
            if (i != parent && vis[i]) {
                cyclic = 1;
            }

            if (!vis[i])
                dfs(i, cur);
        }
    }
}

void main() {
    printf("Enter num. of vertices >> \n");
    scanf("%d", &n);

    vis = (int *)calloc((sizeof(int)), n);

    printf("Enter Adjacency matrix >> ");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &graph[i][j]);

    printf("\n\nConnected Components >> \n");
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
            printf("\n");
        }
    }

    if (cyclic)
        printf("Graph is cyclic\n");
    else
        printf("Graph is acyclic");
}