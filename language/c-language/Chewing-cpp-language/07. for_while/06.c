#include <stdio.h>

int main(void)
{
	int a, b, c;
	int sum = 0;

	for (a = 1; a < 2000; a++)
	{
		for (b = 1; b < a; b++)
		{
			for (c = 1; c < b; c++)
			{
				if (a + b + c == 2000)
				{
					sum++;
				}
			}
		}
	}
	printf("%d", sum);

	return 0;
}