#include <stdio.h>

int plus(int* p_result);
int minus(int* p_result);
int multiply(int* p_result);
int divide(int* p_result);
int reset(int* p_result);

int main(void)
{
	int n;
	int result = 0;

	for (;;)
	{
		printf("1 을 누르면 +\n");
		printf("2 를 누르면 -\n");
		printf("3 을 누르면 *\n");
		printf("4 를 누르면 /\n");
		printf("5 를 누르면 초기화\n");
		printf("0 을 누르면 종료 입니다 \n");
		scanf_s("%d", &n);

		switch (n)
		{
		case 1:
			plus(&result);
			break;
		case 2:
			minus(&result);
			break;
		case 3:
			multiply(&result);
			break;
		case 4:
			divide(&result);
			break;
		case 5:
			reset(&result);
			break;
		case 0:
			return 0;
		default:
			printf("\n잘못 입력하셨습니다\n\n");
			continue;
		}
	}

	return 0;
}

int plus(int* p_result)
{
	int n;

	printf("\n더하고 싶은 값을 입력하세요 \n");
	scanf_s("%d", &n);

	*p_result += n;
	printf("현재 값 : %d \n\n", *p_result);

	return 0;
}

int minus(int* p_result)
{
	int n;

	printf("\n빼고 싶은 값을 입력하세요 \n");
	scanf_s("%d", &n);

	*p_result -= n;
	printf("현재 값 : %d \n\n", *p_result);

	return 0;
}

int multiply(int* p_result)
{
	int n;

	printf("\n곱하고 싶은 값을 입력하세요 \n");
	scanf_s("%d", &n);

	*p_result *= n;
	printf("현재 값 : %d \n\n", *p_result);

	return 0;
}

int divide(int* p_result)
{
	int n;

	printf("\n나누고 싶은 값을 입력하세요 \n");
	scanf_s("%d", &n);

	*p_result /= n;
	printf("현재 값 : %d \n\n", *p_result);

	return 0;
}

int reset(int* p_result)
{
	int n = 0;

	printf("\n값을 초기화 시킵니다\n");
	*p_result = n;
	printf("현재 값 : %d \n\n", *p_result);

	return 0;
}