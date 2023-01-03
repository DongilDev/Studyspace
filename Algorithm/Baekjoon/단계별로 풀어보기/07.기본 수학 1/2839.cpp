#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	while (N >= 0) {
		if (N % 5 == 0) {
			cout << N / 5 + cnt;
			return 0;
		}
		N -= 3;
		cnt++;
	}

	cout << "-1";

	return 0;
}