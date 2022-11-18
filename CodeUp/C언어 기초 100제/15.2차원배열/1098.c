#include <stdio.h>

int main() {
    int h, w, n;
    int l, d, x, y;
    int i, j;
    int a[101][101] = { 0 };
    scanf("%d%d", &h, &w);
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &l, &d, &x, &y);
        for (j = 0; j < l; j++) {
            if (d == 0)
                a[x][y + j] = 1;
            else
                a[x + j][y] = 1;
        }
    }

    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}