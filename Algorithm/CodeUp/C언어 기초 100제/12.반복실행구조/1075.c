#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    while (n>=1 && n<=100) {
        n--;
        printf("%d \n", n);
    }

    return 0;
}