#include <iostream>
#include <time.h>

// console input output 헤더파일이다. 
// 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일이다.
#include <conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다. 
	// 공백을 의미하는 값으로 특수한 값을 사용할건데 INT_MAX라는 값을 사용한다.
	// INT_MAX는 이미 정의되어있는 값으로 int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX;

	// 별이 있는 위치를 저장할 변수를 만들어준다.
	int iStarIndex = 24;
	
	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다. 
	// 즉 인덱스는 0 ~ 23번 인덱스 까지만 섞어준다.

	int  iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	
	
	while (true)
	{
		system("cls");
		// i for문이 세로줄을 의미한다.
		for (int i = 0; i < 5; ++i)
		{
			// j for문이 가로 칸을 의미한다.
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}
		
		//true 로 주어서 먼저 모두 맞췄다 라고 가정해둔다.
		bool bWin = true;

		// 퍼즐을 맞추었는지 체크한다.
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}

		cout << "w : 위 s : 아래 a: 왼쪽 d : 오른쪽 q : 종료";
		// _getch() 함수는 문자 1개를 입력 받는 함수이다.
		// 이 함수는 Enter를 치지 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료된다.
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

		switch (cinput)
		{
		case 'w':
		case 'W':
			// 가장 윗줄일 때는 w를 눌러도 위로 올라가서는 안된다.
			if (iStarIndex > 4)
			{
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex - 5] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸 위의 인덱스로 만들어준다.
				iStarIndex -= 5;
			}			
			break;
		case 's':
		case 'S':
			// 가장 아래줄이 아닐 경우 움직인다.
			if (iStarIndex < 20)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;
		case 'a':
		case 'A':
			if (iStarIndex % 5!=0)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				--iStarIndex;
			}
			break;
		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				++iStarIndex;
			}
			break;
		}
	}

	cout <<  endl << "게임을 종료합니다." << endl;
	

	return 0;
}