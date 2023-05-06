#pragma once

typedef struct
{
	char map[30][60];
	int playerX;
	int playerY;
	int playerMoveCount;
	int playerPushCount;
}UNDO;

UNDO Undo[20];

void MapInit();
void SetStartStageCoordinate(const char* pnt);
void StageToMap(const char* pnt);

void gotoxy(int x, int y);
void SetColor(int color);

void MainDraw();
void InfoDraw();

void MapDraw(int x, int y);
void GameDraw();
void PlayerDraw();

void TitleDraw();
void StageDraw();
void PlayerMoveCountDraw();
void PlayerPushCountDraw();
void GameHelpDraw();
void UndoDraw();
void GameStateDraw();

void GameUndo();

void StageClear();
void GameOver();