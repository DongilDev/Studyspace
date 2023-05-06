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
	stageClearFlag = 1;	 // �ʰ� �������̽� ����� ������������ 1ȸ ���
	stage = StageClearFileLoad(); // ���� ���̺������� Ȯ�� �� �������� ��������
	HideCursor();	// Ŀ�� �����
	SoundInit();    // ���� ��ü ���� �� �ʱ�ȭ

	while(true)
	{
		// Ÿ��Ʋ
		if (gameState == 0)
		{
			LoopSound(MAINBACKGROUND);  // ������� ���� 
			MainDraw(); // Ÿ��Ʋ ���;
		}

		// ���� �÷���
		else if (gameState == 1)
		{
			if (stageClearFlag != 0) 
			{
				SoundStopSound();
				system("cls");    
				StageInit();		// �������� �ʱ�ȭ
				GameStateDraw();	// ���� �������̽� ���

				if (stage + 1 == STAGE_MAX)
				{
					StageClear();   // �������� Ŭ���� ���ڿ� ���
					GameOver();   	// ���� ����
					break;
				}
			}

			PlayerAction();  // �÷��̾� Ű �Է�
		}
		
		// ���̺����� ����
		else if (gameState == 2)
		{
			DeleteSaveFile(); 
			gameState = 0;
			system("cls");
		}

		// ���� ���
		else if (gameState == 3)
		{
			GameHelpDraw(); 
			gameState = 0;
			system("cls");
		}

		// ���� ����
		else if (gameState == 4)
		{
			GameOver();
			break;
		}
	}

	return 0;
}