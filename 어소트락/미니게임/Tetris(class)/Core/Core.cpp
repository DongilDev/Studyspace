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
	// 콘솔창 핸들 생성
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	// 스테이지 관리자를 초기화한다.
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
	// 한칸은 2바이트를 사용한다. 그렇기 때문에 *2 를 해준다.
	// 테트리스에서는 특수문자를 사용하여 1칸을 표현하므로 *2 를 해주어야 한다.
	COORD pos = { (x+1)*2, y };
	SetConsoleCursorPosition(m_hConsole, pos);
}