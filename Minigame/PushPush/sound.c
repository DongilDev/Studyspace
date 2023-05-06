#include "sound.h"
#include "flag.h"
#include "macros.h"
#include <assert.h>

FMOD_SYSTEM* fsystem;
FMOD_SOUND* sound[SOUND_END];
FMOD_RESULT result;
FMOD_CHANNEL* channelMusic;
FMOD_CHANNEL* channelEffect;

void SoundInit()
{
	int result = 0;
	// FMOD �ý��� ��ü �ʱ�ȭ
	result=FMOD_System_Create(&fsystem, FMOD_VERSION);
	assert(!result);

	result=FMOD_System_Init(fsystem, 32, FMOD_INIT_NORMAL, NULL);
	assert(!result);

	// ���� ����
	result =FMOD_System_CreateSound(fsystem, "music\\MainBackground.mp3", FMOD_DEFAULT, 0, &sound[MAINBACKGROUND]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, "music\\MoveCursor.wav", FMOD_DEFAULT, 0, &sound[MOVE_CURSOR]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, "music\\MoveBox.mp3", FMOD_DEFAULT, 0, &sound[MOVE_BOX]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, "music\\StageClear.wav", FMOD_DEFAULT, 0, &sound[STAGE_CLEAR]);
	assert(!result);
	result = FMOD_System_CreateSound(fsystem, "music\\ClickCursor.wav", FMOD_DEFAULT, 0, &sound[CLICK_CURSOR]);
	assert(!result);
}

void SoundExit()
{
	// �ý��� ��ü ����
	FMOD_System_Release(fsystem);
}

void SoundPlaySound(int soundNumber)
{
	// ���� ���� �ε� �� ���
	FMOD_System_PlaySound(fsystem, sound[soundNumber], NULL, 0, &channelMusic);
}

void SoundPlayEffect(int soundNumber)
{
	// ���� ���� �ε� �� ���
	FMOD_System_PlaySound(fsystem, sound[soundNumber], NULL, 0, &channelEffect);
}

void SoundStopSound()
{
	// ��� ���� ���� ���߱�
	FMOD_Channel_Stop(channelMusic);
}

void LoopSound(int soundNumber)
{
	FMOD_BOOL isPlaying = false;
	FMOD_Channel_IsPlaying(channelMusic, &isPlaying);

	// ��� ���� �ƴϸ� ���
	if (!isPlaying)
	{
		SoundPlaySound(soundNumber);
	}
}
