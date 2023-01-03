#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	int arr[15][15] = {};

	for (int i = 1; i < 15; i++) {
		arr[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	
	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}

	return 0;
}