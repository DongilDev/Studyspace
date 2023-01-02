#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	int H, W, N;

	while (T--) {
		cin >> H >> W >> N;

		int floor = N % H;
		int number = N / H + 1;

		if (N % H == 0) {
			floor = H;
			number = N / H;
		}

		cout << floor * 100 + number << endl;

	}

	return 0;
}