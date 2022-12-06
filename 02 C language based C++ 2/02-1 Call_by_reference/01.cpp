#include <iostream>

using namespace std;

void Increase(int& num) {
	num++;
}

void  ChangeSign(int& num) {
	num *= -1;
}

int main() {
	int num = 10;

	cout << num << endl;
	Increase(num);
	cout << num << endl;
	ChangeSign(num);
	cout << num << endl;
    
    return 0;
}
