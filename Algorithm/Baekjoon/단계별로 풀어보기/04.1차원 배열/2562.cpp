	#include <iostream>

	using namespace std;

	int main() {
		int arr[9], max = 0, index;

		for (int i = 0; i < 9; i++) {
			cin >> arr[i];
			if (max < arr[i]) {
				max = arr[i];
				index = i;
			}
		}
		
		cout << max << endl;
		cout << index + 1;

		return 0;
	}