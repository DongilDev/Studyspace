#include "Monster.h"
#include "FileStream.h"

CMonster::CMonster()
{
    m_eType = OT_MONSTER; 
}

CMonster::CMonster(const CMonster& monster)
    : CCharacter(monster)
{
    m_iGoldMin = monster.m_iGoldMin;
    m_iGoldMax = monster.m_iGoldMax;
    m_eStageType = monster.m_eStageType;
}

CMonster::~CMonster()
{
}

void CMonster::SetGold(int iMin, int iMax)
{
    m_iGoldMin = iMin;
    m_iGoldMax = iMax;
}

void CMonster::SetStageType(STAGE_TYPE eType)
{
    m_eStageType = eType;
}

int CMonster::GetDropGold() const
{
    return rand() % (m_iGoldMax - m_iGoldMin + 1) + m_iGoldMin;
}

STAGE_TYPE CMonster::GetStageType() const
{
    return m_eStageType;
}

bool CMonster::Init()
{
    return true;
}

void CMonster::Render()
{
    cout << "이름 : " << m_strName;

    switch (m_eStageType)
    {
    case ST_EASY:
        cout << "\t난이도 : EASY" << endl;
        break;
    case ST_NORMAL:
        cout << "\t난이도 : NORMAL" << endl;
        break;
    case ST_HARD:
        cout << "\t난이도 : HARD" << endl;
        break;
    }

    cout << "레벨 : " << m_tInfo.iLevel << "\t획득경험치 : " << m_tInfo.iExp << endl;
    cout << "공격력 : " << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax <<
        "\t방어력 : " << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax << endl;
    cout << "체력 : " << m_tInfo.iHP << " / " << m_tInfo.iHPMax << "\t마나 : " <<
        m_tInfo.iMP << " / " << m_tInfo.iMPMax << endl;
    cout << "획득금액 : " << m_iGoldMin << " ~ " << m_iGoldMax <<" Gold" << endl;
}

CMonster* CMonster::Clone()
{
    // this 는 자기자신의 포인터이다.
    // 자기자신의 포인터를 역참조하면 자기자신 객체 자체가 된다.
    // 그래서 새로 할당하는 플레이어 객체에 자기자신을 넘겨주어서
    // 자기자신을 복사하는 생성자를 호출하여 생성하도록 만들어준다.
    // 이렇게 해주면 이 객체를 복사한 새로운 객체를 동적할당 하여 그 메모리 주소를 반환해주게 한다.
    return new CMonster(*this);
}

void CMonster::Save(CFileStream* pFile)
{
    CCharacter::Save(pFile);

    // 나의 기능을 추가한다.
    pFile->Write(&m_iGoldMin, 4);
    pFile->Write(&m_iGoldMax, 4);
    pFile->Write(&m_eStageType, 4);
}

void CMonster::Load(CFileStream* pFile)
{
    CCharacter::Load(pFile);

    pFile->Read(&m_iGoldMin, 4);
    pFile->Read(&m_iGoldMax, 4);
    pFile->Read(&m_eStageType, 4);
}
