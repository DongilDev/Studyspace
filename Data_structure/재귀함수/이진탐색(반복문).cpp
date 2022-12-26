#include <iostream>

using namespace std;

int BSearch(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == ar[mid])
			return mid;
		else {
			if (target < ar[mid])
				last = mid - 1;  // -1 혹은 +1 을 추가하지 않으면 first <= mid <= last 가
			else                 // 항상 성립이 되어, 탐색 대상이 존재하지 않는 경우 
				first = mid + 1; // first 아 last 의 역전 형상이 발생하지 않는다
		}
	}
	return -1; // 찾지 못했을 때 반환 값 -1 
}

int main() {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = i;
	}

	cout << "찾고자 하는 숫자가 존재하는 인덱스 값: "
		<< BSearch(arr, 100, 75) << endl;
}
