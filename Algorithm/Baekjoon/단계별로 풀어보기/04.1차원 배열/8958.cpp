#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		char str[80] = {};
		int cnt = 0;
		int score = 0;
		cin >> str;
		for (int i = 0; i < 80; i++) {
			if (str[i] == 'O') {
				cnt++;
				score += cnt;
			}
			else
				cnt = 0;
		}
		cout << score << endl;
	}

	return 0;
}