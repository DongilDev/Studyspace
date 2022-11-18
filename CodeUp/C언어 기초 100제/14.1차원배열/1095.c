#include <stdio.h>

int main()
{
    int i, j, k, a[10000] = { 0 };
    int temp;
    scanf("%d", &k);

    for (i = 0; i < k; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < k; i++) {
        for (j = 1; j < k; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("%d", a[0]);

    return 0;
}

// CodeUp 모범답안 ! 
#include <stdio.h>

int main()
{
    int i, j, k;
    int a[10000] = {0};
    int min = 24;
    
    scanf("%d", &k);
    for(i=0; i<k; i++)
    {
        scanf("%d", &a[i]);
        if(min > a[i])
            min  =a[i];
    }
    printf("%d", min);
    return 0;
}