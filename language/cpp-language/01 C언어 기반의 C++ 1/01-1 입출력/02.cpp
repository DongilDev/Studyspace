#include <iostream>

int main() {
	char name[100], number[100];

	std::cout << "이름: ";
	std::cin >> name;
	std::cout << "전화번호: ";
	std::cin >> number;
	
	std::cout << "당신의 이름: " << name << std::endl;
	std::cout << "당신의 전화번호: " << number << std::endl;

	return 0;
}