#include <stdio.h>

int main_array(void)
{
	// 배열
	
	//int subway_1 = 30; //지하철 1호차에 30명이 타고 있다.
	//int subway_2 = 40;
	//int subway_3 = 50;
	//printf("지하철 1호차에 %d 명이 타고 있습니다\n", subway_1);
	//
	//printf("지하철 1호차에 %d 명이 타고 있습니다\n", subway_2);
	//printf("지하철 1호차에 %d 명이 타고 있습니다\n", subway_3);

	// 여러 개의 변수를 함께, 동시에 생성
	// 
	//int subway_array[3];  // [0] [1] [2] 
	//subway_array[0] = 30;
	//subway_array[1] = 40;
	//subway_array[2] = 50;

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("지하철 %호차에 %d 명이 타고 있습니다\n", i + 1, subway_array[i]);
	//}

	// 값 설정 방법
	//
	/*int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}*/

	// 초기화를 하지 않으면 더미(쓰레기)값
	// 값은 초기화를 반드시 해야 함
	//
	/*int arr[10]; 
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}*/

	// 배열 크기는 항상 산수로 선언

	/*int size = 10;
	int arr[10];*/

	//int arr[10] = { 1, 2 }; // 3번째 값부터는 자동으로 '0'으로 초기화 됨
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n", arr[i]);
	//}
	
	// int arr[] = { 1, 2 }; // arr[2]
	
	/*float arr_f[5] = { 1.0f, 2.0f, 3.0f };
	for (int i = 0; i < 5; i++)
	{
		printf("%.2f\n", arr_f[i]);
	}*/

	// 문자 vs 문자열
	
	/*char c = 'A';
	printf("%c\n", c);*/

	// 문자열 끝에는 '끝'을 의미하는 NULL 문자 '\0' 이 포함되어야 함

	//char str[6] = "coding"; // [c][o][d][i][n][g][\0]

	/*char str[7] = "coding";
	printf("%s\n", str);*/

	//char str[] = "coding";
	///*printf("%s\n", str);
	//printf("%d\n", sizeof(str));*/

	//for (int i = 0; i < sizeof(str); i++)
	//{
	//	printf("%c\n", str[i]);
	//}

	//char kor[] = "나도코딩"; // 8 byte + 1 byte (문자 끝)  
	//printf("%s\n", kor);
	//printf("%d\n", sizeof(kor));
	// 영어 1글자 : 1 byte
	// 한글 1글자 : 2 byte
	// char 크기 : 1 byte

	//char c_array[7] = { 'c', 'o', 'd', 'i', 'n', 'g', '\0' };
	/*char c_array[6] = { 'c', 'o', 'd', 'i', 'n', 'g', };
	printf("%s\n", c_array);*/

	char c_array[10] = { 'c', 'o', 'd', 'i', 'n', 'g', };
	//printf("%s\n", c_array);
	/*for (int i = 0; i < sizeof(c_array); i++)
	{
		printf("%c\n", c_array[i]);
	}*/

	//for (int i = 0; i < sizeof(c_array); i++)
	//{
	//	printf("%d\n", c_array[i]); // ascll 코드 값 출력 (null 문자 0 으로 입력
	//}
	
	// 문자열 입력받기 : 경찰서 조서 쓰기 예제
	/*char name[256];
	printf("이름이 뭐에요? ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);*/

	// 참고 : ASC|| 코드? ANSI (미국표준협회) 에서 제시한 표준 코드 체계
	// 7bit, 총 128 개 코드 (0~127)
	// a : 97 (문자 a 의 아스키 코드 정수값)
	// A : 65
	// 0 : 48

	//printf("%c\n", 'a');
	//printf("%d\n", 'a');

	//printf("%c\n", 'b');
	//printf("%d\n", 'b');

	//printf("%c\n", 'A');
	//printf("%d\n", 'A');

	//printf("%c\n", '\0');
	//printf("%d\n", '\0');

	//printf("%c\n", '0');
	//printf("%d\n", '0');

	//printf("%c\n", '1');
	//printf("%d\n", '1');

	// 참고2 : 0~127 사이의 아스키코드 정수값에 해당하는 문자 확인
	/*for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 정수 %d : %c\n", i, i);
	}*/

	return 0;
}