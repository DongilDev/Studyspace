#include <stdio.h>

int main()
{
	int i, j, k, n;

	printf("몇 줄인 삼각형을 원하는가? \n");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-i; j++)
		{
			printf(" ");
		}

		for (k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}