#include "EditorItem.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "FileStream.h"

DEFINITION_SINGLE(CEditorItem)

enum EDIT_ITEM_MENU
{
    EIM_NONE,   
    EIM_INSERT,
    EIM_MODIFY,
    EIM_DELETE,
    EIM_OUTPUT,
    EIM_SAVE,
    EIM_LOAD,
    EIM_BACK
};

CEditorItem::CEditorItem()
{
}

CEditorItem::~CEditorItem()
{
	Safe_Delete_VecList(m_vecWeapon);
	Safe_Delete_VecList(m_vecArmor);
}

bool CEditorItem::Init()
{
	return true;
}

void CEditorItem::Run()
{
    while (true)
    {
        switch (OutputMenu())
        {
        case EIM_INSERT:
            Insert();
            break;
        case EIM_MODIFY:
            break;
        case EIM_DELETE:
            break;
        case EIM_OUTPUT:
            OutputStoreList();
            break;
        case EIM_SAVE:
            Save();
            break;
        case EIM_LOAD:
            Load();
            break;
        case EIM_BACK:
            return;
        }
    }
}

int CEditorItem::OutputMenu()
{
    system("cls");
    cout << "1. ������ �߰�" << endl;
    cout << "2. ������ ����" << endl;
    cout << "3. ������ ����" << endl;
    cout << "4. ������ ���" << endl;
    cout << "5. ����" << endl;
    cout << "6. �ҷ�����" << endl;
    cout << "7. �ڷΰ���" << endl;
    cout << "�޴��� �����ϼ��� : ";
    int iMenu = Input<int>();

    if (iMenu <= EIM_NONE || iMenu > EIM_BACK)
        return EIM_NONE;

    return iMenu;
}

void CEditorItem::Insert()
{
    CItem* pItem = NULL;

    system("cls");
    cout << "============== ������ �߰� ===============" << endl;

    int iItemType = -1;
    while (iItemType < IT_WEAPON || iItemType > IT_MAX)
    {
        cout << "1. ����" << endl;
        cout << "2. ��" << endl;
        cout << "������ ������ �����ϼ��� : ";
        iItemType = Input<int>();
    }    

    switch (iItemType-1)
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
        return;
    }

    cin.ignore(1024, '\n');
    cout << "�̸� : ";
    char strName[256] = {};
    cin.getline(strName, 255);

    pItem->SetName(strName);

    int iPrice, iSell;
    cout << "Price : ";
    cin >> iPrice;

    cout << "Sell : ";
    cin >> iSell;

    switch (iItemType - 1)
    {
    case IT_WEAPON:
    {
        int iAttMin, iAttMax;
        cout << "�ּ� ���ݷ� : ";
        iAttMin = Input<int>();

        cout << "�ִ� ���ݷ� : ";
        iAttMax = Input<int>();

        float fCritical;
        cout << "ġ��Ÿ Ȯ�� : ";
        fCritical = Input<float>();
      
        ((CItemWeapon*)pItem)->SetWeaponInfo(iAttMin, iAttMax, fCritical);
    }        
        break;
    case IT_ARMOR:
    {
        int iArMin, iArMax;
        cout << "�ּ� ���� : ";
        iArMin = Input<int>();

        cout << "�ִ� ���� : ";
        iArMax = Input<int>();

        ((CItemArmor*)pItem)->SetArmorInfo(iArMin, iArMax);   
    }
        break;
    }
        
    char strDesc[256] = {};

    cin.ignore(1024, '\n');
    cout << "������ ���� : ";
    cin.getline(strDesc, 255);

    pItem->SetItemInfo((ITEM_TYPE)(iItemType - 1), iPrice, iSell, strDesc);           

    switch (iItemType - 1)
    {
    case IT_WEAPON:
        m_vecWeapon.push_back(pItem);
        break;
    case IT_ARMOR:
        m_vecArmor.push_back(pItem);
        break;
    }
}

void CEditorItem::OutputStoreList()
{
    system("cls");
    cout << "================= ���� ���� =================" << endl;
    for (int i = 0; i < m_vecWeapon.size(); ++i)
    {
        cout << i + 1 << ". ";
        m_vecWeapon[i]->Render();
        cout << endl;
    }

    cout << "================= �� ���� =================" << endl;
    for (int i = 0; i < m_vecArmor.size(); ++i)
    {
        cout << i + 1 << ". ";
        m_vecArmor[i]->Render();
        cout << endl;
    }

    system("pause");
}

void CEditorItem::Save()
{
    CFileStream file("StoreWeapon.swp", "wb");

    if (file.GetOpen())
    {
        // ���� ���� ���� ���� �����Ѵ�.
        int iCount = m_vecWeapon.size();

        file.Write(&iCount, 4);

        for (int i = 0; i < iCount; ++i)
        {
            m_vecWeapon[i]->Save(&file);
        }

        file.Close();
    }    


    // �� ���� ����

    if (file.Open("StoreArmor.sar", "wb"))
    {
        // �� ���� �� ���� �����Ѵ�.
        int iCount = m_vecArmor.size();

        file.Write(&iCount, 4);

        for (int i = 0; i < iCount; ++i)
        {
            m_vecArmor[i]->Save(&file);
        }

        file.Close();
    }

    cout << "���� ��� ���� �Ϸ�" << endl;
    system("pause");
}

void CEditorItem::Load()
{
    Safe_Delete_VecList(m_vecWeapon);
    Safe_Delete_VecList(m_vecArmor);

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
                return;
            }

            pItem->Load(&file);

            m_vecWeapon.push_back(pItem);
        }

        file.Close();
    }


    // �� ���� ����

    if (file.Open("StoreArmor.sar", "rb"))
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
                return;
            }

            pItem->Load(&file);

            m_vecArmor.push_back(pItem);
        }

        file.Close();
    }

    cout << "���� ��� ���� �Ϸ�" << endl;
    system("pause");
}
