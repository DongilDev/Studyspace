#include <stdio.h>

int main()
{
    int n, i, sum = 0;
    scanf("%d", &n);
    
    for (i = 1; i<n; i++) {
        if (sum < n) {
            sum += i;
        }
        if (sum >= n) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}