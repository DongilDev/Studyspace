#include <iostream>

using namespace std;

int check(int n) {
	if (n < 100)
		return 1;

	int a, b, c;

	a = n / 100;
	n %= 100;
	b = n / 10;
	n %= 10;
	c = n % 10;

	if ((a - b) == (b - c))
		return 1;
	
	return 0;
}

int main(){
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += check(i);
	}

	cout << sum;

	return 0;
}

// #include <stdio.h>
// int main() {
// 	int N, cnt = 99;
// 	scanf("%d", &N);
// 	if (N < 100) printf("%d", N);
// 	else {
// 		for (int i = 100; i < N + 1; i++) {
// 			if (i / 100 - i % 100 / 10 == i % 100 / 10 - i % 10) cnt++;
// 		}
// 		printf("%d", cnt);
// 	}
// 	return 0;
// }