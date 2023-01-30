#include "ItemWeapon.h"
#include "FileStream.h"

CItemWeapon::CItemWeapon()
{
}

CItemWeapon::CItemWeapon(const CItemWeapon& item)
	: CItem(item)
{
	m_iAttackMin = item.m_iAttackMin;
	m_iAttackMax = item.m_iAttackMax;
	m_fCritical = item.m_fCritical;
}

CItemWeapon::~CItemWeapon()
{
}

int CItemWeapon::GetAttackMin() const
{
	return m_iAttackMin;
}

int CItemWeapon::GetAttackMax() const
{
	return m_iAttackMax;
}

float CItemWeapon::GetCritical() const
{
	return m_fCritical;
}

void CItemWeapon::SetWeaponInfo(int iMin, int iMax, float fCritical)
{
	m_iAttackMin = iMin;
	m_iAttackMax = iMax;
	m_fCritical = fCritical;
}

bool CItemWeapon::Init()
{
	// �Ǹ� ����� ������ش�.

	return true;
}

void CItemWeapon::Render()
{
	cout << "�̸� : " << m_strName << "\t���� : " << m_tInfo.strTypeName << endl;
	cout << "���ݷ� : " << m_iAttackMin << " ~ " << m_iAttackMax << "\tġ��Ÿ�� : " <<
		m_fCritical << endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "����: " << m_tInfo.strDesc << endl;
}

CItemWeapon* CItemWeapon::Clone()
{
	return new CItemWeapon(*this);
}

void CItemWeapon::Save(CFileStream* pFile)
{
	CItem::Save(pFile);

	pFile->Write(&m_iAttackMin, 4);
	pFile->Write(&m_iAttackMax, 4);
	pFile->Write(&m_fCritical, 4);
}

void CItemWeapon::Load(CFileStream* pFile)
{
	CItem::Load(pFile);

	pFile->Read(&m_iAttackMin, 4);
	pFile->Read(&m_iAttackMax, 4);
	pFile->Read(&m_fCritical, 4);
}
