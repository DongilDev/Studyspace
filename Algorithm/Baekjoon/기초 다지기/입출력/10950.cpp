#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	int A, B;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << endl;
	}

	return 0;
}