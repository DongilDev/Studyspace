	#include <iostream>

	using namespace std;

	int main() {
		int totalmoney, n;
		cin >> totalmoney >> n;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;

			cnt += a * b;
		}

		if (totalmoney == cnt)
			cout << "Yes";
		else
			cout << "No";
	
		return 0;
	}