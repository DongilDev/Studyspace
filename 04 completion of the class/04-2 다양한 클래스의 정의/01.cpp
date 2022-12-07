#include <iostream>

using namespace std;

class Point {
	int xpos, ypos;
	
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
	Point center;
	int radi;

public:
	void Init(int x, int y, int radius) {
		center.Init(x, y);
		radi = radius;
	}
	void ShowCircleInfo() const {
		cout << "radius : " << radi << endl;
		center.ShowPointInfo();
	}
};

class Ring {
	Circle InnerCircle;
	Circle OutterCircle;

public:
	void Init(int x1, int y1, int radius1, int x2, int y2, int radius2) {
		InnerCircle.Init(x1, y1, radius1);
		OutterCircle.Init(x2, y2, radius2);
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info" << endl;
		InnerCircle.ShowCircleInfo();

		cout << "Outter Circle Info" << endl;
		OutterCircle.ShowCircleInfo();
	}
};

int main() {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}