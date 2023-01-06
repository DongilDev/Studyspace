#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string arr;
	cin >> arr;
	vector <int> arr2(arr.length());
	
	for (int i = 0; i < arr.length(); i++) {
		arr2[i] = arr[i]-'0';
	}

	sort(arr2.begin(), arr2.end(), greater<int>());

	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i];
	}

	return 0;
}