#include <iostream>

using namespace std;

int main() {
	int arr[100][100] = {};
	int n;
	cin >> n;

	int cnt = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;

		for (int i=y; i < y + 10; i++) {
			for (int j=x; j < x + 10; j++) {
					if (!arr[i][j]) {
					arr[i][j] = 1;
					cnt++;
				}
			}
		}
	}	
	
	cout << cnt;

	return 0;
}