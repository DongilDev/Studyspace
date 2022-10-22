#include <stdio.h>

int add_number(int(*parr)[3]);

int main(void)
{
	int i, j;
	int arr[2][3];

	printf("6 개의 원소를 입력하십시오 \n");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	
	add_number(arr);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
	}

	return 0;
}

int add_number(int(*parr)[3])
{
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			parr[i][j]++;
		}
	}

	return 0;
}