#include "render.h"
#include "flag.h"
#include "macros.h"

extern UNDO Undo[UNDO_MAX];

int stageX;
int stageY;

char map[SIZE_MAP_Y][SIZE_MAP_X];

extern int playerX;
extern int playerY;
extern int stage;
extern int playerMoveCount;
extern int playerPushCount;
extern int stageClear[STAGE_MAX];
extern int pushCount[STAGE_MAX];
extern int moveCount[STAGE_MAX];
extern int undoCount;
extern int gameState;
extern int exitFlag;
extern char* stageClear1;
extern char* stageClear2;

void MapInit()
{
	for (int y = 0; y < SIZE_MAP_Y; ++y)
	{
		for (int x = 0; x < SIZE_MAP_X; ++x)
		{
			map[y][x] = '0';
		}
	}
}

void SetStartStageCoordinate(const char* pnt)
{
	int maxX = 0;
	int x = 0, y = 0;
	char data;

	while (true)
	{
		data = *(pnt++);

		if (data == 0) // 스테이지 데이터의 끝을 체크
			break; 
		
		if (data == 'n') // 줄바꿈 처리
		{
			if (x > maxX)
				maxX = x;

			x = 0; // 줄바꿈
			++y;
			continue;
		}

		++x;
	}

	stageX = (SIZE_MAP_X - maxX + 1) / 2;
	stageY = (SIZE_MAP_Y - y + 5) / 2;
}

void StageToMap(const char* pnt)
{
	int x = stageX;
	int y = stageY;
	char data;

	while (true)
	{
		data = *(pnt++);

		if (data == 0)
			break;

		if (data == 'n')
		{
			x = stageX;
			++y;
			continue;
		}

		map[y][x] = data;
		++x;
	}
}

