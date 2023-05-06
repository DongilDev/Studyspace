#pragma once

#define test 1
#define ESC 27

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define DELAY	300 // 0.3초 , 1000하면 1초

#define SIZE_MAP_X 48
#define SIZE_MAP_Y 25

#define STAGE_MAX 67

#define UNDO_MAX 20 // 최대 열번까지 취소가능
#define BACK_SPACE 8

#define RESTART 114

#define PLAYER_MOVE_MAX 1000

#define PAGE_UP 73
#define PAGE_DOWN 81

#define REPLAY 'h'

enum
{
	BLACK,			//  0 : 까망
	DARK_BLUE,		// 1 : 어두운 파랑 
	DARK_GREEN,		// 2 : 어두운 초록 
	DARK_SKY_BLUE,	// 3 : 어두운 하늘 
	DARK_RED,		// 4 : 어두운 빨강
	DARK_VIOLET,	// 5 : 어두운 보라 
	DARK_YELLOW,	// 6 : 어두운 노랑 
	GRAY,			// 7 : 회색 
	DARK_GRAY,		// 8 : 어두운 회색 
	BLUE,			// 9 : 파랑 
	GREEN,			// 10 : 초록 
	SKY_BLUE,		// 11 : 하늘 
	RED,			// 12 : 빨강 
	VIOLET,			// 13 : 보라 
	YELLOW,			// 14 : 노랑 
	WHITE,			// 15 : 하양	
};

enum
{
	KEY_UP,
	KEY_DOWN,
	KEY_SUBMIT,
};

enum SOUNDNUMBER
{
	// 배경
	MAINBACKGROUND,

	// 이펙트
	MOVE_CURSOR,
	MOVE_BOX,
	STAGE_CLEAR,
	CLICK_CURSOR,
	PLAYER_MOVE,

	// 끝
	SOUND_END,
};