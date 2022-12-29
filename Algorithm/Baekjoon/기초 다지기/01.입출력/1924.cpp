#include <iostream>

using namespace std;

int main() {
	char day[7][4] = {
		"SUN",
		"MON",
		"TUE",
		"WED",
		"THU",
		"FRI",
		"SAT"
	};

	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int x, y, key = 0;
	cin >> x >> y;

	for (int i = 0; i < x - 1; i++) { // x 에 -1 을 하는 이유는 y 를 입력 받았기 때문.
		y += month[i];
	}

	key = y % 7;
	cout << day[key];

	return 0;
}