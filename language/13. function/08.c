#include <stdio.h>

int average(int (*pstudent)[3]);

int main(void)
{
	int student[5][3]; //학생 5 명의 국어,수학,영어 점수
	int i, j; 

	printf("국어, 영어, 수학 점수를 차례대로 입력하세요 \n\n");

	for (i = 0; i < 5; i++)
	{
		printf("학생 %d : ", i + 1);
		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &student[i][j]);
		}
	}
	
	printf("\n");

	average(student);

	return 0;
}

int average(int(*pstudent)[3])
{
	float aver[5]; // 학생 5 명의 평균 점수 
	float average = 0; // 학생 한명 평균 점수
	float totalaver = 0; // 모든 학생 점수를 더하고 난 평균점수
	int i, j;
	int temp = 0; 

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			average += pstudent[i][j];
		}
		average /= 3; // 학생 한명 평균 점수가 구해짐 
		printf("학생 %d 의 평균점수 : %.2f \n", i+1, average);
		aver[i] = average; // 구해진 평균 점수를 5 명의 평균 점수 배열에 넣음 
		totalaver += aver[i]; // 모든 학생의 평균을 더하기
		average = 0; // 0 으로 초기화 시켜서 다음 학생의 평균 점수 구하기 
	}

	totalaver /= 5;
	printf("\n학생 5 명의 평균 점수 : %.2f \n\n", totalaver);

	for (i = 0; i < 5; i++) // 학생 5 명의 평균 점수를 높은 사람부터 낮은 사람 순으로 정렬
	{
		for (j = i+1; j < 5; j++)
		{
			if (aver[i] < aver[j])
			{
				temp = aver[j];
				aver[j] = aver[i];
				aver[i] = temp;
			}
		}
	}

	for (i = 0; i < 5; i++) // 학생 5 명의 평균 점수를 출력하고 합격인지 불합격인지 알리기 
	{
		if (aver[i] >= totalaver)
		{
			printf("%.2f 합격\n", aver[i]);
		}

		else
		{
			printf("%.2f 불합격\n", aver[i]);
		}
	}

	return 0;
}