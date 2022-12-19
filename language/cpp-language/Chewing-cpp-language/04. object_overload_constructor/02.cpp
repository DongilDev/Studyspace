#include <iostream>

class Date {
	int year_;
	int month_;  // 1 부터 12 까지.
	int date_;    // 1 부터 31 까지.

public:
	Date() { // 기본 생성자 호출
		year_ = 2022;
		month_ = 11;
		date_ = 26;
	}
	Date(int year, int month, int day) { // 인자 3 개인 생성자 호출
		year_ = year;
		month_ = month;
		date_ = day;
	}
	void AddDay(int inc) {
		date_ += inc;
		if (month_ == 2 && date_ > 28) {
			AddMonth(1);
			date_ -= 28;
			AddDay(0);
		}
		if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11 && date_ > 30) {
			AddMonth(1);
			date_ -= 30;
			AddDay(0);
		}
		if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12 && date_ > 31) {
			AddMonth(1);
			date_ -= 31;
			AddDay(0);
		}
	}
	void AddMonth(int inc) {
		month_ += inc;
		if (month_ > 12) {
			AddYear(1);
			month_ -= 12;
			AddMonth(0);
		}
	}
	void AddYear(int inc) {
		year_ += inc;
	}
	void ShowDate() {
		std::cout << year_ << month_ << date_ << std::endl;
	}
};

int main() {
	int year, month, day;

	std::cout << "year, month, date 값 입력 : " << std::endl;
	std::cin >> year >> month >> day;

	// Date date; 위에 인자 3개를 받는것과 상관없이 기본 생성자 호출
	Date date(year, month, day); // 인자가 3개인 기본 생성자 호출
	date.ShowDate();

	while (1) {
		int input1, input2;
		std::cout << "1. day 추가 \n" << "2. month 추가 \n" << "3. year 추가 \n";
		std::cin >> input1;
		std::cout << "얼마나 추가하시겠습니까? \n";
		std::cin >> input2;

		switch (input1) {
		case 1:
			date.AddDay(input2);
			break;
		case 2:
			date.AddMonth(input2);
			break;
		case 3:
			date.AddYear(input2);
			break;
		}

		date.ShowDate();
	}
	return 0;
}