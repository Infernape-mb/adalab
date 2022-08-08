#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 4
#define y 20
int n;
int c;
int count;
struct stack {
    int arr[20];
    int top;
};
typedef struct stack stack;

void push(stack *s, int data) { s->arr[++s->top] = data; }

int isempty(stack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int pop(stack *s) { return s->arr[s->top--]; }

void dfs(int v, int n, int mat[][n], int vis[], stack *s) {
    for (int i = 0; i < n; i++) {
        count++;
        if (mat[v][i] == 1 && vis[i] == 0) {
            vis[i] = 1;
            dfs(i, n, mat, vis, s);
        }
    }
    push(s, v);
}
void dfsmain() {
    FILE *a;
    FILE *b;
    a = fopen("output.txt", "a");
    b = fopen("result.txt", "a");
    int tm = 0;
    srand(time(NULL));
    for (int j = 2; j < 20; j++) {
        stack s;
        s.top = -1;
        n = j;
        tm = 0;
        int arr[n][n];
        int isvis[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            arr[i - 1][i] = 1;
        }
        int vis[n];
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }
        count = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                dfs(i, n, arr, vis, &s);
            }
        }
        fprintf(a, "%d\t%d\n", j, count);
        while (!isempty(&s)) {
            int r = pop(&s);
            fprintf(b, "%d ", r);
        }
        fprintf(b, "\n");
    }
    fclose(a);
}
int main() {
    system("rm -r *.txt");
    dfsmain();
}