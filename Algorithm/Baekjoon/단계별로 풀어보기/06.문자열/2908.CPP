#include <iostream>
#include <string>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	for (int i = 0; i < A.length() / 2; i++) {
		int temp = A[A.length() - i - 1];
		A[A.length() - i - 1] = A[i];
		A[i] = temp;
	}

	for (int i = 0; i < B.length() / 2; i++) {
		int temp = B[B.length() - i - 1];
		B[B.length() - i - 1] = B[i];
		B[i] = temp;
	}

	if (A > B)
		cout << A;
	else
		cout << B;

	return 0;
}
