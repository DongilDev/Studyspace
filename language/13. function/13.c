#include <stdio.h>

int IsPrimeNumber(int n);

int main(void)
{
	int n;

	printf("1부터 n 까지의 소수를 구하는 프로그램 입니다. \n");
	printf("n 값 입력 : ");
	scanf_s("%d", &n);

	if (n < 2 || n>1000)
	{
		printf("2 이상 1000 이하 의 값만 가능합니다 \n");
		return 0;
	}

	IsPrimeNumber(n);


	return 0;
}

int IsPrimeNumber(int n)
{
	int i, j;
	int arr[1001];

	for (i = 2; i <= n; i++)	
	{
		arr[i] = i;
	}

	for (i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
			continue;
		for (j = i + i; j <= n; j += i)
		{
			arr[j] = 0;
		}
		printf("%d ", arr[i]);
	}

	return 0;
}