#include <stdio.h>

int main() {
    long long int h, b, c, s;
    double result = 0;
    scanf("%lld %lld %lld %lld", &h, &b, &s, &c);
    result = h * b * s * c;
    printf("%.1lf MB", result / 8 / 1024 / 1024);

    return 0;
}