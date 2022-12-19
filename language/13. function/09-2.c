#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
	int gcd_number[50];
	int i, n;
	int result = 0;

	printf("원하는 자연수들의 최대공약수를 구하는 프로그램입니다. \n");
	printf("몇 개의 수를 입력하시겠습니까? (최대 50개) : ");
	scanf_s("%d", &n);

	printf("원하는 수를 입력하세요\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &gcd_number[i]);
	}
	
	result = gcd_number[0];

	for (int i = 1; i < n; i++)
	{
		result = gcd(result, gcd_number[i]);
	}

	printf("최대공약수 : %d \n", result);
	

	return 0;
}

int gcd(int a, int b)
{
	int temp, r;

	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}