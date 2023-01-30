#include "Obj.h"
#include "FileStream.h"

CObj::CObj()
{
}

CObj::CObj(const CObj& obj)
{
	m_strName = obj.m_strName;
	m_eType = obj.m_eType;
}

CObj::~CObj()
{
}

OBJECT_TYPE CObj::GetObjectType() const
{

	return  m_eType;
}

void CObj::SetName(char* pName)
{
	m_strName = pName;
}
string CObj::GetName() const
{
	return m_strName;
}

bool CObj::Init()
{
	return true;
}

void CObj::Render()
{
}

void CObj::Save(CFileStream* pFile)
{
	pFile->Write(&m_eType, sizeof(OBJECT_TYPE));

	int iLength = m_strName.length();

	// 이름 길이를 저장한다.
	pFile->Write(&iLength, 4);

	// 이름을 저장한다.
	pFile->Write((void*)m_strName.c_str(), iLength);
}

void CObj::Load(CFileStream* pFile)
{
	pFile->Read(&m_eType, sizeof(OBJECT_TYPE));

	// 이름 길이를 읽어온다.
	int iLength = 0;
	pFile->Read(&iLength, 4);

	char* pName = new char[iLength + 1];
	memset(pName, 0, iLength);

	pFile->Read(pName, iLength);
	pName[iLength] = 0;

	m_strName = pName;

	SAFE_DELETE_ARRAY(pName);
}
