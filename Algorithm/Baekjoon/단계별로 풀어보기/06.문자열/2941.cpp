#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;
	
	int cnt = 0;
	int i = 0;
	while (i < input.length()) {
		switch (input[i]) {
		case 'd':
			if (input[i + 1] == 'z' && input[i + 2] == '=') {
				cnt++;
				i += 3;
				break;
			}
		case 'c':
			if (input[i + 1] == '-') {
				cnt++;
				i += 2;
				break;
			}
		case 's':
		case 'z':
			if (input[i + 1] == '=') {
				cnt++;
				i += 2;
				break;
			}
			else {
				cnt++;
				i++;
				break;
			}
		case 'n':
		case 'l':
			if (input[i + 1] == 'j') {
				cnt++;
				i += 2;
				break;
			}
		default:
			cnt++;
			i++;
			break;
		}
	}

	cout << cnt;

	return 0;
}
