#pragma once

#include "Character.h"

class CMonster : public CCharacter
{
private:
	CMonster();
	CMonster(const CMonster& monster);

public:
	~CMonster();

private:
	friend class CObjectManager;
	friend class CEditorMonster;

private:
	int m_iGoldMin;
	int m_iGoldMax;
	STAGE_TYPE m_eStageType;

public:
	void SetGold(int iMin, int iMax);
	void SetStageType(STAGE_TYPE eType);
	
public:
	int GetDropGold() const;
	STAGE_TYPE GetStageType() const;

public:
	virtual bool Init();
	virtual void Render();
	virtual CMonster* Clone();
	virtual void Save(class CFileStream* pFile);
	virtual void Load(class CFileStream* pFile);
};

