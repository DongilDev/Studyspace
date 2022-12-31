#include <iostream>

using namespace std;

int d(int n) {
	int temp = n;

	while (n != 0) {
		temp = temp + (n % 10);
		n /= 10;
	}

	return temp;
}

int main() {
	bool check[10001] = {};
	
	for (int i = 1; i < 10001; i++) {
		int n = d(i);
		if (n < 10001)
			check[n] = true;
	}

	for (int i = 1; i < 10001; i++)
		if (!check[i])
			cout << i << endl;

	return 0;
}