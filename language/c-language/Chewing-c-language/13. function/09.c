#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
	int a, b;
	printf("최대공약수를 구하고 싶은 두 수를 입력하세요\n");
	scanf_s("%d %d", &a, &b);


	printf("두 수의 최대공약수 : %d", gcd(a, b));

	return 0;
}

int gcd(int a, int b)
{
	int temp, n;
	
	if (a<b) 
	{
		temp = a;
		a = b;
		b = temp;
	}

	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}