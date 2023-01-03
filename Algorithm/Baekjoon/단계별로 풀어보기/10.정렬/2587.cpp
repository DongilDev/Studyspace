#include <iostream>

using namespace std;

int main() {
	int arr[5] = {};
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum /= 5;
	cout << sum << endl;

	int temp;
	for (int i = 4; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	cout << arr[2] << endl;

	return 0;
}