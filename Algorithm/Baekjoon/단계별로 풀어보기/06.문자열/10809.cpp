#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	char s[101];
	cin >> s;
	
	int key = 0;
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < strlen(s); j++) {
			if (str[i] == s[j]) {
				cout << j << " ";
				key = 0;
				break;
			}
			else
				key = 1;
		}
		if (key == 1)
			cout << "-1 ";
	}

	return 0;
}

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
// 	string input;
// 	string s = "abcdefghijklmnopqrstuvwxyz";
// 	cin >> input;
// 	for (int i = 0; i < s.length(); i++)
// 		cout << (int)input.find(s[i]) << " ";

// 	return 0;
// }