#include <stdio.h>
#include <stdlib.h>
int n;
int count;
int min(int a, int b) { return (a < b) ? a : b; }
void floyd(int a[][n]) {
    // completed calulating d0 matrix;
    // we are usign a as a previous  matrix and current as a current matrix
    for (int k = 0; k < n; k++) {
        int current[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count++;
                current[i][j] = min(a[i][j], (a[i][k] + a[k][j]));
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
    /*printf("Enter the order of a matrix \n");
    scanf("%d",&n);
    int a[n][n];
    printf("ENter the adjacence matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    floyd(a);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
    */
    FILE *a;
    system("rm -r *.txt");
    a = fopen("output.txt", "a");
    for (int c = 4; c < 12; c++) {
        n = c;
        int arr[n][n];
        count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = __INT32_MAX__;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    arr[i][j] = 0;
                } else {
                    int temp1 = rand() % 2;
                    arr[i][j] = temp1;
                }
            }
        }
        floyd(arr);
        fprintf(a, "%d\t%d\n", c, count);
    }
}