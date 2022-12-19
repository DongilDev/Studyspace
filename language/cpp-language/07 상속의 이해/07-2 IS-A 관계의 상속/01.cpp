#include <iostream>

using namespace std;

class Rectangle {
	int width; // 가로
	int height; // 세로
public:
	Rectangle(int _width, int _height) : width(_width), height(_height) {}
	
	void ShowAreaInfo() {
		cout << "면적: " << width * height << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int side) : Rectangle(side, side), length(side) {}
};

int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}