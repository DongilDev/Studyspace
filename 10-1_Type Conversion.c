#include <stdio.h>

int main()
{
	int i;
	float f;

	printf("실수 입력 : ");
	scanf_s("%f", &f);

	i = (f - (int)f) * 100;

	if (i < 0)
	{
		i *= -1;
	}

	printf("i=%d\n", i);

	return 0;
}
