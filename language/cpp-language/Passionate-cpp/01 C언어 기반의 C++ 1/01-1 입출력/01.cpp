#include <iostream>

int main() {
	int input, num = 0;

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << "번째 정수 : ";
		std::cin >> input;
		std::cout << input << std::endl;
		num += input;
	}

	std::cout << "합계: " << num << std::endl;
	return 0;
}