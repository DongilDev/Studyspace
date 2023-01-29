#include "StoreManager.h"
#include "StoreWeapon.h"
#include "StoreArmor.h"

DEFINITION_SINGLE(CStoreManager)

CStoreManager::CStoreManager()
{
}

CStoreManager::~CStoreManager()
{
	Safe_Delete_VecList(m_vecStore);
}

bool CStoreManager::Init()
{
	// 무기 상점 생성
	CStore* pStore = CreateStore(STR_WEAPON);

	// 방어구 상점 생성
	pStore = CreateStore(STR_ARMOR);

	return true;
}

void CStoreManager::Run()
{
	while (true)
	{
		int iMenu = OutputMenu();

		if (iMenu == STR_NONE)
			continue;

		else if (iMenu == STR_BACK)
			break;

		m_vecStore[iMenu - 1]->Run();
	}
}

CStore* CStoreManager::CreateStore(STORE_TYPE eType)
{
	CStore* pStore = NULL;

	switch (eType)
	{
	case STR_WEAPON:
		pStore = new CStoreWeapon;
		break;
	case STR_ARMOR:
		pStore = new CStoreArmor;
		break;
	}

	if (!pStore->Init())
	{
		SAFE_DELETE(pStore);
		return NULL;
	}

	m_vecStore.push_back(pStore);

	return pStore;
}

int CStoreManager::OutputMenu()
{
	system("cls");
	cout << "1. 무기상점" << endl;
	cout << "2. 방어구상점" << endl;
	cout << "3. 뒤로가기" << endl;
	cout << "상점을 선택하세요 : ";
	int iStore = Input<int>();

	if (iStore <= STR_NONE || iStore > STR_BACK)
		return STR_NONE;

	return iStore;
}

