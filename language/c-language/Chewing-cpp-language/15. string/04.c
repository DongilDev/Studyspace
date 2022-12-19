#include <stdio.h>

int compare(char* arr1, char* arr2);

int main(void)
{
	char arr1[100];
	char arr2[200];

	printf("두 개의 문자열을 입력하세요\n");
	printf("첫 번째 문자열 : ");
	scanf("%s", arr1);
	printf("두 번째 문자열 : ");
	scanf("%s", arr2);

	if (compare(arr1, arr2)==1)
		printf("같다");
	else
		printf("다르다");
	return 0;
}

int compare(char* arr1, char* arr2)
{
	int i = 0;

	while (arr1[i])
	{
		if (arr1[i] != arr2[i])
			return 0;
		i++;
	}

	if (arr2[i] == NULL)
		return 1;
}