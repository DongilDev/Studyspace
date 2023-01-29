#pragma once

#include "value.h"

class CInventory
{
private:
	vector<class CItem*> m_vecItem;
	int m_iInvenMax;

public:
	void SetInvenMax(int iMax);
	int GetInvenMax() const;

	bool Full() const
	{
		return m_iInvenMax == m_vecItem.size();
	}

public:
	bool Init();
	void AddItem(class CItem* pItem);
	void Run();

	DECLARE_SINGLE(CInventory)
};

