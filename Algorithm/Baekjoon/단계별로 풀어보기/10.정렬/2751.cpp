#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000000] = {};

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+N); // 시간복잡도 O(nlogn) quick sort 알고리즘을 바탕으로 만들어짐. 

	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";
	

	return 0;
}