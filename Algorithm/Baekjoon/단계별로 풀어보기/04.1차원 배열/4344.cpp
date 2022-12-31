#include <iostream>

using namespace std;

int main() {
	int C;
	cin >> C;

	while (C--) {
		double N;
		cin >> N;
		double score[1000];
		double aver = 0;
		double cnt = 0;
		double total;

		for (int i = 0; i < N; i++) {
			cin >> score[i];
			aver += score[i];
		}
		aver /= N; 
		for (int i = 0; i < N; i++) {
			if (score[i] > aver) {
				cnt++;
			}
		}
		total = cnt / N * 100;

		cout << fixed;
		cout.precision(3);
		cout << total << "%" << endl;
	}

	return 0;
}