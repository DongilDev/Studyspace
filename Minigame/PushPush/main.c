#include "core.h"
#include "flag.h"
#include "macros.h"
#include "sound.h"
#include "file.h"
#include "render.h"
#include "player.h"

extern int exitFlag;
extern int stageClearFlag;
extern int stage;
extern int gameState;
extern FMOD_CHANNEL* channelMusic;

int main()
{
	gameState = 0; 
	stageClearFlag = 1;	 // 맵과 인터페이스 출력을 스테이지마다 1회 출력
	stage = StageClearFileLoad(); // 이전 세이브파일을 확인 후 스테이지 가져오기
	HideCursor();	// 커서 숨기기
	SoundInit();    // 사운드 객체 생성 및 초기화

	while(true)
	{
		// 타이틀
		if (gameState == 0)
		{
			LoopSound(MAINBACKGROUND);  // 배경음악 시작 
			MainDraw(); // 타이틀 출력;
		}

		// 게임 플레이
		else if (gameState == 1)
		{
			if (stageClearFlag != 0) 
			{
				SoundStopSound();
				system("cls");    
				StageInit();		// 스테이지 초기화
				GameStateDraw();	// 게임 인터페이스 출력

				if (stage + 1 == STAGE_MAX)
				{
					StageClear();   // 스테이지 클리어 문자열 출력
					GameOver();   	// 게임 종료
					break;
				}
			}

			PlayerAction();  // 플레이어 키 입력
		}
		
		// 세이브파일 삭제
		else if (gameState == 2)
		{
			DeleteSaveFile(); 
			gameState = 0;
			system("cls");
		}

		// 게임 방법
		else if (gameState == 3)
		{
			GameHelpDraw(); 
			gameState = 0;
			system("cls");
		}

		// 게임 종료
		else if (gameState == 4)
		{
			GameOver();
			break;
		}
	}

	return 0;
}