#include <stdio.h>

int main_printfscanf(void)
{

	// printf("Hello World \n");

	// 정수형 변수에 대한 예제
	/*int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);*/

	// 실수형 변수에 대한 예제
	/*float f = 46.5f;
	printf("%.2f\n", f);
	double d = 4.428;
	printf("%.2lf\n", d);*/

	// const int YEAR = 2000; // 상수
	// printf("태어난 년도 : %d\n", YEAR);
	// YEAR = 2001;

	// printf
	// 연산
	//int add = 3 + 7; // 10
	//printf("3 + 7 = %d\n", add);
	//printf("%d x %d = %d\n", 30, 79, 30 * 79);

	// scanf
	// 키보드 입력을 받아서 저장
	/*int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	printf("입력값 : %d\n", input);*/ 
	
	/*int one, two, three;
	printf("3개의 정수를 입력하세요 : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("첫번째 값 : %d\n", one);
	printf("두번째 값 : %d\n", two);
	printf("세번째 값 : %d\n", three);*/

	// 문자(한 글자), 문자열(한 글자 이상의 여러 글자)
	/*char c = 'A';
	printf("%c\n", c);*/
	
	/*char str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);*/

	// 프로젝트
	// 경찰관이 범죄자의 정보를 입수 (조서 작성)
	// 이름? 나이? 몸무게? 키? 범죄명?
	//char name[256];
	//printf("이름이 뭐에요? ");
	//scanf_s("%s", name, sizeof(name));

	//int age;
	//printf("몇살이에요? ");
	//scanf_s("%d", &age);

	//float weight;
	//printf("몸구게는 몇 kg 이에요? ");
	//scanf_s("%f", &weight);

	//double height;
	//printf("키는 몇 cm 이에요? ");
	//scanf_s("%lf", &height);

	//char what[256];
	//printf("무슨 범죄를 저질렀어요? ");
	//scanf_s("%s", what, sizeof(what));

	//// 조서 내용 출력
	//printf("\n\n--- 범죄자 정보 --- \n\n");
	//printf(" 이름    : %s\n", name);
	//printf(" 나이    : %d\n", age);
	//printf(" 몸무게  : %.2f\n", weight);
	//printf(" 키      : %.2lf\n", height);
	//printf(" 범죄    : %s\n", what);

	// ++
	/*int a = 10;
	printf("a 는 %d\n", a);
	a++;
	printf("a 는 %d\n", a);
	a++;
	printf("a 는 %d\n", a);*/

	//int b = 20;
	//// b = b + 1;
	//printf("b 는 %d\n", ++b);
	//printf("b 는 %d\n", b++);
	//printf("b 는 %d\n", b);

	//반복문
	// for, while, do whiel

	//for (선언: 조건; 증감) { }
	/*for (int i = 1; 1 <= 10; i++)
	{
		printf(" Hello World %d\n", i++);	
	}*/

	// while (조건) { }
	//int i = 1;
	//while (i <= 10)
	//{
	//	printf(" Hello World %d\n", i++);
		//i++
	//}

	// do { } while (조건);

	/*int i = 1;
	do {
		printf(" Hello World %d\n", i++);
	} while (i <= 10);*/

	// 2중 반복문
	/*for (int i = 1; i <= 3; i++)
	{
		printf("첫 번째 반복문 : %d\n", i);

		for (int j = 1; j <= 5; j++)
		{
			printf("   두 번째 반복문 : %d\n", j);
		}
	}*/

	//구구단
	// 2 x 1 = 2
	// 2 x 2 = 4
	// 2 x 3 = 6
	// 2 x 4 = 8
	// ... 
	// 9 x 9 = 81
	/*for (int i = 2; i <= 9; i++)
	{
		printf("%d단 계산\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf(" %d x %d = %d\n", i, j, i * j);
		}
	}*/

	// 이중 반복문 파헤치기  (별 찍기)
	/*
	*
	**
	***
	****
	*****
	*/

	/*for (int i = 0; i < 5; i++)
	{
		{
			for (int j = 0; j <= i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}*/
	
	/*
	     *
	    **
	   ***
	  ****
	 *****
	*/

	/*
	SSSS*
	SSS**
	SS***
	S****
	*****
	*/

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5 - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
		}*/

// 피라미드를 쌓아라 - 프로젝트

/*

SSSS*
SSS***
SS*****
S*******
*********
 
*/

	/*int floor;
	printf("몇 층으로 쌓겠느냐?");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}*/

 


	return 0;
}