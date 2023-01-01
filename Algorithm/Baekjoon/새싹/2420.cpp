#include <iostream>

using namespace std;

int main()
{
	long long N, M, sum;
	cin >> N >> M;
	sum = N - M;
	if (sum < 0)
		sum *= -1;
	cout << sum << endl;
}