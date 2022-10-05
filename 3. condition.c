#include <stdio.h>
#include <time.h>

int main_condition(void)
{
//// 버스틀 탄다고 가정. 학생 / 일반인으로 구분 (일반인 : 20세)

//	int age = 25;
//// if (조건) (...) else (...)
//	if (age >= 20) 
//		printf("일반인 입니다\n");
//	else
//		printf("학생입니다\n");

	// 초등학생(8-13) / 중학생(14-16) / 고등학생(17-19)으로 나누면?
	// if / else if / else
	// && : 양쪽 조건이 모두 만족 할 때 

	/*int age = 25;
	if (age >= 8 && age <= 13)   
	{
		printf("초등학생입니다\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("중학생입니다\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("고등학생입니다\n");
	}
	else
	{
		printf("학생이 아닌가봐요\n");
	}*/
	
	// break / continue
	// 1번부터 30번까지 있는 반에서 1번에서 5번까지 조별 발표를 합니다.
	
	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6)
		{
			printf("나머지 학생은 집에 가세요\n");
			break; // 반복문 탈출
		}
		printf("%d 번 학생은 조별 발표 준비를 하세요\n", i);
	}*/
	
	// 1번부터 30번까지 있는 반에서 7번 학생은 아파서 결석
	// 7번을 제외하고 6번부터 10번까지 조별 발표를 하세요

	/*for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d 번 학생은 결석입니다\n", i);
				continue;  // continue 구문을 넣어서 아래를 생략하고 8번째 학생으로 넘어가게 된다
			}
			printf("%d 번 학생은 조별 발표 준비를 하세요\n", i);
		}
	}*/

	// && ||
	// && 양쪽 둘다 같아야함
	// || (or) 양쪽 중에 하나라도 같으면 됨

	/*int a = 10;
	int b = 10;
	int c = 12;
	int d = 13;
	if (a == b || c == d)
	{
		printf("a 와 b 는 혹은, c 와 d 의 값이 같습니다\n");
	}
	else
	{
		printf("값이 서로 다르네요\n");
	}*/

	// 가위 0 바위 1 보 2

	/*srand(time(NULL));
	int i = rand() % 3;  // 0 ~ 2 반환
	if (i == 0)
	{
		printf("가위\n");
	}
	else if (i == 1)
	{
		printf("바위\n");
	}
	else if (i == 2)
	{
		printf("보\n");
	}
	else
	{
		printf("몰라요\n");
	}*/

	/*srand(time(NULL));
	//int i = rand() % 3;  // 0 ~ 2 반환
	int i = 0;
	switch (i)
	{
	case 0:printf("가위\n"); break; // break문을 안넣으면 다음 구문도 전부 실행된다 
	case 1:printf("바위\n"); break;
	case 2:printf("보\n"); break;
	default:printf("몰라요\n"); break;
	}*/

	/*int age = 8;
	switch (age)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("초등학생입니다\n"); break;
	case 14:
	case 15:
	case 16:printf("중학생입니다\n"); break;
	case 17:
	case 18:
	case 19:printf("고등학생입니다\n"); break;
	default : printf("학생이 아닌가봐요\n"); break;
	}*/

	// Up and Down

	//srand(time(NULL));
	//int num = rand() % 100 + 1; // 1 ~ 100 사이의 숫자 
	//printf("숫자 : %d\n", num);
	//int answer = 0; // 정답
	//int chance = 5; // 기회
	//while (1) // 1 : 참, 0 : 거짓
	//{
	//	printf("남은 기회 %d 번\n", chance--);
	//	printf("숫자를 맞춰보세요 (1~100) : ");
	//	scanf_s("%d", &answer);

	//	if (answer > num)
	//	{
	//		printf("DOWN \n\n");
	//	}
	//	else if (answer < num)
	//	{
	//		printf(" UP \n\n");
	//	}
	//	else if (answer == num)
	//	{
	//		printf("정답입니다! \n\n");
	//		break;
	//	}
	//	else
	//	{
	//		printf("알 수 없는 오류가 발생했어요 \n\n");
	//	}

	//	if (chance == 0)
	//	{
	//		printf("모든 기회를 다 사용하셨네요. 아쉽게 실패했습니다\n");
	//		break;
	//	}
	//}

	return 0;
}