#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int d[101][10] = { }; 

	for (int i = 1; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				d[i][0] = d[i - 1][j + 1];
			else if (j == 9)
				d[i][9] = d[i - 1][j - 1];
			else
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1])%1000000000;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
		result = (result+d[n][i])%1000000000;
	
	cout << result;


	return 0;
}