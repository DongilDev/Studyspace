#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	int r;
	string s;
	while (T--) {
		cin >> r >> s;
		
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < r; j++) {
				cout << s[i];
			}
		}
	
		cout << endl;
	}

	return 0;
}