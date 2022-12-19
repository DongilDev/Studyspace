#include <stdio.h>

int main() {
    int a, d, n;
    scanf("%d%d%d", &a, &d, &n);

    for (int i = 2; i <= n; i++) {
        a += d;
    }
    printf("%d", a);

    return 0;
}

// CodeUp 모범답안
#include <stdio.h>
int main(){
    int i, j, a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(i=a, j=1; ;j++, i+=b)
        if(j==c) break;
    printf("%d", i);
    return 0;
}