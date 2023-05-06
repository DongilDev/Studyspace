#include "file.h"
#include "flag.h"
#include "macros.h"

int stageClear[STAGE_MAX];
int pushCount[STAGE_MAX];
int moveCount[STAGE_MAX];

extern int stage;
extern int replayBuffer[PLAYER_MOVE_MAX];
extern char map[SIZE_MAP_Y][SIZE_MAP_X];
extern int playerPushCount;
extern int playerMoveCount;
extern char playerMove[PLAYER_MOVE_MAX];

int StageClearFileLoad()
{
	char buffer[12];	
	char filename[12];
	int ret = 0;
	FILE* fp;

	for (int i = 0; i < STAGE_MAX; ++i)
	{
		sprintf_s(filename,sizeof(filename), "stage%02d.txt", i);

		if (fopen_s(&fp, filename, "rt") != 0)
		{
			stageClear[i] = 0;
		}
		else
		{
			stageClear[i] = 1;

			fgets(buffer, 12, fp);
			pushCount[i] = (buffer[5] - '0') * 100 + (buffer[6] - '0') * 10 + (buffer[7] - '0');
			moveCount[i] = (buffer[8] - '0') * 100 + (buffer[9] - '0') * 10 + (buffer[10] - '0');

			fclose(fp);
			fp = NULL;
		}
	}

	for (int i = 0; i < STAGE_MAX; ++i)
	{
		sprintf_s(filename, sizeof(filename), "stage%02d.txt", i);

		if (fopen_s(&fp, filename, "rt") != 0)
		{
			ret = i;
			break;
		}
		else
		{
			fclose(fp);
			fp = NULL;
		}
	}

	return ret;
}

void StageReplayLoad()
{
	char buffer[12];
	char filename[12];
	FILE* fp;

	sprintf_s(filename, sizeof(filename), "stage%02d.txt", stage);

	if (fopen_s(&fp, filename, "rt") != 0)
		return;

	fgets(buffer, 12, fp); // 키 받기 전 앞의 정보를 읽어 커서를 옮김
	fgets(replayBuffer, moveCount[stage] + 1, fp); // 문자열 끝에있는 널까지 같이 읽음

	fclose(fp);
	fp = NULL;
}

int StageClearCheck()
{
	char data;

	for (int y = 0; y < SIZE_MAP_Y; ++y)
	{
		for (int x = 0; x < SIZE_MAP_X; ++x)
		{
			data = map[y][x];

			if (data == '3') 
				return 0;
		}
	}
		
	return 1;
}

void StageClearFileSave()
{
	char filename[12];
	char c;
	int temp;
	FILE* fp;

	sprintf_s(filename, sizeof(filename), "stage%02d.txt", stage);

	if (fopen_s(&fp, filename, "wt") != 0)
		return;

	// 00 
	fputc('t', fp);
	// 01 
	fputc('x', fp);
	// 02 
	fputc('t', fp);

	// 03 stage 의 10의 자리
	temp = stage;
	c = temp / 10;
	fputc(c + '0', fp);

	// 04 stage 의 1의 자리
	temp -= c * 10;
	fputc(temp + '0', fp);

	// 05 PushCount 의 100의 자리 
	temp = playerPushCount;
	c = temp / 100;
	fputc(c + '0', fp);

	// 06 PushCount 의 10의 자리
	temp -= c * 100; c = temp / 10;
	fputc(c + '0', fp);

	// 07 PushCount 의 1의 자리
	temp -= c * 10;
	fputc(temp + '0', fp);

	// 08 MoveCount 의 100의 자리
	temp = playerMoveCount;
	c = temp / 100;
	fputc(c + '0', fp);

	// 09 MoveCount 의 10의 자리
	temp -= c * 100;
	c = temp / 10;
	fputc(c + '0', fp);

	// 10 MoveCount 의 1의 자리
	temp -= c * 10;
	fputc(temp + '0', fp);

	// 11 리플레이를 위한 플레이어 방향 입력 정보
	for (int i = 0; i < playerMoveCount; ++i)
	{
		fputc(playerMove[i], fp);
	}
	fclose(fp);
}

void DeleteSaveFile()
{
	char filename[12];
	FILE* fp;
	bool isFile = false;

	int x = 35;
	int y = 5;

	system("cls");

	for (int i = 0; i < 67; ++i)
	{
		sprintf_s(filename, sizeof(filename), "stage%02d.txt", i);
		if (fopen_s(&fp, filename, "rt") == 0)
		{
			fclose(fp);
			remove(filename);
			isFile = true;

			SetColor(RED);
			gotoxy(x+ 2, y);
			printf("%s 초기화 성공", filename);
			++y;
		}
	}


	

	if (isFile == 0)
	{
		SetColor(RED);
		gotoxy(x + 2, y + 5);
		printf("세이브 파일이 없습니다.");

		SetColor(YELLOW);
		gotoxy(x - 2, 15);
		printf("press space key to main screen");
	}

	else
	{
		SetColor(YELLOW);
		gotoxy(x - 2, y + 5);
		printf("press space key to main screen");
	}

	while (1)
	{
		if (KeyControl() == KEY_SUBMIT)
			break;
	}
}
