#include <iostream>

using namespace std;

int Factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main() {
	cout << "1! = " << Factorial(1) << endl;
	cout << "2! = " << Factorial(2) << endl;
	cout << "3! = " << Factorial(3) << endl;
	cout << "4! = " << Factorial(4) << endl;
	cout << "5! = " << Factorial(5) << endl;
	cout << "6! = " << Factorial(6) << endl;
	cout << "10! = " << Factorial(10) << endl;

	return 0;
}