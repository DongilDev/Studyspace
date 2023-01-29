#include "StoreArmor.h"
#include "ItemArmor.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Inventory.h"
#include "FileStream.h"

CStoreArmor::CStoreArmor()
{
}

CStoreArmor::~CStoreArmor()
{
}

bool CStoreArmor::Init()
{
	// 판매 목록을 만들어준다.
	/*CItemArmor* pItem = (CItemArmor*)CreateItem("천갑옷", IT_ARMOR, 1000, 500, "천으로 만든 옷");
	pItem->SetArmorInfo(3, 5);

	pItem = (CItemArmor*)CreateItem("가죽갑옷", IT_ARMOR, 3000, 1500, "가죽으로 만든 질긴 갑옷");
	pItem->SetArmorInfo(10, 20);

	pItem = (CItemArmor*)CreateItem("가시갑옷", IT_ARMOR, 25000, 12500, "가시로 만든 갑옷");
	pItem->SetArmorInfo(30, 50); */

	CFileStream file("StoreArmor.swp", "rb");

	if (file.GetOpen())
	{
		// 방어구 상점 방어구 수를 불러온다.
		int iCount = 0;

		file.Read(&iCount, 4);

		for (int i = 0; i < iCount; ++i)
		{
			CItem* pItem = new CItemArmor;

			if (!pItem->Init())
			{
				SAFE_DELETE(pItem);
				return false;
			}

			pItem->Load(&file);

			m_vecItem.push_back(pItem);
		}

		file.Close();
	}

	return true;
}

void CStoreArmor::Run()
{
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	while (true)
	{
		system("cls");
		OutputTag("Armor Store");
		OutputItemList();
		cout << m_vecItem.size() + 1 << ". 뒤로가기" << endl;
		cout << "보유금액 : " << pPlayer->GetGold() << " Gold" << endl;
		int iInput = Input<int>();

		if (iInput < 1 || iInput > m_vecItem.size() + 1)
			continue;

		else if (iInput == m_vecItem.size() + 1)
			return;

		// 아이템을 구매한다. 가방이 꽉 찼을 경우 구매할 수 없다.
		if (GET_SINGLE(CInventory)->Full())
		{
			cout << "인벤토리에 빈 공간이 없습니다." << endl;
			continue;
		}

		// 돈이 부족할 경우를 체크한다.
		else if (pPlayer->GetGold() < m_vecItem[iInput - 1]->GetItemInfo().iPrice)
		{
			cout << "소지금이 부족합니다." << endl;
			continue;
		}

		CItem* pItem = m_vecItem[iInput - 1]->Clone();

		GET_SINGLE(CInventory)->AddItem(pItem);

		pPlayer->AddGold(-pItem->GetItemInfo().iPrice);
	}
}