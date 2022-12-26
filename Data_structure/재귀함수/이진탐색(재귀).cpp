#include <iostream>

using namespace std;

int BSearchRecur(int arr[], int first, int last, int target) {
	int mid;
	if (first > last)
		return -1;
	mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return BSearchRecur(arr, first, mid - 1, target);
	else
		return BSearchRecur(arr, mid + 1, last, target);
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		cout << "탐색 실패" << endl;
	else
		cout << "타겟 저장 인덱스: " << idx << endl;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		cout << "탐색 실패" << endl;
	else
		cout << "타겟 저장 인덱스: " << idx << endl;
}