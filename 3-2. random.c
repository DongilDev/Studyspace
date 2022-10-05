#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int main_random(void)
{
	//srand(time(NULL)); // 난수 초기화
	//int num = rand() % 3; // 0 ~ 2
	
	printf("난수 초기화 이전...\n"); // 매 실행마다 같은 숫자가 나옴
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL)); // 난수 초기화  (매번 다른 숫자가 나오게 됨)
	printf("\n\n난수 초기화 이후..\n");  
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);
	
	return 0;
}