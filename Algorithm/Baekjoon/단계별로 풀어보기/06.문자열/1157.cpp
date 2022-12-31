#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int arr[26] = {}; // 알파벳 카운트 배열 
	int max = 0;
	int cnt = 0;
	int index;

	for (int i = 0; i < s.length(); i++) { // 알파벳 개수 세기
		int n = s[i];
		if (n < 97)        // 대문자
			arr[n - 65]++;
		else               // 소문자
			arr[n - 97]++;
	}

	for (int i = 0; i < 26; i++) { // 알파벳 개수로 최대빈도 찾기 
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {  // 최대빈도 2개 이상이라면 ? 출력
			cnt++;
			if (cnt >= 2) {
				cout << "?";
				return 0;
			}
		}
	}
	
	cout << (char)(index + 65);


	return 0;
}