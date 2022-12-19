#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

enum {
	MAP_WIDTH = 20,
	MAP_HEIGHT = 20
};

enum {
	STOP = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
}dir;

int x, y, score, level, speed;
int food_x, food_y;
int tail_x[100], tail_y[100];
int tail_num;
bool gameover;
bool print;

void GameSet() {
	cout << "-------지렁이 게임-------" << endl << endl;
	cout << "Clear 조건: Score 350점 달성" << endl;
	cout << "* 을 5번 먹을때마다 게임 속도가 증가합니다 (Max Lv 7)" << endl << endl;
	gameover = false;
	x = MAP_WIDTH / 2 + 7;
	y = MAP_HEIGHT / 2;
	srand(time(NULL));
	food_x = rand() % MAP_WIDTH;
	food_y = rand() % MAP_HEIGHT;
	level = 1;
	speed = 175;
	
	
	cout << "space bar 를 누르시면 게임이 시작됩니다" << endl;
	while (true) {
		_kbhit();
		int input = _getch();
		if (input == 32)
			break;
	}
}

void Screen() {
	system("cls");

	for (int i = 0; i < MAP_WIDTH; i++) {
		cout << "■";
	}
	cout << endl;

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH*2-3; j++) {
			if (j == 0 || j == MAP_WIDTH * 2 - 4)
				cout << "■";
			if (j == x && i == y)
				cout << "O";
			else if (j == food_x && i == food_y) 
				cout << "*";
			else {
				bool print = true;
				for (int k = 0; k < tail_num; k++) {
					if (tail_y[k] == i && tail_x[k] == j) {
						cout << "o";
						print = false;
					}
				}
				if (print) {
					cout << " ";
				}
			}

		}
		cout << endl;
	}

	for (int i = 0; i < MAP_WIDTH; i++) {
		cout << "■";
	}
	cout << endl << endl;
	cout << "Score: " << score << endl;
	if (level != 7)
		cout << "Level: " << level << endl;
	else if (level == 7)
		cout << "level: MAX SPEED" << endl;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		}
	}
}

void Logic() {
	int prev_tail_x = tail_x[0];
	int prev_tail_y = tail_y[0];
	int prev2_tail_x, prev2_tail_y;
 	tail_x[0] = x;
	tail_y[0] = y;
	for (int i = 1; i < tail_num; i++) {
		prev2_tail_x = tail_x[i];
		prev2_tail_y = tail_y[i];
		tail_x[i] = prev_tail_x;
		tail_y[i] = prev_tail_y;
		prev_tail_x = prev2_tail_x;
		prev_tail_y = prev2_tail_y;
	}
	

	switch (dir) {
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}

	if (x > MAP_WIDTH * 2 - 5 || x < 0 || y > MAP_HEIGHT || y < 0)
		gameover = true;

	for (int i = 0; i < tail_num; i++)
		if (tail_x[i] == x && tail_y[i] == y)
			gameover = true;
	
	if (x == food_x && y == food_y) {
		food_x = rand() % MAP_WIDTH;
		food_y = rand() % MAP_HEIGHT;
		tail_num++;
		score += 10;
		
		if (score % 50 == 0 && score <=300) {
			level++;
			speed -= 25;
		}
	}

	if (score == 350) {
		system("cls");
		for (int i = 0; i < 15; i++) 
			cout << "--------------------------------- CLEAR ---------------------------------" << endl;
		gameover = true;
	}
}

int main() {
	GameSet();

	clock_t start = clock();

	while (!gameover) {
		Screen();
		Input();
		Logic();
		//Sleep(speed);
	}

	clock_t end = clock();

	if(score!=350)
		system("cls");
		cout << "Game over" << endl;
	cout << "Play time: " << (end - start) / CLOCKS_PER_SEC << "초" << endl;

	return 0;
}