// 커서 이동 
void gotoxy(int x, int y)
{
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

// 콘솔 색깔 지정
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void MainDraw()
{
	gotoxy(0, 4);
	SetColor(YELLOW); 
	printf("         dMMMMb   dMP dMP   dMMMb    dMP dMP          dMMMMb   dMP dMP   dMMMb    dMP dMP\n");
	printf("        dMP dMP  dMP dMP  dMP       dMP dMP          dMP dMP  dMP dMP  dMP       dMP dMP\n");
	printf("       dMMMMP   dMP dMP    VMMMb   dMMMMMP          dMMMMP   dMP dMP    VMMMb   dMMMMMP\n");
	printf("      dMP      dMP aMP      dMP   dMP dMP          dMP      dMP aMP      dMP   dMP dMP\n");
	printf("     dMP       VMMMP     VMMMP   dMP dMP          dMP       VMMMP     VMMMP   dMP dMP\n");

	int x = 42, y = 16;
	SetColor(DARK_YELLOW);
	gotoxy(x - 2, y);
	printf("> 게임 시작");

	gotoxy(x, y + 2);
	printf("게임 초기화");

	gotoxy(x, y + 4);
	printf("게임 방법");

	gotoxy(x, y + 6);
	printf("게임 종료");

	while (true)
	{
		int n = KeyControl();

		switch (n)
		{
		case KEY_UP:
			if (y > 16)
			{
				gotoxy(x - 2, y);
				printf(" ");

				y -= 2;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;

		case KEY_DOWN:
			if (y < 22)
			{
				gotoxy(x - 2, y);
				printf(" ");

				y += 2;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;

		case KEY_SUBMIT:
			if (y == 16)
				gameState = 1;
			else if (y == 18)
				gameState = 2;
			else if (y == 20)
				gameState = 3;
			else if (y == 22)
				gameState = 4;
			return;
		}
	}
}

void InfoDraw()
{
	system("cls");
	GameHelpDraw();

}

void MapDraw(int x, int y)
{
	char data = map[y][x];
	gotoxy(x * 2, y);

	switch (data)
	{
	case '0': // 빈 공간	
		SetColor(BLACK);
		printf("  ");
		break;
	case '1': // 벽
		SetColor(RED);
		printf("▩");
		break;
	case '2': // 움직일 박스
		SetColor(YELLOW);
		printf("★");
		break;
	case '3': // 목적지
		SetColor(DARK_GRAY);
		printf("♀");
		break;
	case '4': // 완성된 목적지
		SetColor(YELLOW);
		printf("♀");
		break;
	}
}

void GameDraw()
{
	for (int y = 0; y < SIZE_MAP_Y; ++y)
	{
		for (int x = 0; x < SIZE_MAP_X; ++x)
		{
			MapDraw(x,y);
		}
	}
}

void PlayerDraw()
{
	gotoxy(playerX * 2, playerY);
	SetColor(GREEN);
	printf("●");
}

void TitleDraw()
{
	int x = SIZE_MAP_X -10;
	int y = 3;
	
	SetColor(YELLOW);
	gotoxy(x + 2, y);
	printf("P U S H  P U S H");
}

void StageDraw()
{
	int x = SIZE_MAP_X - 12;
	int y = 5;

	SetColor(SKY_BLUE);
	gotoxy(x, y);
	printf("Stage : %d", stage + 1);
	SetColor(RED);
	printf("/%d", 67);
}

void PlayerMoveCountDraw()
{
	int x = SIZE_MAP_X;
	int y = 5;

	SetColor(VIOLET);
	gotoxy(x + 4, y);
	printf("Move : %d", playerMoveCount);

	if (stageClear[stage] != 0)
	{
		SetColor(RED);
		printf("/%d", moveCount[stage]);
	}
}

void PlayerPushCountDraw()
{
	int x = SIZE_MAP_X;
	int y = 6;

	SetColor(VIOLET);
	gotoxy(x + 4, y);
	printf("Push : %d", playerPushCount);

	if (stageClear[stage] != 0)
	{
		SetColor(RED);
		printf("/%d", pushCount[stage]);	
	}
}

void GameHelpDraw()
{
	system("cls");
	int x = 35;
	int y = 5;

	gotoxy(x-2, 24);
	printf("press space key to main screen");

	SetColor(DARK_GREEN);
	gotoxy(x + 2, y++); printf("[ Backspace ] : 뒤로가기\n");
	gotoxy(x + 2, y++); printf("[ R ] : 다시하기 \n");
	gotoxy(x + 2, y++); printf("[ Esc ] : 나가기 \n");
	SetColor(BLUE);
	++y;
	gotoxy(x + 2, y++); printf("[ H ] : 리플레이\n");
	SetColor(GRAY);
	
	y += 2;
	
	gotoxy(x + 2, y++); printf("       UP");
	gotoxy(x + 2, y++); printf("       ↑");
	gotoxy(x + 2, y++); printf("LEFT ←   → RIGHT");
	gotoxy(x + 2, y++); printf("       ↓");
	gotoxy(x + 2, y++); printf("      DOWN");

	y += 2;

	SetColor(SKY_BLUE);
	gotoxy(x + 2, y++); printf("[ PAGE_UP ]   : 다음 스테이지");
	gotoxy(x + 2, y++); printf("[ PAGE_DOWN ] : 이전 스테이지");


	while (1)
	{
		if (KeyControl() == KEY_SUBMIT)
			break;
	}
}

void UndoDraw()
{
	int x = SIZE_MAP_X - 12;
	int y = 6;
	SetColor(BLUE);
	gotoxy(x , y);
	printf("Undo  : %d", undoCount);
	
}

void GameStateDraw()
{
	TitleDraw();
	StageDraw();
	PlayerMoveCountDraw();
	PlayerPushCountDraw();
	UndoDraw();
	// GanmeHelpDraw();
}

void GameUndo()
{
	--undoCount;

	for (int y = 0; y < SIZE_MAP_Y; ++y)
	{
		for (int x = 0; x < SIZE_MAP_X; ++x)
		{
			map[y][x] = Undo[undoCount].map[y][x];
			MapDraw(x, y);
		}
	}

	TitleDraw();
	StageDraw();
	UndoDraw();

	playerX = Undo[undoCount].playerX;
	playerY = Undo[undoCount].playerY;

	PlayerDraw();

	playerMoveCount = Undo[undoCount].playerMoveCount;

	PlayerMoveCountDraw();

	playerPushCount = Undo[undoCount].playerPushCount;

	PlayerPushCountDraw();
}

void StageClear()
{
	SetColor(GREEN);
	gotoxy(64, 10);
	printf("%s", stageClear1);
	gotoxy(60, 12);
	printf("%s", stageClear2);
	
	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			break;
	}
}

void GameOver()
{
	SetColor(WHITE);
	system("cls");
	gotoxy(0, 0);
}
