#include "ShapeRGun.h"

CShapeRGun::CShapeRGun()
{
}

CShapeRGun::~CShapeRGun()
{
}

bool CShapeRGun::Init()
{
    if (!CShape::Init())
		return false;

	m_cShape[2][0] = '0';
	m_cShape[2][1] = '0';
	m_cShape[2][2] = '0';
	m_cShape[3][0] = '0';

	m_iWidthCount = 3;
	m_tPos.x = 4;
	m_tPos.y = 0;

	m_iDir = RD_RIGHT;

	return true;
}

void CShapeRGun::Rotation()
{
	++m_iDir;

	m_iDir %= RD_END;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m_cShape[i][j] = '1';
		}
	}

	switch (m_iDir)
	{
	case RD_UP:
		m_cShape[1][0] = '0';
		m_cShape[2][0] = '0';
		m_cShape[3][0] = '0';
		m_cShape[3][1] = '0';
		m_iWidthCount = 2;
		break;
	case RD_RIGHT:
		m_cShape[2][0] = '0';
		m_cShape[2][1] = '0';
		m_cShape[2][2] = '0';
		m_cShape[3][0] = '0';
		m_iWidthCount = 3;
		break;
	case RD_DOWN:
		m_cShape[1][0] = '0';
		m_cShape[1][1] = '0';
		m_cShape[2][1] = '0';
		m_cShape[3][1] = '0';
		m_iWidthCount = 2;
		break;
	case RD_LEFT:
		m_cShape[3][0] = '0';
		m_cShape[3][1] = '0';
		m_cShape[3][2] = '0';
		m_cShape[2][2] = '0';
		m_iWidthCount = 3;
		break;
	}
}
