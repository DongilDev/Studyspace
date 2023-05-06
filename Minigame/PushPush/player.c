#include "flag.h"
#include "player.h"
#include "macros.h"
#include "file.h"
#include "render.h"
#include "sound.h"

int playerX;
int playerY;

int replayFlag; // 0 이었다가 <H>를 눌러 리플레이를하면 1로 바뀌게함
int replayCount;  // txt 0000 4010 MKKHPPKMMP 뒤에 방향키 인덱스(위치) 정보를 하나씩 받게됨  (MKKHPPKMMP 이것)
char replayBuffer[PLAYER_MOVE_MAX];

int exitFlag;

char* stageClear1 = " S T A G E  C L E A R";
char* stageClear2 = "press space key to next stage";

char playerMove[PLAYER_MOVE_MAX];

extern int undoCount;
extern int stageClearFlag;
extern int stageClear[STAGE_MAX];
extern int stage;
extern int moveCount[STAGE_MAX];
extern char map[SIZE_MAP_Y][SIZE_MAP_X];
extern int playerMoveCount;
extern int playerPushCount;
extern UNDO Undo[UNDO_MAX];
extern int gameState;

// 플레이어 위치 구하기
int PlayerGetPosition(const char* pnt)
{
	int position;
	char data;

	data = *(pnt++);
	position = data - '0';
	position *= 10;
	
	data = *(pnt++);
	position += data - '0';

	return position;
}

// 플레이어 위치 설정
void PlayerSetPosition(const char* pnt)
{
	playerX = PlayerGetPosition(pnt);
	playerY = PlayerGetPosition(pnt + 2);
}

// 플레이어 키 입력 받기
int Getkey()
{
	int key = 0; // 키 입력 반환 값
	int nowState[100] = { 0, };  // 현재 키 입력 상태 배열
	int prevState[100] = { 0, }; // 이전 키 입력 상태 배열
	
	// 게임 종료 (스테이지에서 메인메뉴로)
	if (GetAsyncKeyState(VK_ESCAPE) & 0x1) 
		nowState[VK_ESCAPE] = 1; // 현재 눌렀다
	else
		nowState[VK_ESCAPE] = 0; // 현재 안눌렀다

	if (prevState[VK_ESCAPE] == 0 && nowState[VK_ESCAPE] == 1) // 이전에 안눌렀고 현재 눌렀으면 !! 버튼 다운 !! 
	{
		system("cls");
		gameState = 0;
		stageClearFlag = 1;
		return key;
	}
	prevState[VK_ESCAPE] = nowState[VK_ESCAPE]; // 이전 키 상태에 현재 키 상태를 넣어준다.

	// 뒤로 가기
	if (GetAsyncKeyState(VK_BACK) & 0x1)
		nowState[VK_BACK] = 1;
	else
		nowState[VK_BACK] = 0;

	if (prevState[VK_BACK] == 0 && nowState[VK_BACK] == 1)
	{
		if (undoCount > 0)
			GameUndo();
	}
	prevState[VK_BACK] = nowState[VK_BACK];

	// 재시작 (VK_R)
	if (GetAsyncKeyState(0x52) & 0x1)
		nowState[0x52] = 1;
	else
		nowState[0x52] = 0;

	if (prevState[0x52] == 0 && nowState[0x52] == 1)
		stageClearFlag = 1;
	prevState[0x52] = nowState[0x52];

	// 리플레이 (VK_H)
	if (GetAsyncKeyState(0x48) & 0x1)
		nowState[0x48] = 1;
	else
		nowState[0x48] = 0;

	if (prevState[0x48] == 0 && nowState[0x48] == 1)
	{
		if (replayFlag == 0 && stageClear[stage] == 1)
		{
			replayFlag = 1;
			replayCount = 0;
			StageReplayLoad();
		}
	}
	prevState[0x48] = nowState[0x48];

	// 스테이지 변경 (PageUp)
	if (GetAsyncKeyState(VK_PRIOR) & 0x1)
		nowState[VK_PRIOR] = 1;
	else
		nowState[VK_PRIOR] = 0;

	if (prevState[VK_PRIOR] == 0 && nowState[VK_PRIOR] == 1)
	{
		if (++stage >= STAGE_MAX)
			stage = 0;
		stageClearFlag = 1;
	}
	prevState[VK_PRIOR] = nowState[VK_PRIOR];

	// 스테이지 변경 (PageDown)
	if (GetAsyncKeyState(VK_NEXT) & 0x1)
		nowState[VK_NEXT] = 1;
	else
		nowState[VK_NEXT] = 0;

	if (prevState[VK_NEXT] == 0 && nowState[VK_NEXT] == 1)
	{
		if (--stage < 0)
			stage = STAGE_MAX - 1;
		stageClearFlag = 1;
	}
	prevState[VK_NEXT] = nowState[VK_NEXT];
	
	// 방향키 UP 
	if (GetAsyncKeyState(VK_UP) & 0x1)
		nowState[VK_UP] = 1;
	else
		nowState[VK_UP] = 0;

	if (prevState[VK_UP] == 0 && nowState[VK_UP] == 1)
	{
		key = UP;
	}
	prevState[VK_UP] = nowState[VK_DOWN];

	// 방향키 DOWN
	if (GetAsyncKeyState(VK_DOWN) & 0x1)
		nowState[VK_DOWN] = 1;
	else
		nowState[VK_DOWN] = 0;

	if (prevState[VK_DOWN] == 0 && nowState[VK_DOWN] == 1)
	{
		key = DOWN;
	}
	prevState[VK_LEFT] = nowState[VK_LEFT];

	// 방향키 LEFT
	if (GetAsyncKeyState(VK_LEFT) & 0x1)
		nowState[VK_LEFT] = 1;
	else
		nowState[VK_LEFT] = 0;

	if (prevState[VK_LEFT] == 0 && nowState[VK_LEFT] == 1)
	{
		key = LEFT;
	}
	prevState[VK_LEFT] = nowState[VK_LEFT];

	// 방향키 RIGHT
	if (GetAsyncKeyState(VK_RIGHT) & 0x1)
		nowState[VK_RIGHT] = 1;
	else
		nowState[VK_RIGHT] = 0;

	if (prevState[VK_RIGHT] == 0 && nowState[VK_RIGHT] == 1)
	{
		key = RIGHT;
	}
	prevState[VK_RIGHT] = nowState[VK_RIGHT];

	return key;
}

