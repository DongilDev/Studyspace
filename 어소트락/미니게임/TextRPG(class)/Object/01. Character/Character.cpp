#include "Character.h"
#include "FileStream.h"

CCharacter::CCharacter()
{
}

// Obj의 복사생성자를 먼저 호출하여 Obj의 값을 복사하고
// character의 값을 복사하도록 한다.
CCharacter::CCharacter(const CCharacter& character)
	: CObj(character)
{
	m_tInfo = character.m_tInfo;
}

CCharacter::~CCharacter()
{
}

void CCharacter::SetCharacterInfo(int iAtMin, int iAtMax, int iArMin, int iArMax, int iHP, int iMP, int iLevel, int iExp)
{
	m_tInfo.iAttackMin = iAtMin;
	m_tInfo.iAttackMax = iAtMax;
	m_tInfo.iArmorMin = iArMin;
	m_tInfo.iArmorMax = iArMax;
	m_tInfo.iHP = iHP;
	m_tInfo.iHPMax = iHP;
	m_tInfo.iMP = iMP;
	m_tInfo.iMPMax = iMP;
	m_tInfo.iLevel = iLevel;
	m_tInfo.iExp = iExp;
}

int CCharacter::GetDamage()
{
	return rand() % (m_tInfo.iAttackMax - m_tInfo.iAttackMin + 1) + m_tInfo.iAttackMin;	
}

int CCharacter::GetArmor()
{
	return rand() % (m_tInfo.iArmorMax - m_tInfo.iArmorMin + 1) + m_tInfo.iArmorMin;
}

bool CCharacter::Damage(int iDamage)
{
	m_tInfo.iHP -= iDamage;

	// true면 이 캐릭터가 죽은것이다.
	return m_tInfo.iHP <= 0;
}

bool CCharacter::AddExp(int iExp)
{
	m_tInfo.iExp += iExp;

	// false 리턴 시에는 레벨업이 아니다.
	return false;
}

bool CCharacter::CheckLevelUp()
{
	if (g_iLvUpTable[m_tInfo.iLevel - 1] <= m_tInfo.iExp)
		return true;

	return false;
}

void CCharacter::DropExp()
{
	m_tInfo.iExp *= 0.9f;
}

void CCharacter::FullHPMP()
{
	m_tInfo.iHP = m_tInfo.iHPMax;
	m_tInfo.iMP = m_tInfo.iMPMax;
}

void CCharacter::LevelUp()
{
	m_tInfo.iExp -= g_iLvUpTable[m_tInfo.iLevel - 1];

	++m_tInfo.iLevel;
}

void CCharacter::AddLevelUpStatus(const LEVELUPINFO& tInfo)
{
	m_tInfo.iAttackMin += tInfo.iAttackMin;
	m_tInfo.iAttackMax += tInfo.iAttackMax;
	m_tInfo.iArmorMin += tInfo.iArmorMin;
	m_tInfo.iArmorMax += tInfo.iArmorMax;
	m_tInfo.iHPMax += tInfo.iHP;
	m_tInfo.iHP = m_tInfo.iHPMax;
	m_tInfo.iMPMax += tInfo.iMP;
	m_tInfo.iMP = m_tInfo.iMPMax;
}

bool CCharacter::Init()
{
	return true;
}

void CCharacter::Render()
{
}

void CCharacter::Save(CFileStream* pFile)
{
	CObj::Save(pFile);

	pFile->Write(&m_tInfo, sizeof(m_tInfo));
}

void CCharacter::Load(CFileStream* pFile)
{
	CObj::Load(pFile);

	pFile->Read(&m_tInfo, sizeof(m_tInfo));
}
