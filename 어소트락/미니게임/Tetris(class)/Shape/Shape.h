#pragma once

#include "value.h"

class CShape
{
public:
	CShape();
	virtual ~CShape();

protected:
	char m_cShape[4][4];
	POSITION m_tPos;
	POSITION m_tPivot;
	int m_iWidthCount;
	int  m_iDir;

public:
	char GetBlock(int x, int y) const
	{
		return m_cShape[y][x];
	}

	void SetPosition(int x, int y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& tPos)
	{
		m_tPos = tPos;
	}

	POSITION GetPosition() const
	{
		return m_tPos;
	}

	POSITION GetPivot() const
	{
		return m_tPivot;
	}

public:
	virtual bool Init();
	virtual void Rotation();

public:
	void Render();
	void RenderNext();
	bool MoveDown();
	void MoveLeft();
	void MoveRight();
};

