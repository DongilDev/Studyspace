#include <stdio.h>

int main(void)
{
	int radix, n, i = 0;
	char array[100];

	printf("변환하고 싶은 진법 입력(2~16) : ");
	scanf_s("%d", &radix);

	if (radix < 2 || radix>16)
	{
		printf("2 에서 16진법 까지만 변환 가능합니다 \n");
	}

	printf("변환하고 싶은 수 입력 : ");
	scanf_s("%d", &n);

	while (n >= radix)
	{
		array[i] = n % radix;
		n /= radix;
		i++;
	}

	array[i] = n;

	printf("%d 진법으로 변환된 수 : ", radix);

	for (; i >= 0; i--)
	{
		if (array[i] < 10)
			printf("%c", array[i] + 48);
		else
			printf("%c", array[i] + 55);
	}

	return 0;
}