	#include <iostream>

	using namespace std;

	int main() {
		int n;
		cin >> n;

		int temp1 = n;
		int temp2 = -1;
		int cnt = 0;


		while (n != temp2) {
			temp2 = temp1 / 10 + temp1 % 10;
			temp2 = (temp1 % 10) * 10 + temp2 % 10;
			temp1 = temp2;

			cnt++;
		}

		cout << cnt;

		return 0;
	}