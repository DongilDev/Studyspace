#include "Core.h"
#include "StageManager.h"
#include "ShapeManager.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore() :
	m_bLoop(true)
{
	srand(time(0));
}	

CCore::~CCore()
{
	CShapeManager::DestroyInst();
	CStageManager::DestroyInst();
}

bool CCore::Init()
{
	// �ܼ�â �ڵ� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	// �������� �����ڸ� �ʱ�ȭ�Ѵ�.
	if (!CStageManager::GetInst()->Init())
		return false;

	return true;
}

void CCore::Run()
{
	while (m_bLoop)
	{		
		system("cls");
		CShapeManager::GetInst()->Update();

		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();

		Sleep(30);
	}	
}

void CCore::SetConsolePos(int x, int y)
{
	// ��ĭ�� 2����Ʈ�� ����Ѵ�. �׷��� ������ *2 �� ���ش�.
	// ��Ʈ���������� Ư�����ڸ� ����Ͽ� 1ĭ�� ǥ���ϹǷ� *2 �� ���־�� �Ѵ�.
	COORD pos = { (x+1)*2, y };
	SetConsoleCursorPosition(m_hConsole, pos);
}