#include <stdio.h>

int factorial(int n);

int main(void)
{
	int n;
	
	printf("1 부터 n 까지의 곱을 구하세요 \n");
	printf("n 값 입력 : ");
	scanf_s("%d", &n);
	printf("1 부터 n 까지의 곱 : %d", factorial(n));

	return 0;
}

int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n* factorial(n - 1);
}