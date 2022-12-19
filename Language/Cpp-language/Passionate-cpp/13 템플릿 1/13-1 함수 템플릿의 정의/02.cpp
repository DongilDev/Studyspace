#include <iostream>
#include <cstring>

using namespace std;

template <class T>
T SumArray(T arr[], int len) {
	T sum = (T)0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main() {
	int arr1[] = { 1,2,3,4,5 };
	double arr2[] = { 1.1,2.2,3.3,4.4,5.5 };

	cout << SumArray(arr1, sizeof(arr1)/sizeof(int)) << endl;
	cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << endl;
}