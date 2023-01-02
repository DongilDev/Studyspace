#include <iostream>

using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	int day = 0;

	if ((V - B) % (A - B) == 0)
		day += (V - B) / (A - B);
	else
		day += (V - B) / (A - B) + 1;

	cout << day;

	return 0;
}