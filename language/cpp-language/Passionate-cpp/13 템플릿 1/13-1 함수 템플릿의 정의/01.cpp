#include <iostream>
#include <cstring>

using namespace std;

class Point {
	int xpos, ypos;
public:
	Point(int x = 0, int y=0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <class T>
void SwapData(T& ref1, T&ref2) {
	T temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main() {
	Point point1(1, 2);
	Point point2(3, 4);

	point1.ShowPosition();
	point2.ShowPosition();
	
	SwapData(point1, point2);

	point1.ShowPosition();
	point2.ShowPosition();
}