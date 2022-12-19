#include <stdio.h>

void reverse(char* arr);

int main(void)
{
	char arr[100];

	printf("문자열을 입력하세요(최대100) \n");
	scanf("%s", arr);

	reverse(arr);

	return 0;
}

void reverse(char* arr)
{
	int i = 0;

	while (*arr)
	{
		arr++;
		i++;
	}

	arr--;

	while (i)
	{
		printf("%c", *arr);
		arr--;
		i--;
	}
}