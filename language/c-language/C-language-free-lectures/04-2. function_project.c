#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main_function_project(void)
{
	// ���� 5���� �ְ�, �� ������ ���� ����� ���� ��� ���� (����)
	// ������ ���, Ʋ���� ����

	srand(time(NULL));
	int count = 0; // ���� ���� ��
	for (int i = 1; i <= 5; i++)
	{
		// x * y = ?
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		//printf("%d x %d ?", num1, num2);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == -1)
		{
			printf("���α׷��� �����մϴ�\n");
			exit(0);
		}
		else if (answer == num1 * num2)
		{
			//����
			success();
			count++;
		}
		else
		{
			//����
			fail();
		}
	}
	
	printf("\n\n ����� 5���� ��й�ȣ �� %d ���� �������ϴ�\n", count);

	return 0;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n####### %d ��° ��й�ȣ ######", level);
	printf("\n\t%d x %d ��? \n\n", num1, num2);
	printf("############################\n");
	printf("\n��й�ȣ�� �Է��ϼ��� (���� : -1) >> ");
}

void success()
{
	printf("\n >>> Good ! �����Դϴ� \n");
}

void fail()
{
	printf("\n >>> �� ! Ʋ�Ƚ��ϴ�\n");
}