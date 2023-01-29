#include "Core.h"
#include "StageManager.h"
#include "ObjectManager.h"
#include "StoreManager.h"
#include "Inventory.h"

DEFINITION_SINGLE(CCore)

enum MAIN_MENU
{
	MM_NONE,
	MM_STAGE,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

CCore::CCore()
{	
}

CCore::~CCore()
{
	DESTROY_SINGLE(CInventory);
	DESTROY_SINGLE(CStoreManager);
	DESTROY_SINGLE(CObjectManager);
	DESTROY_SINGLE(CStageManager);
}

LEVELUPINFO CCore::GetLevelUpInfo(JOB eJob)
{
	return m_tLevelUpInfo[eJob - 1];
}

bool CCore::Init()
{
	// 레벨업시 상승 능력치를 생성한다.
	SetLevelUpInfo();

	// 오브젝트 관리자 초기화
	if (!GET_SINGLE(CObjectManager)->Init())
		return false;

	// Stage를 초기화한다.
	if (!GET_SINGLE(CStageManager)->Init())
		return false;
	
	// 상점 관리자를 초기화한다.
	if (!GET_SINGLE(CStoreManager)->Init())
		return false;

	// 인벤토리를 초기화한다.
	if (!GET_SINGLE(CInventory)->Init())
		return false;

	return true;
}

void CCore::Run()
{
	while (true)
	{
		switch (OutputMenu())
		{
		case MM_STAGE:
			GET_SINGLE(CStageManager)->Run();
			break;
		case MM_STORE:
			GET_SINGLE(CStoreManager)->Run();
			break;
		case MM_INVENTORY:
			GET_SINGLE(CInventory)->Run();
			break;
		case MM_EXIT:
			return;
		}
	}

}

int CCore::OutputMenu()
{
	system("cls");
	cout << "1. 맵" << endl;
	cout << "2. 상점" << endl;
	cout << "3. 인벤토리" << endl;
	cout << "4. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iMenu = Input<int>();

	if (iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;

	return iMenu;
}

void CCore::SetLevelUpInfo()
{
	// 레벨업에 필요한 정보 상승 구조체를 만들어준다.
	m_tLevelUpInfo[JOB_KNIGHT - 1] = CreateLevelUpInfo(5, 10, 15, 20, 100, 10);
	m_tLevelUpInfo[JOB_ARCHER - 1] = CreateLevelUpInfo(10, 15, 10, 25, 80, 30);
	m_tLevelUpInfo[JOB_WIZARD - 1] = CreateLevelUpInfo(15, 20, 5, 10, 50, 50);
}

LEVELUPINFO CCore::CreateLevelUpInfo(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iMP)
{
	LEVELUPINFO tInfo = {};

	tInfo.iAttackMin = iAttackMin;
	tInfo.iAttackMax = iAttackMax;
	tInfo.iArmorMin = iArmorMin;
	tInfo.iArmorMax = iArmorMax;
	tInfo.iHP = iHP;
	tInfo.iMP = iMP;
	return tInfo;
}


