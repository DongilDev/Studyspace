#include <stdio.h>

int main()
{
    char c, t = 'a';
    scanf("%c", &c);

    do {
        printf("%c ", t);
        t++;
    } while (t <= c);

    return 0;
}