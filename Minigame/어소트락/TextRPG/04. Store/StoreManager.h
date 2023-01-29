#pragma once

#include "value.h"

enum STORE_TYPE
{
	STR_NONE,
	STR_WEAPON,
	STR_ARMOR,
	STR_BACK
};

class CStoreManager
{
private:
	vector<class CStore*> m_vecStore;

public:
	bool Init();
	void Run();

private:
	CStore* CreateStore(STORE_TYPE eType);
	int OutputMenu();

private:
	DECLARE_SINGLE(CStoreManager)
};