#include "StoreWeapon.h"
#include "ItemWeapon.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Inventory.h"
#include "FileStream.h"

CStoreWeapon::CStoreWeapon()
{
}

CStoreWeapon::~CStoreWeapon()
{
}

bool CStoreWeapon::Init()
{
	// 판매 목록을 만들어준다.
	/*CItemWeapon* pItem = (CItemWeapon*)CreateItem("목검", IT_WEAPON, 1000, 500, "나무로 만든 검");
	pItem->SetWeaponInfo(5, 10, 10.f);

	pItem = (CItemWeapon*)CreateItem("철검", IT_WEAPON, 3000, 1500, "철로 만든 검");
	pItem->SetWeaponInfo(20, 30, 20.f);

	pItem = (CItemWeapon*)CreateItem("다이아검", IT_WEAPON, 25000, 12500, "다이아로 만든 검");
	pItem->SetWeaponInfo(70, 100, 35.f);*/
	
	CFileStream file("StoreWeapon.swp", "rb");

	if (file.GetOpen())
	{
		// 무기 상점 무기 수를 불러온다.
		int iCount = 0;

		file.Read(&iCount, 4);

		for (int i = 0; i < iCount; ++i)
		{
			CItem* pItem = new CItemWeapon;

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

void CStoreWeapon::Run()
{
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	while (true)
	{
		system("cls");
		OutputTag("Weapon Store");
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
			system("pause");
			continue;
		}

		// 돈이 부족할 경우를 체크한다.
		else if (pPlayer->GetGold() < m_vecItem[iInput - 1]->GetItemInfo().iPrice)
		{
			cout << "소지금이 부족합니다." << endl;
			system("pause");
			continue;
		}

		CItem* pItem = m_vecItem[iInput - 1]->Clone();

		GET_SINGLE(CInventory)->AddItem(pItem);

		pPlayer->AddGold(-pItem->GetItemInfo().iPrice);
	}	
}
