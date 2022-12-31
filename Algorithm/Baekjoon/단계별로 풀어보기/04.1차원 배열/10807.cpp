	#include <iostream>

	using namespace std;

	int main() {
		int n, search;
		int cnt = 0;
		int arr[101];
		cin >> n;
	
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cin >> search;

		for (int i = 0; i < n; i++) {
			if (arr[i] == search)
				cnt++;
		}

		cout << cnt;

		return 0;
	}