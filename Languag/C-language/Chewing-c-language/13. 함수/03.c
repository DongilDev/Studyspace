#include <stdio.h>

int total(int n)
{
	int i, sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

int main(void)
{
	int n;
	printf("1부터 n까지 합에서 n 값 : ");
	scanf_s("%d", &n);
	
	printf("1부터 n까지의 합 : %d \n", total(n));

	return 0;
}