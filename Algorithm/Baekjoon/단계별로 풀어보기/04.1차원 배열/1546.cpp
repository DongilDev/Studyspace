#include <iostream>

using namespace std;

int main() {
	int n;
	double M = 0, total = 0;
	double score[1001] = {};

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (M < score[i])
			M = score[i];
	}
	
	for (int i = 0; i < n; i++) {
		score[i] = score[i] / M * 100;
		total += score[i];
	}

	cout << total / n;


	return 0;
}