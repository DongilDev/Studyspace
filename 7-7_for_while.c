#include <stdio.h>

int main()
{
	int i, n;
	printf("소인수 분해 시킬 자연수 입력 : ");
	scanf_s("%d", &n);
	printf("\nn = %d  %d = ", n, n);

	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			n /= i;
			printf("%d ", i);
			i = 1;

			if (n != i)
			{
				printf("* ");
			}
		}
	}

	return 0;
}