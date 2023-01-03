#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[1000];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int temp = 0;
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}