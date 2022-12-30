#include <iostream>

using namespace std;

int main() {
	double A, B;
	cin >> A >> B;

	cout.precision(10); // c++ 소수점 출력 범위 설정 precision(10) = 정수부와 실수부를 합친 범위가 10 이라는 뜻
	cout << A / B;

	return 0;
}

// #include <iostream>

// using namespace std;

// int main() {
// 	double A, B;
// 	cin >> A >> B;

// 	printf("%.9f", A / B);  // %.9f = 소수점 9번째 자리까지 출력하라는 뜻 

// 	return 0;
// }