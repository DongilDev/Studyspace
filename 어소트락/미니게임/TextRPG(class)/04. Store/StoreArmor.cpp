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
	// �Ǹ� ����� ������ش�.
	/*CItemArmor* pItem = (CItemArmor*)CreateItem("õ����", IT_ARMOR, 1000, 500, "õ���� ���� ��");
	pItem->SetArmorInfo(3, 5);

	pItem = (CItemArmor*)CreateItem("���װ���", IT_ARMOR, 3000, 1500, "�������� ���� ���� ����");
	pItem->SetArmorInfo(10, 20);

	pItem = (CItemArmor*)CreateItem("���ð���", IT_ARMOR, 25000, 12500, "���÷� ���� ����");
	pItem->SetArmorInfo(30, 50); */

	CFileStream file("StoreArmor.swp", "rb");

	if (file.GetOpen())
	{
		// �� ���� �� ���� �ҷ��´�.
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
			continue;
		}

		// ���� ������ ��츦 üũ�Ѵ�.
		else if (pPlayer->GetGold() < m_vecItem[iInput - 1]->GetItemInfo().iPrice)
		{
			cout << "�������� �����մϴ�." << endl;
			continue;
		}

		CItem* pItem = m_vecItem[iInput - 1]->Clone();

		GET_SINGLE(CInventory)->AddItem(pItem);

		pPlayer->AddGold(-pItem->GetItemInfo().iPrice);
	}
}