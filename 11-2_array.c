#include <stdio.h>

int main(void)
{
	int i, j;
	int grade[10];

	for (i = 0; i < 10; i++)
	{
		printf("학생 %d 성적 : ", i + 1);
		scanf_s("%d", &grade[i]);
	}

	for (i = 0; i < 10; i++)
	{
		printf("\n학생 %d ", i + 1);

		for (j = 0; j < grade[i]; j++)
		{
			printf("*");
		}
	}
	printf("\n\n");

	return 0;
}