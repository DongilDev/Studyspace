#include "Inventory.h"
#include "Item.h"
#include "Player.h"
#include "ObjectManager.h"

DEFINITION_SINGLE(CInventory)

CInventory::CInventory()
    : m_iInvenMax(10)
{
}

CInventory::~CInventory()
{
    Safe_Delete_VecList(m_vecItem);
}

void CInventory::SetInvenMax(int iMax)
{
    m_iInvenMax = iMax;
}

int CInventory::GetInvenMax() const
{
    return m_iInvenMax;
}

bool CInventory::Init()
{
    return true;
}

void CInventory::AddItem(CItem* pItem)
{
    if (m_iInvenMax == m_vecItem.size())
        return;

    m_vecItem.push_back(pItem);
}

void CInventory::Run()
{
    CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

    while (true)
    {
        system("cls");
        cout << "================ Inventory ===============" << endl << endl;
        pPlayer->Render();
        cout << endl;

        for (size_t i = 0; i < m_vecItem.size(); ++i)
        {
            cout << i + 1 << ". ";
            m_vecItem[i]->Render();
            cout << endl;
        }
        cout << m_vecItem.size() + 1 << ". �ڷΰ���" << endl;
        cout << "������ �������� �����ϼ��� : ";
        int iItem = Input<int>();

        if (iItem < 1 || iItem > m_vecItem.size() + 1)
            continue;

        else if (iItem == m_vecItem.size() + 1)
            return;

        // iItem�� 1������ �����ϹǷ� 1�� ���ָ� �ش� �������� �ε����� �ȴ�.
        CItem* pEquip = pPlayer->Equip(m_vecItem[iItem - 1]);

        if (pEquip)
        {
            // �����ϰ� �ִ� �������� ���� ��� �޾ƿͼ� ������ �������� �����ϰ� �ִ� ���������� ��ü���ش�.
            m_vecItem[iItem - 1] = pEquip;
        }            

        else
        {
            // �����ϰ� �ִ� �������� ���� ��� �ش� ������ĭ�� �����ش�.
            // begin + �ε����� ���־ ������ �������� iterator �� �����ش�.
            vector<CItem*>::iterator iter = m_vecItem.begin() + (iItem - 1);

            // �����ְ� ��ĭ�� ������ �������ش�.
            m_vecItem.erase(iter);
        }
    }    
}
