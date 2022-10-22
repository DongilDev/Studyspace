#include <stdio.h>

int PrimeNumber(int n)
{
	int i, j; // for문 돌리기
	int prime = 0; // 소수 개수 
	int totalprime = 0; // 총 소수 개수

	for (i = 2; i <= n; i++)
	{
		for (j = 2; j <= i; j++)
		{
			if (i % j == 0)
			{
				prime++;
			}
		}

		if (prime == 1)
		{
			totalprime++;
		}

		prime = 0;
	}
	return totalprime;
}

int main(void)
{
	int n;

	printf("1 부터 n 까지의 소수의 개수를 알려드립니다 \n");
	printf("n 값 입력 : ");
	scanf_s("%d", &n);

	printf("1 부터 %d 까지의 소수의 개수는 : %d \n", n, PrimeNumber(n));


	return 0;
}