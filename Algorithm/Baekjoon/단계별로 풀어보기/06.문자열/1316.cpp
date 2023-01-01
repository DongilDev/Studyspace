#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	int cnt = N;

	while (N--) {
		int key = 0;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] != str[i + 1]) { 
				for (int j = i + 1; j < str.length(); j++) {
					if (str[i] == str[j]) {
						cnt--;
						key = 1;
						break;
					}
				}
			}
			if (key == 1)
				break;
		}
	}
	cout << cnt;

	return 0;
}