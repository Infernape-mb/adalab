// to analyse the order of growth of basic operation of the algorithm for string
// matching using actual chars
#include <stdio.h>
#include <stdlib.h>

void match(int ch) {
    FILE *f;
    int i, j, k, count;
    char *pat;
    char a[5] = "aaaa", b[5] = "aaab", c[5] = "aaac";
    switch (ch) {
    case 1:
        f = fopen("strbest.txt", "w");
        break;
    case 2:
        f = fopen("stravg.txt", "w");
        break;
    case 3:
        f = fopen("strworst.txt", "w");
        break;
    }
    for (i = 100; i <= 1000; i += 100) {
        char *arr = malloc(i * sizeof(char));
        for (j = 0; j < i; j++)
            arr[j] = 'a';
        arr[i / 2] = 'b';
        switch (ch) {
        case 1:
            pat = a;
            break;
        case 2:
            pat = b;
            break;
        case 3:
            pat = c;
            break;
        }
        count = 0;
        for (j = 0; j <= i - 4; j++) {
            for (k = 0; k < 4; k++) {
                count++;
                if (pat[k] != arr[j + k])
                    break;
            }
            if (k == 4)
                break;
        }
        fprintf(f, "%d\t%d\n", i, count);
    }
    fclose(f);
}
void main() {
    for (int i = 1; i <= 3; i++) {
        match(i);
    }
}