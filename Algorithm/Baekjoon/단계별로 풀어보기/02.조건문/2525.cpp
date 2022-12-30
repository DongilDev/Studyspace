	#include <iostream>

	using namespace std;

	int main() {
		int A, B;
		cin >> A >> B;
	
		int C;
		cin >> C;

		int cnt = 0;
		while (C >= 60) {
			C -= 60;
			cnt++;
		}

		if (cnt <= 0) {
			if (B + C < 60)
				B += C;
			else {
				B = B + C - 60;
				A++;
				if (A > 23)
					A = 0;
			}
		}
			
		else {
			while (cnt > 0) {
				A++;
				if (A > 23)
					A = 0;
				cnt--;
			}
			if (B + C < 60)
				B += C;
			else {
				B = B + C - 60;
				A++;
				if (A > 23)
					A = 0;
			}
		}

		cout << A << " " << B;

		return 0;
	}

//위에가 직접 푼 코드

//아래가 간결한 다른 정답 코드

//     #include <iostream>

// int main()
// {
//     int hour, minute, elapsedTime;

//     std::cin >> hour >> minute;
//     std::cin >> elapsedTime;

//     hour = (hour + (minute + elapsedTime) / 60) % 24;
//     minute = (minute + elapsedTime) % 60;

//     std::cout << hour << " " << minute << std::endl;

//     return 0;
// }