#include <stdio.h>

int max_number(int* parr);

int main(void)
{
	int arr[10];
	int i;

	printf("10 개의 원소 입력 : ");
	
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	max_number(arr);

	printf("입력받은 원소들을 큰 순서대로 정렬 \n\n");

	for (i = 0; i <10; i++)
	{
		printf("%d \n", arr[i]);
	}

	return 0;
}

int max_number(int* parr)
{
	int i,j;
	int temp;
	for (i = 0; i < 10; i++)
	{
		for (j = i+1; j < 10; j++)
		{
			if (parr[i] < parr[j])
			{
				temp = parr[j];
				parr[j] = parr[i];
				parr[i] = temp;
			}
		}
	}

	return 0;
}