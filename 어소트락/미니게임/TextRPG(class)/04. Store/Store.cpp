#include "Store.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"

CStore::CStore()
{
}

CStore::~CStore()
{
	Safe_Delete_VecList(m_vecItem);
}

CItem* CStore::CreateItem(char* pName, ITEM_TYPE eType, int iPrice,
	int iSell, char* pDesc)
{
	CItem* pItem = NULL;
	
	switch (eType)
	{
	case IT_WEAPON:
		pItem = new CItemWeapon;
		break;
	case IT_ARMOR:
		pItem = new CItemArmor;
		break;
	}

	if (!pItem->Init())
	{
		SAFE_DELETE(pItem);
		return NULL;
	}

	pItem->SetName(pName);
	pItem->SetItemInfo(eType, iPrice, iSell, pDesc);

	m_vecItem.push_back(pItem);

	return pItem;
}

void CStore::OutputItemList()
{
	/*for (size_t i = 0; i < m_vecItem.size(); ++i)
	{
		cout << i + 1 << ". ";
		m_vecItem[i]->Render();
		cout << endl;
	}*/

	vector<CItem*>::iterator iter;
	int iCount = 1;
	for (iter = m_vecItem.begin(); iter != m_vecItem.end(); ++iter, ++iCount)
	{
		cout << iCount << ". ";
		(*iter)->Render();
		cout << endl;
	}
}

void CStore::OutputTag(char* pStoreName)
{
	cout << "=====================" << pStoreName << "=====================" << endl;
}
