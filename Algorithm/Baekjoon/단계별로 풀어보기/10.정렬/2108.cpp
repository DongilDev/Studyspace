#include <iostream>
#include <algorithm>
#include <cmath> // round 반올림 함수를 사용하기 위한 라이브러리

using namespace std;
int arr[500001]; // (중앙값과 범위값 찾을 용도)
int number[8001];  // (최빈값 찾을 용도)

int main(void) {
	int N;
	cin >> N;
	double sum = 0; // 산술 값 찾을 용도
	int temp, max = 0; 
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; 
		sum += arr[i];
		temp = (arr[i] <= 0) ? abs(arr[i]) : arr[i] + 4000;
		number[temp]++; // -4000 ~ 4000 의 각 수가 몇개인지 저장
		if (number[temp] > max)
			max = number[temp];
	}

	sort(arr, arr+N); // 정렬

	double sansool = round(sum / N); 
	if (sansool == -0) // 0 0 -1 을 입력 받았을 때 -0.333 에서 반올림으로 -0 으로 출력되는걸 방지
		sansool = 0;
	
	int key = 0;
	bool isSecond = false;
	for (int i = -4000; i < 4001; i++)
	{
		temp = i <= 0 ? abs(i) : i + 4000;
		if (number[temp] == max)
		{
			key = i;
			if (isSecond)
				break;
			isSecond = true;
		}
	}

	cout << sansool << endl; // 1. 산술 값
	cout << arr[N / 2] << endl; // 2. 중앙 값
	cout << key << endl; // 3. 최빈 값 중 두 번째로 작은 수
	cout << arr[N-1] - arr[0]; // 4. 범위 

	return 0;
}