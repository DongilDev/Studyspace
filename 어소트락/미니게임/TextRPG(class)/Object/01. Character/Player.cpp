#include "Player.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"

CPlayer::CPlayer()
    : m_iGold(10000)
{
    m_eType = OT_PLAYER;
    
    // 포인터 변수 배열 2개짜리를 0으로 초기화한다. 
    // EQ_END 가 2이므로 포인터변수 크기 4 * 2 가 되어 8바이트를 0으로 초기화한다.
    // 즉 포인터 변수 2개를 NULL 포인터로 초기화 하는 것이다.
    memset(m_pEquip, 0, sizeof(CItem*) * EQ_END);
}

CPlayer::CPlayer(const CPlayer& player) 
    : CCharacter(player)
{
    m_eJob = player.m_eJob;
    m_strJobName = player.m_strJobName;
    m_iGold = player.m_iGold;
    memset(m_pEquip, 0, sizeof(CItem*) * EQ_END);
}

CPlayer::~CPlayer()
{
    for (int i = 0; i < EQ_END; ++i)
    {
        SAFE_DELETE(m_pEquip[i]);
    }
}

void CPlayer::AddGold(int iGold)
{
    m_iGold += iGold;
}

void CPlayer::DropGold()
{
    m_iGold *= 0.9f;
}

JOB CPlayer::GetJob() const
{
    return m_eJob;
}

int CPlayer::GetGold() const
{
    return m_iGold;
}

CItem* CPlayer::GetEquip(EQUIP eq) const
{
    return m_pEquip[eq];
}

int CPlayer::GetDamage()
{
    int iMin = m_tInfo.iAttackMin;
    int iMax = m_tInfo.iAttackMax;
    if (m_pEquip[EQ_WEAPON])
    {
        iMin += ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMin();
        iMax += ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMax();

        if (rand() % 9901 / 100.f <= ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetCritical())
        {
            cout << "Critical" << endl;
            iMin *= 2;
            iMax *= 2;
        }
    }

    return rand() % (iMax - iMin + 1) + iMin;
}

int CPlayer::GetArmor()
{
    int iMin = m_tInfo.iArmorMin;
    int iMax = m_tInfo.iArmorMax;
    if (m_pEquip[EQ_ARMOR])
    {
        iMin += ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMin();
        iMax += ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMax();
    }

    return rand() % (iMax - iMin + 1) + iMin;
}

CItem* CPlayer::Equip(CItem* pItem)
{
    // 장착하고자 하는 아이템의 타입에 따라 장착 부위가 달라져야 한다.
    EQUIP eq;
    
    switch (pItem->GetItemInfo().eType)
    {
    case IT_WEAPON:
        eq = EQ_WEAPON;
        break;
    case IT_ARMOR:
        eq = EQ_ARMOR;
        break;
    }

    // 착용하고 있는 아이템이 있을 경우 착용하고 있던 아이템을 반환해 주어야 한다.
    if (m_pEquip[eq])
    {
        CItem* pEquip = m_pEquip[eq];
        m_pEquip[eq] = pItem;

        // 착용하고 있던 아이템을 반환한다.
        return pEquip;
    }

    m_pEquip[eq] = pItem;

    return NULL;

}

bool CPlayer::Init()
{
    system("cls");
    cin.ignore(1024, '\n');
    cout << "이름을 입력하세요 : ";
    char strName[32] = {};
    cin.getline(strName, 31);  

    SetName(strName);

    int iJob;

    while (true)
    {
        system("cls");
        cout << "1. 기사" << endl;  
        cout << "2. 궁수" << endl;
        cout << "3. 마법사" << endl;
        cout << "직업을 선택하세요 : ";
        iJob = Input<int>();

        if (iJob < JOB_KNIGHT || iJob >= JOB_END)
            continue;

        break;
    }

    m_eJob = (JOB)iJob;

    switch (m_eJob)
    {
    case JOB_KNIGHT:
        m_strJobName = "기사";
        SetCharacterInfo(10, 15, 15, 20, 500, 100, 1, 0);
        break;
    case JOB_ARCHER:
        m_strJobName = "궁수";
        SetCharacterInfo(15, 20, 10, 15, 400, 200, 1, 0);
        break;
    case JOB_WIZARD:
        m_strJobName = "마법사";
        SetCharacterInfo(20, 25, 5, 10, 300, 300, 1, 0);
        break;
    }

    return true;
}

void CPlayer::Render()
{
    cout << "이름 : " << m_strName << "\t직업 : " << m_strJobName << endl;
    cout << "레벨 : " << m_tInfo.iLevel << "\t경험치 : " << m_tInfo.iExp << endl;
    cout << "공격력 : ";
    
    if (m_pEquip[EQ_WEAPON])
    {
        cout << m_tInfo.iAttackMin << " + " << ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMin() << " ~ " <<
            m_tInfo.iAttackMax << " + " << ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMax();
    }

    else
    {
        cout << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax;
    }
    
    cout << "\t방어력 : ";

    if (m_pEquip[EQ_ARMOR])
    {
        cout << m_tInfo.iArmorMin << " + " << ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMin() << " ~ " <<
            m_tInfo.iArmorMax << " + " << ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMax() << endl;
    }

    else
    {
        cout << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax << endl;
    }

    cout << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax << endl;
    cout << "체력 : " << m_tInfo.iHP << " / " << m_tInfo.iHPMax << "\t마나 : " <<
        m_tInfo.iMP << " / " << m_tInfo.iMPMax << endl;
    cout << "보유금액 : " << m_iGold << " Gold" << endl;

    cout << "장착 무기 : ";
    if (m_pEquip[EQ_WEAPON])
       cout << m_pEquip[EQ_WEAPON]->GetName();

    else
        cout << "없음";

    cout << "\t징착 방어구 : ";
    if (m_pEquip[EQ_ARMOR])
       cout << m_pEquip[EQ_ARMOR]->GetName() << endl;

    else
        cout << "없음";

}

CPlayer* CPlayer::Clone()
{
    // this 는 자기자신의 포인터이다.
    // 자기자신의 포인터를 역참조하면 자기자신 객체 자체가 된다.
    // 그래서 새로 할당하는 플레이어 객체에 자기자신을 넘겨주어서
    // 자기자신을 복사하는 생성자를 호출하여 생성하도록 만들어준다.
    // 이렇게 해주면 이 객체를 복사한 새로운 객체를 동적할당 하여 그 메모리 주소를 반환해주게 한다.
    return new CPlayer(*this);
}
