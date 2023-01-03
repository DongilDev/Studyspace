#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int arr[100] = {};
	int cnt = N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			cnt--;
			continue;
		}
		if (arr[i] == 2)
			continue;

		for (int j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				cnt--;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}