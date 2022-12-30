#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	int d[11];
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		for (int j = 4; j <= n; j++) {
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
		}
		cout << d[n] << endl;
	}

	return 0;
}