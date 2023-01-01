#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 32) {
			if (i!=0 && i != s.length()-1)
				cnt++;
		}
	}

	if (cnt == 0 && s.length() == 1 && s[0]==32)
		cout << cnt;
	else
		cout << cnt + 1;

	return 0;
}
