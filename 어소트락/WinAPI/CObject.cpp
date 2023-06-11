#include "pch.h"
#include "CObject.h"

#include "CKeyMgr.h"

#include "CTimeMgr.h"

CObject::CObject()
	: m_vPos{}
	, m_vScale{}
	, m_bAlive(true)
{
}

CObject::~CObject()
{ 
}

void CObject::render(HDC _dc)
{
	Rectangle(_dc, (int)(m_vPos.x - m_vScale.x / 2.f) , (int)(m_vPos.y - m_vScale.y / 2.f)
				, (int)(m_vPos.x + m_vScale.x / 2.f), (int)(m_vPos.y + m_vScale.y / 2.f));
}