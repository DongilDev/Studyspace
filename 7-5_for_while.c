#include <stdio.h>

int main(void)
{
	int i, n;
	int result = 1;

	printf("n 값 입력: ");
	scanf_s("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		result *= i;
	}
	printf("\n\n1 부터 입력받는 n 까지의 곱 = %d \n", result);

	return 0;
}