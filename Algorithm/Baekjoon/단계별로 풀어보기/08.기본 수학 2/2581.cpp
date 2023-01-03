#include <iostream>

using namespace std;

int main() {
	int M, N; // M<=N
	cin >> M >> N;
	
	int min = 10000, sum = 0;
	int cnt = 0;
	int cnt2 = 0;
	for (int i = M; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			sum += i;
			cnt2++;
			if (min > i)
				min = i;
		}
		cnt = 0;
	}

	if (cnt2 == 0) {
		cout << "-1";
		return 0;
	}

	cout << sum << endl;
	cout << min;

	return 0;
}