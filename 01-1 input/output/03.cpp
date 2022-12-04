#include <iostream>

int main() {
	int num;
	
	std::cout << "숫자 입력: ";
	std::cin >> num;

	std::cout << "입력하신 숫자로 구구단을 출력하겠습니다." << std::endl;

	for (int i = 1; i < 10; i++) {
		std::cout << num << " * " << i << " = " << num * i << std::endl;
	}

	return 0;
	//1
}