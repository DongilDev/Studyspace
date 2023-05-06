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

	// �� �ʱ�ȭ
	MapInit();

	const char* pnt = stageTable[stage];

	// �ܼ� Ÿ��Ʋ 
	SetConsoleTitle(L"PushPush"); 

	// stagTable �� ���ؼ� �÷��̾��� x, y ��ǥ ��´�.
	PlayerSetPosition(pnt);

	// ���� ���ڸ��� �÷��̾� ��ǥ�̹Ƿ� �ѱ��. (�ٷ� ���� PlayerSetPosition �Լ��� ���� ����ߴ�.)
	pnt += 4; 

	// stageTable �� ���ؼ� ���� �׸� ���� ��ǥ�� ���Ѵ�.
	SetStartStageCoordinate(pnt);

	// PlayerSetPosition ���� ���� �÷��̾� ��ǥ�� SetStartStageCoordinate �� ����Ͽ� ���� ���� ��ǥ�� ���Ѵ�.
	playerX += stageX;
	playerY += stageY;

	// ������ ȭ��� map 2���� �迭�� 1:1 �� ��Ī ��Ų��.
	StageToMap(pnt);

	// map 2���� �迭�� ���ؼ� ���� ȭ�鿡 �׸���.
	GameDraw();

	// �÷��̾� ������ ȭ�鿡 �׸���.
	PlayerDraw();

	stageClearFlag = 0;
	playerMoveCount = 0;
	playerPushCount = 0;
	undoCount = 0;
}

void HideCursor()
{
	// Ŀ�� ���� (�����)
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO cursorInfo;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorInfo.bVisible = 0; // �������
	cursorInfo.dwSize = 1;   // ũ�� ����
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}
