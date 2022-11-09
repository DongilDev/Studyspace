#include <stdio.h>
#include <stdlib.h>

// arr에 저장되있던 값은 보존하고 add 만큼 늘린 배열(?)을 반환하는 함수
int* append(int* arr, int origin, int add);

int main() {

    int origin;
    int* arr;
    printf("몇 개의 배열 요소를 원하나요? : ");
    scanf("%d", &origin);

    arr = (int*)malloc(sizeof(int) * origin);

    // 임의로 arr 내부 값 지정
    for (int i = 0; i < origin; i++) {
        arr[i] = i; 
    }

    int add;
    printf("몇 개의 배열 요소를 추가 하시겠어요? : ");
    scanf("%d", &add);
    arr = append(arr, origin, add);

    for (int i = 10; i < origin + add; i++) {
        arr[i] = i;
    }

    // arr 내부 값 확인
    for (int i = 0; i < origin + add; i++) { printf("arr[%d] : %d\n", i, arr[i]); }

    return 0;
}

int* append(int* arr, int origin, int add) {
    int* new_arr;
    new_arr = (int*)malloc(sizeof(int) * (origin + add));
    new_arr = arr;
    return new_arr;
}