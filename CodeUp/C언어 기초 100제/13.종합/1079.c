#include <stdio.h>

int main()
{
    char c = 'a';
    
    while (c != 'q') {
        scanf("%c", &c);
        if (c == 'q') {
            printf("%c", c);
            break;
        }
        printf("%c", c);
    }

    return 0;
}