#include <stdio.h>

int main(void)
{
	int i, j;
	int grade[10];
	int temp = 0;

	for (i = 0; i < 10; i++)
	{
		printf("학생 %d 성적 : ", i + 1);
		scanf_s("%d", &grade[i]);
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (grade[i] > grade[j])
			{
				temp = grade[i];
				grade[i] = grade[j];
				grade[j] = temp;
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d 등 점수 : %d \n", i+1, grade[i]);
	}


	return 0;
}