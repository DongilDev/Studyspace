#include <stdio.h>

void change(char* arr);

int main(void)
{
	char arr[100];

	printf("문자열을 입력하세요(최대100) \n");
	scanf("%s", arr);

	change(arr);

	return 0;
}

void change(char* arr)
{
	char c;
	while (*arr)
	{
		if (*arr >= 65 && *arr <= 90)
			printf("%c", *arr + 32);
		else if (*arr >= 97 && *arr <= 122)
			printf("%c", *arr - 32);
		else
			printf("%c", *arr);
		arr++;
	}
}