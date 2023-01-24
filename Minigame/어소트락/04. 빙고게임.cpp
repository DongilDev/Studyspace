#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

void SetNumber(int* pArray);
void Shuffle(int* pArray);
AI_MODE SelectAIMode();
void OutputNumber(int* pArray, int iBingo);
bool ChangeNumber(int* pArray, int iInput);
int SelectAINumber(int* pArray, AI_MODE eMode);
int BingoCounting(int* pArray);
int BingoCountingH(int* pArray); 
int BingoCountingV(int* pArray); 
int BingoCountingLTD(int* pArray);
int BingoCountingRTD(int* pArray);

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	SetNumber(iNumber);
	SetNumber(iAINumber);

	Shuffle(iNumber);
	Shuffle(iAINumber);
	
	int iBingo = 0, iAIBingo = 0;

	AI_MODE eAIMode = SelectAIMode();		

	while (true)
	{
		system("cls");

		// 숫자를 5 x 5 로 출력한다.
		cout << "=============== Player =================" << endl;
		OutputNumber(iNumber, iBingo);
		
		cout << "=============== AI =================" << endl;
		OutputNumber(iAINumber, iAIBingo);

		switch (eAIMode)
		{
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}

		// 줄수가 5 이상일 경우 게임을 종료한다.
		if (iBingo >= 5)
		{
			cout << "Player 승리" << endl;
			break;
		}
		else if (iAIBingo >= 5)
		{
			cout << "AI 승리" << endl;
			break;
		}

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput > 25)
			continue;

		// 중복입력을 체크하기 위한 변수이다.
		// 기본적으로 중복되었다라고 하기위해 true 로 잡아주었다.
		bool bAcc = ChangeNumber(iNumber, iInput);			

		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 바꾸지 못했으므로 
		// 다시 입력받게 continue 해준다.
		if (bAcc)
			continue;	

		// 중복이 아니라면 AI의 숫자도 찾아서 *로 바꿔준다.
		ChangeNumber(iAINumber, iInput);		

		// AI가 숫자를 선택한다. AI모드에 맞춰서 선택되도록 함수가 구성되어있다.
		iInput = SelectAINumber(iAINumber, eAIMode);		

		// AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꿔준다.
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAINumber, iInput);

		// 빙고 줄 수를 체크하는것은 매번 숫자를 입력할때마다 처음부터 새로 카운트를  할 것이다.
		// 그러므로 iBingo 변수를 0으로 매번 초기화하고 새롭게 줄 수를 구해주도록 한다.
		iBingo = BingoCounting(iNumber);
		iAIBingo = BingoCounting(iAINumber);
	}
	return 0;
}

void SetNumber(int* pArray)
{
	for (int i = 0; i < 25; ++i)
	{
		pArray[i] = i + 1;
	}
}

void Shuffle(int* pArray)
{
	int  iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;		
	}
}

AI_MODE SelectAIMode()
{
	int iAIMode;

	while (true)
	{
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선택하세요 : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}

	return (AI_MODE)iAIMode;
}

void OutputNumber(int* pArray, int iBingo)
{	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (pArray[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
				cout << int(pArray[i * 5 + j]) << "\t";
		}

		cout << endl;
	}

	cout << "Bingo Line : " << iBingo << endl << endl;
}

bool ChangeNumber(int* pArray, int iInput)
{
	// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지를 찾아낸다.
	for (int i = 0; i < 25; ++i)
	{
		// 같은 숫자가 있을 경우
		if (iInput == pArray[i])
		{			
			// 숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
			pArray[i] = INT_MAX;

			return false;
		}
	}

	// 여기까지 오게 되면 return false 가 동작 안된 것으로 같은 숫자가 없다는 뜻
	// 즉 중복된 숫자를 입력했기 때문에 true 를 리턴한다.

	return true;
}

