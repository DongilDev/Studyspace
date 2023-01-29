#pragma once
#include "Item.h"
class CItemArmor : public CItem
{
protected:
	CItemArmor();
	CItemArmor(const CItemArmor& item);
	~CItemArmor();

private:
	friend class CStore;
	friend class CStoreArmor;
	friend class CEditorItem;

private:
	int m_iArmorMin;
	int m_iArmorMax;

public:
	int GetArmorMin() const;
	int GetArmorMax() const;

public:
	void SetArmorInfo(int iMin, int iMax);

public:
	virtual bool Init();
	virtual void Render();
	virtual CItemArmor* Clone();
	virtual void Save(class CFileStream* pFile);
	virtual void Load(class CFileStream* pFile);
};

