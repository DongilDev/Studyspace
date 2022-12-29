#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		for (int j = 0; j < 2 * (n - i - 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n - 1; j++) {
			cout << "*";
		}
		for (int j = 0; j < 2 * (i + 1); j++) {
			cout << " ";
		}
		for (int j = i; j < n - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}


// #include <stdio.h>
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 1; i < 2 * n; i++) {
//         for (int j = 1; j <= (i > n ? 2 * n - i : i); j++) printf("*");
//         for (int j = 1; j <= (i > n ? i - n : n - i) * 2; j++) printf(" ");
//         for (int j = 1; j <= (i > n ? 2 * n - i : i); j++) printf("*");
//         printf("\n");
//     }
// }