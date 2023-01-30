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
	// �Ǹ� ����� ������ش�.
	/*CItemWeapon* pItem = (CItemWeapon*)CreateItem("���", IT_WEAPON, 1000, 500, "������ ���� ��");
	pItem->SetWeaponInfo(5, 10, 10.f);

	pItem = (CItemWeapon*)CreateItem("ö��", IT_WEAPON, 3000, 1500, "ö�� ���� ��");
	pItem->SetWeaponInfo(20, 30, 20.f);

	pItem = (CItemWeapon*)CreateItem("���̾ư�", IT_WEAPON, 25000, 12500, "���̾Ʒ� ���� ��");
	pItem->SetWeaponInfo(70, 100, 35.f);*/
	
	CFileStream file("StoreWeapon.swp", "rb");

	if (file.GetOpen())
	{
		// ���� ���� ���� ���� �ҷ��´�.
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
		cout << m_vecItem.size() + 1 << ". �ڷΰ���" << endl;
		cout << "�����ݾ� : " << pPlayer->GetGold() << " Gold" << endl;
		int iInput = Input<int>();

		if (iInput < 1 || iInput > m_vecItem.size() + 1)
			continue;

		else if (iInput == m_vecItem.size() + 1)
			return;

		// �������� �����Ѵ�. ������ �� á�� ��� ������ �� ����.
		if (GET_SINGLE(CInventory)->Full())
		{
			cout << "�κ��丮�� �� ������ �����ϴ�." << endl;
			system("pause");
			continue;
		}

		// ���� ������ ��츦 üũ�Ѵ�.
		else if (pPlayer->GetGold() < m_vecItem[iInput - 1]->GetItemInfo().iPrice)
		{
			cout << "�������� �����մϴ�." << endl;
			system("pause");
			continue;
		}

		CItem* pItem = m_vecItem[iInput - 1]->Clone();

		GET_SINGLE(CInventory)->AddItem(pItem);

		pPlayer->AddGold(-pItem->GetItemInfo().iPrice);
	}	
}
