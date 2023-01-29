#pragma once

#include "Store.h"

class CStoreArmor : public CStore
{
private:
	CStoreArmor();
	~CStoreArmor();

private:
	friend class CStoreManager;

public:
	virtual bool Init();
	virtual void Run();

};

