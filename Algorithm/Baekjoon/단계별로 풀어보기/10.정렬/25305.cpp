#include <iostream>

using namespace std;

int main() {
	int N, k;
	cin >> N >> k;

	int arr[1000] = {};

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int temp;
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << arr[N - k];

	return 0;
}