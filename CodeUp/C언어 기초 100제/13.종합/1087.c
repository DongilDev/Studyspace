#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;
    scanf("%d", &n);

    for (i = 1; ; i++) {
        sum += i;
        if (sum >= n) {
            printf("%d", sum);
            break;
        }
    }
 
    return 0;
}