int SelectAINumber(int* pArray, AI_MODE eMode)
{
	// 선택 안된 목록 배열을 만들어준다.
	int iNoneSelect[25] = {};
	// 선택 안된 숫작 개수를 저장한다.
	int iNoneSelectCount = 0;
	
	// AI가 선택을 한다. AI 가 선택하는 것은 AI 모드에 따라서 달라진다
	switch (eMode)
	{
		// AI Easy 모드는 현재 AI의 숫자목록중 *로 바뀌지 않은 숫자 목록을 만들어서
		// 그 목록중 하나를 선택하게 한다.(랜덤하게)

	case AM_EASY:
		// 선택 안된 숫자목록을 만들어준다
		// 선택 안된 숫자 개수는 목록을 만들 때 카운팅해준다.
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i)
		{
			// 현재 숫자가 *이 아닐 경우
			if (pArray[i] != INT_MAX)
			{
				// *이 아닌 숫자일 경우 iNoneSelectCount를 인덱스로 활용한다.
				// 선택 안된 목록에 추가할때마다 개수를 1씩 증가시켜서 총 선택 안된 개수를 구해준다.
				// 그런데 0부터 카운트가 시작이므로 0번에 넣고 ++해서 1개 추가되었다라고 해준다.
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}

		// for문을 빠져나오게 되면 선택안된 목록이 만들어지고 선택안된 목록의 개수가 만들어지게 된다.
		// 선택안된 목록의 숫자중 랜덤한 하나의 숫자를 얻어오기 위해 인덱스를 랜덤하게 구해준다.
		return iNoneSelect[rand() % iNoneSelectCount];

	case AM_HARD:
		// 하드모드는 현재 숫자중 빙고줄 완성 가능성이 가장 높은 줄을 찾아서 그 줄에 있는 숫자중 하나를 *로 만들어준다.
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		// 가로 세로 라인 중 가장 *이 많은 라인을 찾아낸다.

		// 가로 라인
		for (int i = 0; i < 5; ++i)
		{
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}

			// 별이 5개 미만이어야 빙고 줄이 아니고 기존에 가장 많은 라인의 별보다 커야 가장 별이 많은 라인이므로
			// 라인을 교체해주고 저장된 별 수를 교체한다.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// 여기는 가로 라인중 가장 별이 많은 라인을 체크하는 곳이다.
				// 가로 라인은 0 ~ 4 로 의미를 부여했다.
				iLine = i;
				iSaveCount = iStarCount;
			}
		}

		// 가로 라인중 가장 별이 많은 라인은 이미 구했다.
		// 이 값과 세로 라인들을 비교하여 별이 가장 많은 라인을 구한다.
		for (int i = 0; i < 5; ++i)
		{
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[j * 5 + i] == INT_MAX)
					++iStarCount;
			}

			// 별이 5개 미만이어야 빙고 줄이 아니고 기존에 가장 많은 라인의 별보다 커야 가장 별이 많은 라인이므로
			// 라인을 교체해주고 저장된 별 수를 교체한다.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// 세로라인은 5 ~ 9 로 의미 부여
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		// 왼쪽 -> 오른쪽 대각선 체크
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		// 오른쪽 -> 왼쪽 대각선 체크
		iStarCount = 0;
		for (int i = 4; i < 20; i += 4)
		{
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}

		// 모든 라인을 조사했으면 iLine에 가능성이 가장 높은 줄 번호가 저장되었다.
		// 그 줄에 있는 *이 아닌 숫자중 하나를 선택하게 한다.

		// 가로줄일 경우
		if (iLine <= LN_H5)
		{
			// 가로줄일 경우 iLine이 0 ~ 4 사이의 값이다.
			for (int i = 0; i < 5; ++i)
			{
				// 현재 줄에서 *이 아닌 숫자를 찾아낸다.
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return  pArray[iLine * 5 + i];
					break;
				}
			}
		}

		else if (iLine <= LN_V5)
		{
			// 세로줄일 경우 iLine이 5 ~ 9 사이의 값이다.
			for (int i = 0; i < 5; ++i)
			{
				// 현재 줄에서 *이 아닌 숫자를 찾아낸다.
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX)
				{
					return pArray[i * 5 + (iLine - 5)];
					break;
				}
			}
		}

		else if (iLine == LN_LT)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
					break;
				}
			}
		}

		else if (iLine == LN_RT)
		{
			for (int i = 4; i < 20; i += 4)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
					break;
				}
			}
		}

		break;
	}

	return -1;
}

int BingoCounting(int* pArray)
{
	int iBingo = 0;

	// 가로줄 체크
	iBingo += BingoCountingH(pArray);
	// 세로줄 체크
	iBingo += BingoCountingV(pArray);
	// 왼쪽 상단 대각선 체크
	iBingo += BingoCountingLTD(pArray);
	// 오른쪽 상단 대각선 체크
	iBingo += BingoCountingRTD(pArray);

	return iBingo;
}

int BingoCountingH(int* pArray)
{
	// 가로 줄 수를 구해준다.
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			// 가로 별 개수를 구해준다.
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}

		// j for 문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇개인지 iStar1 변수에 들어간다.
		// iStar1 값이 5이면 한줄이 모두 * 이라는 의미이므로 빙고 줄 카운트를 추가해준다.
		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}

int BingoCountingV(int* pArray)
{
	// 세로 줄 수를 구해준다.
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		iStar1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			// 가로 별 개수를 구해준다.
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}

		// j for 문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇개인지 iStar1 변수에 들어간다.
		// iStar1 값이 5이면 한줄이 모두 * 이라는 의미이므로 빙고 줄 카운트를 추가해준다.
		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}

int BingoCountingLTD(int* pArray)
{
	// 왼쪽 상단 -> 오른족 하단 대각선 체크
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 25; i += 6)
	{
		if (pArray[i] == INT_MAX)
			++iStar1;
	}

	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}

int BingoCountingRTD(int* pArray)
{
	// 오른쪽 상단 -> 왼쪽 하단 대각선 체크
	int iStar1 = 0, iBingo = 0;

	for (int i = 4; i < 21; i += 4)
	{
		if (pArray[i] == INT_MAX)
			++iStar1;
	}

	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}
