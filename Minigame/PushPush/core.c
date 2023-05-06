#include "core.h"
#include "flag.h"
#include "value.h"
#include "player.h"
#include "render.h"
#include "file.h"

extern int playerX;
extern int playerY;
extern int stageX;
extern int stageY;

void StageInit()
{
	StageClearFileLoad();

	// 맵 초기화
	MapInit();

	const char* pnt = stageTable[stage];

	// 콘솔 타이틀 
	SetConsoleTitle(L"PushPush"); 

	// stagTable 을 통해서 플레이어의 x, y 좌표 얻는다.
	PlayerSetPosition(pnt);

	// 앞의 네자리는 플레이어 좌표이므로 넘긴다. (바로 위에 PlayerSetPosition 함수를 통해 사용했다.)
	pnt += 4; 

	// stageTable 을 통해서 맵을 그릴 시작 좌표를 구한다.
	SetStartStageCoordinate(pnt);

	// PlayerSetPosition 에서 구한 플레이어 좌표에 SetStartStageCoordinate 을 사용하여 구한 시작 좌표를 더한다.
	playerX += stageX;
	playerY += stageY;

	// 게임의 화면과 map 2차원 배열을 1:1 로 매칭 시킨다.
	StageToMap(pnt);

	// map 2차원 배열을 통해서 맵을 화면에 그린다.
	GameDraw();

	// 플레이어 정보를 화면에 그린다.
	PlayerDraw();

	stageClearFlag = 0;
	playerMoveCount = 0;
	playerPushCount = 0;
	undoCount = 0;
}

void HideCursor()
{
	// 커서 관리 (숨기기)
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO cursorInfo;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorInfo.bVisible = 0; // 숨기는지
	cursorInfo.dwSize = 1;   // 크기 설정
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}
