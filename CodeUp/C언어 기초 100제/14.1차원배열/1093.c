#include <stdio.h>

int main() {
    int n, i, t;
    int array[23] = {0};
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &t);
        array[t-1] = array[t-1] + 1;
    }

    for (i = 0; i <= 22; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}

// Code Up 모범답안 
#include <stdio.h>

int i, j, k, a[24];
    
int main()
{
    scanf("%d", &k);
    
    for(i=0; i<k; i++)
    {
        scanf("%d", &j);
        a[j]++;
    }
    
    for(i=1; i<=23; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}