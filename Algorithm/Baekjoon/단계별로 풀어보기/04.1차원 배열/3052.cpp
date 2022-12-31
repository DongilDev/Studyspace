	#include <iostream>

	using namespace std;

	int main() {
		int arr[42] = {  };
		int n;

		for (int i = 0; i < 10; i++) {
			cin >> n;
			arr[n % 42] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < 42; i++)
			cnt += arr[i];

		cout << cnt;

		return 0;
	}