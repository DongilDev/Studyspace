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
    cout << "�̸� : " << m_strName;

    switch (m_eStageType)
    {
    case ST_EASY:
        cout << "\t���̵� : EASY" << endl;
        break;
    case ST_NORMAL:
        cout << "\t���̵� : NORMAL" << endl;
        break;
    case ST_HARD:
        cout << "\t���̵� : HARD" << endl;
        break;
    }

    cout << "���� : " << m_tInfo.iLevel << "\tȹ�����ġ : " << m_tInfo.iExp << endl;
    cout << "���ݷ� : " << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax <<
        "\t���� : " << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax << endl;
    cout << "ü�� : " << m_tInfo.iHP << " / " << m_tInfo.iHPMax << "\t���� : " <<
        m_tInfo.iMP << " / " << m_tInfo.iMPMax << endl;
    cout << "ȹ��ݾ� : " << m_iGoldMin << " ~ " << m_iGoldMax <<" Gold" << endl;
}

CMonster* CMonster::Clone()
{
    // this �� �ڱ��ڽ��� �������̴�.
    // �ڱ��ڽ��� �����͸� �������ϸ� �ڱ��ڽ� ��ü ��ü�� �ȴ�.
    // �׷��� ���� �Ҵ��ϴ� �÷��̾� ��ü�� �ڱ��ڽ��� �Ѱ��־
    // �ڱ��ڽ��� �����ϴ� �����ڸ� ȣ���Ͽ� �����ϵ��� ������ش�.
    // �̷��� ���ָ� �� ��ü�� ������ ���ο� ��ü�� �����Ҵ� �Ͽ� �� �޸� �ּҸ� ��ȯ���ְ� �Ѵ�.
    return new CMonster(*this);
}

void CMonster::Save(CFileStream* pFile)
{
    CCharacter::Save(pFile);

    // ���� ����� �߰��Ѵ�.
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
