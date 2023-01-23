#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	int  iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iBingo = 0;

	
	while (true)
	{
		system("cls");
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
					cout << int(iNumber[i * 5 + j]) << "\t";
			}

			cout << endl;
		}

		cout << "Bingo Line : " << iBingo << endl;

		// 줄수가 5 이상일 경우 게임을 종료한다.
		if (iBingo >= 5)
			break;

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput > 25)
			continue;
		
		// 중복입력을 체크하기 위한 변수이다.
		// 기본적으로 중복되었다라고 하기위해 true 로 잡아주었다.
		bool bAcc = true;

		// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지를 찾아낸다.
		for (int i = 0; i < 25; ++i)
		{
			// 같은 숫자가 있을 경우
			if (iInput == iNumber[i])
			{
				// 숫자를 찾았을 경우 중복된 숫자가 아니므로 bAcc 변수를 false 로 만들어준다.
				bAcc = false;

				// 숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
				iNumber[i] = INT_MAX;

				break;
			}
		}

		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 바꾸지 못했으므로 
		// 다시 입력받게 continue 해준다.
		if (bAcc)
			continue;

		// 빙고 줄 수를 체크하는것은 매번 숫자를 입력할때마다 처음부터 새로 카운트를  할 것이다.
		// 그러므로 iBingo 변수를 0으로 매번 초기화하고 새롭게 줄 수를 구해주도록 한다.
		iBingo = 0;

		// 가로, 세로 줄 수를 구해준다.
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				// 가로 별 개수를 구해준다.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;

				// 세로 별 개수를 구해준다.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
			}

			// j for 문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇개인지 iStar1 변수에 들어간다.
			// iStar1 값이 5이면 한줄이 모두 * 이라는 의미이므로 빙고 줄 카운트를 추가해준다.
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;
		}

		// 왼쪽 상단 -> 오른쪽 하단 대각선 체크
		iStar1 = 0; 
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}

		if (iStar1 == 5)
			++iBingo;

		iStar1 = 0;
		// 오른쪽 상단 -> 왼쪽 하단 대각선 체크
		for (int i = 4; i < 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}

		if (iStar1 == 5)
			++iBingo;
	}
	return 0;
}