#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"

CMissile::CMissile()
	: m_fDir(1.f)
{

}

CMissile::~CMissile()
{

}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.y += 600.f * fDT * m_fDir;

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	Vec2 vPOS = GetPos();
	Vec2 vScale = GetScale();
	Ellipse(_dc, (int)(vPOS.x - vScale.x / 2.f), (int)(vPOS.y - vScale.y / 2.f)
		, (int)(vPOS.x + vScale.x / 2.f), (int)(vPOS.y + vScale.y / 2.f));
}
