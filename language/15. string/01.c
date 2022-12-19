#include <stdio.h>

int compare_str(char *str_a, char *str_b);

int main(void)
{
	char str_a[100];
	char str_b[100];

	printf("두 문자열을 비교하는 프로그램입니다 문자열을 두 번 입력해주세요 \n\n");

	printf("첫 번째 문자열 : ");
	scanf("%s", str_a);
	printf("두 번째 문자열 : ");
	scanf("%s", str_b);
	

	printf("%d", compare_str(str_a, str_b));

	return 0;
}

int compare_str(char* str_a, char* str_b)
{
	int i = 0;

	while (str_a[i]!= NULL || str_b[i]!= NULL)
	{
		if (str_a[i] != str_b[i])
			return 0;
		i++;
	}
	

	return 1;
}