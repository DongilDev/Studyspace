#include <iostream>

using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y) {
		xpos += x;
		ypos += y;
	} // 점의 좌표이동
	void AddPoint(const Point& pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
	} // 점의 좌표증가
	void ShowPosition() {
		cout << xpos << ", " << ypos << endl;
	} // 현재 x,y 좌표정보 출력
};

int main() {
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();

	return 0;
}