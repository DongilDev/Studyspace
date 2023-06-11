#pragma once

// 1. ������ ����ȭ
// ���� ������ ������ ���� Ű�� ����, ������ �̺�Ʈ�� ��������.

// 2. Ű �Է� �̺�Ʈ ó��
// tap, hold, away

enum class KEY_STATE
{
	NONE, // �������� ������ �ʰ�, ���絵 ������ �ʴ�
	TAP,  // ������ ������ �ʰ�, ����� ������ �ִ�
	HOLD, // ������ ���Ȱ�, ���絵 ������ �ִ� 
	AWAY, // ������ ���Ȱ�, ����� ������ �ʴ�
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,
	Z,X,C,V,B,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,



	LAST,
};

struct tKeyInfo
{
	KEY_STATE	eState; // Ű�� ���°�
	bool		bPrevPush;  // ���� �����ӿ��� ���ȴ��� ����
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
};