int GetkeyReplay()
{
	int key;
	key = replayBuffer[replayCount];
	
	if (++replayCount >= moveCount[stage])
		replayFlag = 0;

	Sleep(DELAY);
		
	return key;
}

void UndoSave()
{
	if (undoCount >= UNDO_MAX) // 만약 보관장소가 꽉 찼으면
	{ 
		for (int i = 1; i < UNDO_MAX; ++i) // 하나씩 앞으로 밀어준다
		{  
			for (int y = 0; y < SIZE_MAP_Y; ++y) 
			{
				for (int x = 0; x < SIZE_MAP_X; ++x)
				{
					Undo[i - 1].map[y][x] = Undo[i].map[y][x];
				}
			}

			Undo[i - 1].playerX = Undo[i].playerX;
			Undo[i - 1].playerY = Undo[i].playerY;
			Undo[i - 1].playerMoveCount = Undo[i].playerMoveCount;
			Undo[i - 1].playerPushCount = Undo[i].playerPushCount;
		}
		
		--undoCount;
	}

	for (int y = 0; y < SIZE_MAP_Y; ++y) //보관 장소가 꽉 안찼으면
	{  
		for (int x = 0; x < SIZE_MAP_X; ++x) 
		{
			Undo[undoCount].map[y][x] = map[y][x];
		}
	}

	Undo[undoCount].playerX = playerX;
	Undo[undoCount].playerY = playerY;
	Undo[undoCount].playerMoveCount = playerMoveCount;
	Undo[undoCount].playerPushCount = playerPushCount;
	++undoCount;
}

void PlayerErase()
{
	MapDraw(playerX, playerY);
}

