#include <stdio.h>

int PrimeFactorization(int n)
{
	int i, j;

	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			n /= i;
			printf("%d", i);

			if (n != 1)
			{
				printf("*");
			}

			i = 1;
		}
		
	}

	return 0;
}

int main(void)
{
	int n;
	
	printf("소인수분해를 시킬 n 값 입력 : ");
	scanf_s("%d", &n);

	printf("n = %d  %d =  ", n, n);
	PrimeFactorization(n);
	
	return 0;
}