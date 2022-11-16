#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (a > 0) {
        if (a % 2 == 0) {
            printf("plus \n");
            printf("even");
        }
        else {
            printf("plus \n");
            printf("odd");
        }   
    }
    else if (a < 0) {
        if (a % 2 == 0) {
            printf("minus \n");
            printf("even");
        }
        else {
            printf("minus \n");
            printf("odd");
        }
    }
    else {
        printf("0 은 정수 0 입니다.");
    }

    return 0;
}