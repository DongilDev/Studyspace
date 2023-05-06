#include "flag.h"
#include "player.h"
#include "macros.h"
#include "file.h"
#include "render.h"
#include "sound.h"

int playerX;
int playerY;

int replayFlag; // 0 �̾��ٰ� <H>�� ���� ���÷��̸��ϸ� 1�� �ٲ����
int replayCount;  // txt 0000 4010 MKKHPPKMMP �ڿ� ����Ű �ε���(��ġ) ������ �ϳ��� �ްԵ�  (MKKHPPKMMP �̰�)
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

// �÷��̾� ��ġ ���ϱ�
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

// �÷��̾� ��ġ ����
void PlayerSetPosition(const char* pnt)
{
	playerX = PlayerGetPosition(pnt);
	playerY = PlayerGetPosition(pnt + 2);
}

// �÷��̾� Ű �Է� �ޱ�
int Getkey()
{
	int key = 0; // Ű �Է� ��ȯ ��
	int nowState[100] = { 0, };  // ���� Ű �Է� ���� �迭
	int prevState[100] = { 0, }; // ���� Ű �Է� ���� �迭
	
	// ���� ���� (������������ ���θ޴���)
	if (GetAsyncKeyState(VK_ESCAPE) & 0x1) 
		nowState[VK_ESCAPE] = 1; // ���� ������
	else
		nowState[VK_ESCAPE] = 0; // ���� �ȴ�����

	if (prevState[VK_ESCAPE] == 0 && nowState[VK_ESCAPE] == 1) // ������ �ȴ����� ���� �������� !! ��ư �ٿ� !! 
	{
		system("cls");
		gameState = 0;
		stageClearFlag = 1;
		return key;
	}
	prevState[VK_ESCAPE] = nowState[VK_ESCAPE]; // ���� Ű ���¿� ���� Ű ���¸� �־��ش�.

	// �ڷ� ����
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

	// ����� (VK_R)
	if (GetAsyncKeyState(0x52) & 0x1)
		nowState[0x52] = 1;
	else
		nowState[0x52] = 0;

	if (prevState[0x52] == 0 && nowState[0x52] == 1)
		stageClearFlag = 1;
	prevState[0x52] = nowState[0x52];

	// ���÷��� (VK_H)
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

	// �������� ���� (PageUp)
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

	// �������� ���� (PageDown)
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
	
	// ����Ű UP 
	if (GetAsyncKeyState(VK_UP) & 0x1)
		nowState[VK_UP] = 1;
	else
		nowState[VK_UP] = 0;

	if (prevState[VK_UP] == 0 && nowState[VK_UP] == 1)
	{
		key = UP;
	}
	prevState[VK_UP] = nowState[VK_DOWN];

	// ����Ű DOWN
	if (GetAsyncKeyState(VK_DOWN) & 0x1)
		nowState[VK_DOWN] = 1;
	else
		nowState[VK_DOWN] = 0;

	if (prevState[VK_DOWN] == 0 && nowState[VK_DOWN] == 1)
	{
		key = DOWN;
	}
	prevState[VK_LEFT] = nowState[VK_LEFT];

	// ����Ű LEFT
	if (GetAsyncKeyState(VK_LEFT) & 0x1)
		nowState[VK_LEFT] = 1;
	else
		nowState[VK_LEFT] = 0;

	if (prevState[VK_LEFT] == 0 && nowState[VK_LEFT] == 1)
	{
		key = LEFT;
	}
	prevState[VK_LEFT] = nowState[VK_LEFT];

	// ����Ű RIGHT
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
	if (undoCount >= UNDO_MAX) // ���� ������Ұ� �� á����
	{ 
		for (int i = 1; i < UNDO_MAX; ++i) // �ϳ��� ������ �о��ش�
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

	for (int y = 0; y < SIZE_MAP_Y; ++y) //���� ��Ұ� �� ��á����
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

	if (replayFlag == 0) // ���÷��� X
		key = Getkey(); // ����� �Է� �ޱ�

	else
		key = GetkeyReplay(); // ���÷��� O

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

	if (dx == 0 && dy == 0) // ����Ű Ű �̿��� Ű ó�� 
		return; 

	data = map[playerY + dy][playerX + dx]; // �÷��̾ ����Ű �Է¿� ���� �̵��� ��ġ (�� ĭ ��)
	data2 = map[playerY + dy + dy][playerX + dx + dx]; // (�� ĭ ��)

	if (data == '2') // �̵��� ������ ������ �ڽ�
	{
		if (data2 == '0') // �� ���� ĭ�� �� ����
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();
			
			map[playerY + dy][playerX + dx] = '0'; // �ڽ��� �ִ� ���� �� �������� �ٲٰ�
			map[playerY + dy + dy][playerX + dx + dx] = '2'; // �� ���� �� ������ �ڽ��� ��ü
			
			MapDraw(playerX + dx + dx, playerY + dy + dy);

			moveFlag = 1;
			++playerPushCount;

			PlayerPushCountDraw();
		}

		else if (data2 == '3') // �̵��� ������ ������
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();

			map[playerY + dy][playerX + dx] = '0'; // �ڽ��� �ִ� ���� �� �������� �ٲٰ�
			map[playerY + dy + dy][playerX + dx + dx] = '4'; // �������� �ϼ��� �������� ��ü

			MapDraw(playerX + dx + dx, playerY + dy + dy);

			moveFlag = 1;
			++playerPushCount;

			PlayerPushCountDraw();
		}
	}

	else if (data == '4') // �̵��� ������ �ϼ��� ������
	{
		if (data2 == '0') // �� ���� ĭ�� �� ����
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();

			map[playerY + dy][playerX + dx] = '3'; // �ϼ��� �������� �׳� �������� �ٲٰ�
			map[playerY + dy + dy][playerX + dx + dx] = '2'; // �� ������ ������ ��ü

			MapDraw(playerX + dx + dx, playerY + dy + dy);

			moveFlag = 1;
			++playerPushCount;

			PlayerPushCountDraw();
		}
		
		else if (data2 == '3') // �� ���� ĭ�� ������ 
		{
			SoundPlayEffect(MOVE_BOX);

			UndoSave();

			map[playerY + dy][playerX + dx] = '3'; // �̵��� ������ �ϼ��� �������� �������� �ٲٰ�
			map[playerY + dy + dy][playerX + dx + dx] = '4'; // �������� �ϼ��� �������� ��ü

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

	if (moveFlag != 0) // �÷��̾ �����δٴ� ��Ȳ
	{ 
		playerMove[playerMoveCount] = key;

		PlayerErase();

		playerX += dx;
		playerY += dy;
		++playerMoveCount;

		PlayerMoveCountDraw();
		PlayerDraw();
		UndoDraw();

		if (StageClearCheck() != 0) // �������� ����
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