void PlayerAction()
{
	int moveFlag = 0;
	int dx = 0, dy = 0;
	char key;
	char data;
	char data2;

	if (replayFlag == 0) // 리플레이 X
		key = Getkey(); // 사용자 입력 받기

	else
		key = GetkeyReplay(); // 리플레이 O

	switch (key)
	{
	case UP:
		dx = 0; dy = -1;
		break;
	case DOWN:
		dx = 0; dy = 1;
		break;
	case LEFT:
		dx = -1; dy = 0;
		break;
	case RIGHT:
		dx = 1; dy = 0;
		break;
	}

	if (dx == 0 && dy == 0) // 방향키 키 이외의 키 처리 
		return; 

	data = map[playerY + dy][playerX + dx]; // 플레이어가 방향키 입력에 따라서 이동할 위치 (한 칸 앞)
	data2 = map[playerY + dy + dy][playerX + dx + dx]; // (두 칸 앞)

	if (data == '2') // 이동할 공간이 움직일 박스
	{
		if (data2 == '0') // 그 다음 칸이 빈 공간
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();
			
			map[playerY + dy][playerX + dx] = '0'; // 박스가 있던 곳은 빈 공간으로 바꾸고
			map[playerY + dy + dy][playerX + dx + dx] = '2'; // 빈 공간 은 움직일 박스로 교체
			
			MapDraw(playerX + dx + dx, playerY + dy + dy);

			moveFlag = 1;
			++playerPushCount;

			PlayerPushCountDraw();
		}

		else if (data2 == '3') // 이동할 공간이 목적지
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();

			map[playerY + dy][playerX + dx] = '0'; // 박스가 있던 곳은 빈 공간으로 바꾸고
			map[playerY + dy + dy][playerX + dx + dx] = '4'; // 목적지를 완성된 목적지로 교체

			MapDraw(playerX + dx + dx, playerY + dy + dy);

			moveFlag = 1;
			++playerPushCount;

			PlayerPushCountDraw();
		}
	}

	else if (data == '4') // 이동할 공간이 완성된 목적지
	{
		if (data2 == '0') // 그 다음 칸이 빈 공간
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();

			map[playerY + dy][playerX + dx] = '3'; // 완성된 목적지를 그냥 목적지로 바꾸고
			map[playerY + dy + dy][playerX + dx + dx] = '2'; // 빈 공간을 벽으로 교체

			MapDraw(playerX + dx + dx, playerY + dy + dy);

			moveFlag = 1;
			++playerPushCount;

			PlayerPushCountDraw();
		}
		
		else if (data2 == '3') // 그 다음 칸이 목적지 
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();

			map[playerY + dy][playerX + dx] = '3'; // 이동할 공간의 완성된 목적지를 목적지로 바꾸고
			map[playerY + dy + dy][playerX + dx + dx] = '4'; // 목적지를 완성된 목적지로 교체

			MapDraw(playerX + dx + dx, playerY + dy + dy);

			moveFlag = 1;
			++playerPushCount;

			PlayerPushCountDraw();
		}
	}

	else
	{
		if (data != '1')
		{

			UndoSave();
			moveFlag = 1;
		}
	}

	if (moveFlag != 0) // 플레이어가 움직인다는 상황
	{ 
		playerMove[playerMoveCount] = key;

		PlayerErase();

		playerX += dx;
		playerY += dy;
		++playerMoveCount;

		PlayerMoveCountDraw();
		PlayerDraw();
		UndoDraw();

		if (StageClearCheck() != 0) // 스테이지 성공
		{ 
			SoundPlayEffect(STAGE_CLEAR);

			StageClearFileSave();

			SetColor(GREEN);
			gotoxy(64, 10);
			printf("%s", stageClear1);
			gotoxy(60, 12);
			printf("%s", stageClear2);

			while(1)
			{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000)
					break;
			}

			stage += 1;

			if (stage >= STAGE_MAX)
				stage = 0;

			stageClearFlag = 1;
		}
	}
}

int KeyControl()
{
	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		SoundPlayEffect(MOVE_CURSOR);
		return KEY_UP;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		SoundPlayEffect(MOVE_CURSOR);
		return KEY_DOWN;
	}		
	else if (GetAsyncKeyState(' ') & 0x0001)
	{
		SoundPlayEffect(CLICK_CURSOR);
		return KEY_SUBMIT;
	}
	else
		return 4;
}