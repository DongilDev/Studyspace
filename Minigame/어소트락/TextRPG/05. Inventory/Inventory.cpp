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
        cout << m_vecItem.size() + 1 << ". 뒤로가기" << endl;
        cout << "장착할 아이템을 선택하세요 : ";
        int iItem = Input<int>();

        if (iItem < 1 || iItem > m_vecItem.size() + 1)
            continue;

        else if (iItem == m_vecItem.size() + 1)
            return;

        // iItem은 1번부터 선택하므로 1을 빼주면 해당 아이템의 인덱스가 된다.
        CItem* pEquip = pPlayer->Equip(m_vecItem[iItem - 1]);

        if (pEquip)
        {
            // 장착하고 있던 아이템이 있을 경우 받아와서 선택한 아이템을 장착하고 있던 아이템으로 교체해준다.
            m_vecItem[iItem - 1] = pEquip;
        }            

        else
        {
            // 장착하고 있던 아이템이 없을 경우 해당 아이템칸을 지워준다.
            // begin + 인덱스를 해주어서 장착한 아이템의 iterator 를 구해준다.
            vector<CItem*>::iterator iter = m_vecItem.begin() + (iItem - 1);

            // 지워주고 한칸씩 앞으로 가져와준다.
            m_vecItem.erase(iter);
        }
    }    
}
