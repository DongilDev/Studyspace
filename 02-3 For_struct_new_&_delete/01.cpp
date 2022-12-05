#include <iostream>

using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PointAdder(const Point& p1, const Point& p2) {
	Point* ptr = new Point;
	ptr->xpos = p1.xpos + p2.xpos;
	ptr->ypos = p1.ypos + p2.ypos;

	return *ptr;
}

int main() {
	Point* ptr1 = new Point;
	Point* ptr2 = new Point;

	ptr1->xpos = 10;
	ptr1->ypos = 20;
	ptr2->xpos = 20;
	ptr2->ypos = 40;

	Point &ref = PointAdder(*ptr1, *ptr2);

	cout << ref.xpos << endl << ref.ypos << endl;

	delete ptr1;
	delete ptr2;
	delete &ref;
}