#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char arr1[20] = "Hello";
	char arr2[20] = "Wrold";

	cout << arr1 << endl;
	cout << arr2 << endl;

	cout << strlen(arr1) << endl; // 문자열의 길이 계산
	cout << strlen(arr2) << endl; // 문자열의 길이 계산

	cout << strcat(arr1, arr2) << endl; // 믄지열의 뒤에 덧붙이기

	cout << strcmp(arr1, arr2) << endl; // 문자열 비교 (같으면 0 틀리면 -1 반환)

	cout << strcpy(arr1, arr2) << endl; // 문자열 복사 

	cout << strcmp(arr1, arr2) << endl; // 문자열 비교 
	
	cout << arr1 << endl << arr2;
	
	return 0;
}