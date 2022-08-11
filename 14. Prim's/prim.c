#include <stdio.h>
#include <stdlib.h>

void main() {
    int n;
    printf("Enter num of vertices >> ");
    scanf("%d", &n);
    int graph[n][n];

    printf("Enter the vertices >> ");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &graph[i][j]);

    int *vis = (int *)calloc(sizeof(int), n);

    vis[0] = 1;
    int x, y, min, edge = 0, cost = 0;
    printf("\n\nVertex  ->> Edge \n");
    while (edge < n - 1) {
        min = 99999;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                for (int j = 0; j < n; ++j) {
                    if (!vis[j] && graph[i][j] != 0) {
                        if (min > graph[i][j]) {
                            x = i;
                            y = j;
                            min = graph[i][j];
                        }
                    }
                }
            }
        }
        printf("%d -- %d  ->>  %d\n", x, y, graph[x][y]);
        cost += min;
        vis[y] = 1;
        ++edge;
    }
    printf("\nMST cost >> %d\n", cost);
}