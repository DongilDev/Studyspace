#include <iostream>

using namespace std;
int arr[300000] = {};

int main() {
	for (int i = 2; i <= 300000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= 300000; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i * 2; j <= 300000; j += i) {
			arr[j] = 0;
		}
	}

	while (true) {
		int n;
		cin >> n;
		int cnt = 0;

		if (n == 0)
			break;
		
		for (int i = n+1; i <= 2 * n; i++)
			if (arr[i] != 0)
				cnt++;
		cout << cnt << endl;
	}
	
	return 0;
}