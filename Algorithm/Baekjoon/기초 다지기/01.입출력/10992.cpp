#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i == n-1) {  // 마지막 줄 별 
			for (int j = 0; j < 2 * n - 1; j++)
				cout << "*";
		}
		else {
			for (int j = i; j < n-1; j++)
				cout << " ";
			cout << "*";
			if (i != 0) {  // 첫 번째 줄은 건너 뛰게됨 즉 바로 위에 줄인 '공백-별' 까지만 시행
				for (int j = 0; j < i * 2 - 1; j++) // 두 번째 줄부터는 '공백-줄-공백-줄' 시행
					cout << " "; 
				cout << "*";
			}
		}
		cout << endl;
	}
	return 0;
}