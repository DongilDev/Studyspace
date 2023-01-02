#include <iostream>
#include <string>

using namespace std;

int main()
{
	string n1, n2, str_sum; // 수가 크기 때문에, 문자열로 입력받음
	cin >> n1 >> n2;

	int up = 0;  // 올림수
	int len1 = n1.size();  
	int len2 = n2.size();

	while (len1 > 0 || len2 > 0)
	{
		int nn1 = 0;  // 첫번째 수의 자릿수 중 하나(일의 자리부터 시작)
		if (len1 > 0)
		{
			nn1 = n1[--len1] - '0';  // 문자 0 을 빼주면 함수를 쓰지 않고도 문자를 숫자로 바꾸기 가능
		}

		int nn2 = 0;
		if (len2 > 0)
		{
			nn2 = n2[--len2] - '0';
		}

		int temp = nn1 + nn2 + up;

		up = temp / 10; // 올림수 변경
		temp %= 10;
		char c = temp + '0';  // 문자로 변환

		str_sum += c;
	}	
	if (up > 0) // 올림수가 마지막까지 남아있다면
	{
		str_sum += up + '0';
	}
	for (int i = str_sum.length() - 1; i >= 0; i--)  // 출력
	{
		cout << str_sum[i];
	}

	return 0;
}