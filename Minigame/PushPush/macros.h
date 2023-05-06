#pragma once

#define test 1
#define ESC 27

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define DELAY	300 // 0.3�� , 1000�ϸ� 1��

#define SIZE_MAP_X 48
#define SIZE_MAP_Y 25

#define STAGE_MAX 67

#define UNDO_MAX 20 // �ִ� �������� ��Ұ���
#define BACK_SPACE 8

#define RESTART 114

#define PLAYER_MOVE_MAX 1000

#define PAGE_UP 73
#define PAGE_DOWN 81

#define REPLAY 'h'

enum
{
	BLACK,			//  0 : ���
	DARK_BLUE,		// 1 : ��ο� �Ķ� 
	DARK_GREEN,		// 2 : ��ο� �ʷ� 
	DARK_SKY_BLUE,	// 3 : ��ο� �ϴ� 
	DARK_RED,		// 4 : ��ο� ����
	DARK_VIOLET,	// 5 : ��ο� ���� 
	DARK_YELLOW,	// 6 : ��ο� ��� 
	GRAY,			// 7 : ȸ�� 
	DARK_GRAY,		// 8 : ��ο� ȸ�� 
	BLUE,			// 9 : �Ķ� 
	GREEN,			// 10 : �ʷ� 
	SKY_BLUE,		// 11 : �ϴ� 
	RED,			// 12 : ���� 
	VIOLET,			// 13 : ���� 
	YELLOW,			// 14 : ��� 
	WHITE,			// 15 : �Ͼ�	
};

enum
{
	KEY_UP,
	KEY_DOWN,
	KEY_SUBMIT,
};

enum SOUNDNUMBER
{
	// ���
	MAINBACKGROUND,

	// ����Ʈ
	MOVE_CURSOR,
	MOVE_BOX,
	STAGE_CLEAR,
	CLICK_CURSOR,
	PLAYER_MOVE,

	// ��
	SOUND_END,
};