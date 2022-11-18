#include <stdio.h>

int main() {
    long long int a, m, d, n;
    scanf("%lld%lld%lld%lld", &a,&m,&d,&n);

    for (int i = 2; i <= n; i++) {
        a = a * m + d;
    }
    printf("%lld", a);

    return 0;
}

// CodeUp 모범답안
#include <stdio.h>
int main()
{
    long long i, j;
    long long a, b, b2, c;

    scanf("%lld %lld %lld %lld", &a, &b, &b2, &c);
    for(i=a, j=1; ;j++, i=(i*b)+b2)
        if(j==c) break;

    printf("%lld", i);
    return 0;
}