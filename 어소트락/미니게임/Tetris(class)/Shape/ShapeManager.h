#pragma once

#include "value.h"

class CShapeManager
{
private:
	CShapeManager();
	~CShapeManager();

private:
	static CShapeManager* m_pInst;

public:
	static CShapeManager* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CShapeManager;
		return m_pInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

private:
	// 현재 나와있는 도형을 표현한다.
	class CShape* m_pCurShape;
	// 다음에 나올 도형을 표현한다.
	class CShape* m_pNextShape;

	// 도형을 움직일 틱을 정한다.
	int m_iSpeed;

public:
	void Update();
	void Render();
	class CShape* CreateRandomShape();
	class CShape* CreateShape(SHAPE_TYPE eType);
};

