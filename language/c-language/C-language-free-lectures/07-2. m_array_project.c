#include <stdio.h>
#include <time.h>

// 10마리의 서로 다른 동물 (2쌍 씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기 

int arrayAnimal[4][5]; // 카드 지도 (20장의 카드)
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인 

char* strAnimal[10]; // 동물의 이름 캐릭터 포인터형

//char* cPtr = "테스트"; // 테스트라는 글자의 주소를 가진다. 쉽게 접근가능

void initAnimalArray(); // 동물 배열
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition(); // 좌표에서 빈 공간 찾기
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals(); // 동물 위치 출력
void printQuestion(); // 문제 출력 (카드 지도)

int foundAnimals();

int main(void)
{
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0; //실패 횟수

	while (1) // 게임 진행
	{
		int select1 = 0; // 사용자가 선택한 처음 수 
		int select2 = 0; // 사용자가 선택한 두번 째 수 

		printAnimals(); // 동물 위치 출력
		printQuestion(); // 문제 출력 (카드 지도)
		printf("\n");
		printf("뒤집을 카드 2개를 고르시오 : ");
		scanf_s("%d %d", &select1, &select2);
		if (select1 == select2)
		{
			printf("알 수 없는 오류\n");
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 아닌지 확인

		// select 입력은 seq로 들어가니깐 정수좌표(x,y)로 변환해야 한다. 
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// 선택한 카드가 뒤집힌 카드인지 && 두 카드가 같은 동물인지 확인
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&& arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])
		{
			printf("\n\n 빙고! : %s발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		// 뒤집었는데 다른 동물인 경우
		else
		{
			printf("\n\n 땡! (같은 동물이 아니거나 이미 뒤집힌 카드입니다) \n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		// 모든 동물을 찾았는지 1 : 참, 0 : 거짓
		if (foundAnimals() == 1) // foundAnimals()는 foundAnimals 함수의 반환값을 의미 
		{
			printf("\n\n축하합니다! 모든 동물을 다 찾았네요\n");
			printf("지금까지 총 %d 번 실수하였습니다.\n", failCount);
			break;
		}

	}

	return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "토끼";
	strAnimal[1] = "수달";
	strAnimal[2] = "햄스터";
	strAnimal[3] = "다람쥐";
	strAnimal[4] = "여우";

	strAnimal[5] = "강아지";
	strAnimal[6] = "고양이";
	strAnimal[7] = "앵무새";
	strAnimal[8] = "패럿";
	strAnimal[9] = "도마뱀";
}

void shuffleAnimal()
{
	// □□□□□          □■□□□   랜덤으로 2쌍을 뽑고, 거기에다가 동물의 이름을 집어 넣는다. 
	// □□□□□     ->   □□□□□   그래서 for문 2개에 각각 10(동물종류) , 2(개수)를 집어 넣은 거다.
	// □□□□□          □□□■□
	// □□□□□          □□□□□

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// 좌표에서 빈공간을 찾고 값을 반환하는 함수 
int getEmptyPosition()
{
	//                    0 1 2 3 4
	// □ □ □ □ □         0 □ □ □ □ □    
	// □ □ □ □ □     ->  1 □ □ □ □ □   19번 째 숫자는 (3,4)를 의미한다. 
	// □ □ □ □ □         2 □ □ □ □ □   19 / 5 = 3 이고 19 % 5 = 4가 나오기 때문에 x값은 /로 y값은 %로 표현하면 된다.
	// □ □ □ □ □         3 □ □ □ □ ■  

	while (1)
	{
		int randPos = rand() % 20; // 0 ~ 19 사이의 숫자 반환 -> 배열칸이 총 20개임

		// 19 -> (3,4) 로 표시 해야한다. 
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) // -1이면 비어있다는 뜻이다. 
		{
			return randPos;
			// randPro를 반환하면 또 위에서 x,y 값을 구하는 코드가 반복되는데 x,y값을 반환하면 되지 않느냐?
			// 포인터, 구조체 등을 사용하면 그렇게 코드를 구성할 수 있는데 아직 배우지 않아서 이렇게 함
		}
	}

	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5;
}

void printAnimals() // 동물 위치 출력
{
	printf("\n============= 비밀 ===============\n\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n==================================\n\n");
}

void printQuestion() // 문제 출력 (카드 지도)
{
	printf("\n\n 문제 \n\n");
	int seq = 0;
	//                   seq 표시                                      seq 표시         
	// □□□□□          0  1  2  3  4                                  0  1  2  3  4
	// □□□□□     ->   5  6  7  8  9    몇번. 몇번 선택! 정답!  ->    하마  6  7  8  9 
	// □□□□□         10 11 12 13 14                                 10 11 12 하마 14
	// □□□□□         15 16 17 18 19                                 15 16 17 18 19
	//                                       checkAnimal로 확인 ( != 0 )
	//                                           0 0 0 0 0
	//                                           1 0 0 0 0
	//                                           0 0 0 1 0
	//                                           0 0 0 0 0

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 카드를 뒤집어서 정답을 맞추면 '동물 이름'이 나오도록 
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// 정답을 못맞췄으면 뒷면 -> 위치를 나타내는 숫자 -> seq 
			else
			{
				printf("%8d", seq);
			}
			seq++;
			// seq를 0으로 설정했으면 문제 출력이 0으로만 된다. 그래서 for문이 끝날때마다 seq++을 해서 0 1 2로 표현
			// 한다. if, else문 밖에서 한 이유는 해당 조건이 만족 될때만 seq를 ++하면 문제가 발생하기 때문이다. 

		}
		printf("\n");
	}
}

int foundAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0) // 아직 못찾은게 하나라도 있다면 0을 반환
				return 0;
		}
	}

	return 1; // 모두 다 찾음
}