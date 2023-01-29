#pragma once

#include "value.h"

class CEditorMonster
{
private:
	vector<class CMonster*> m_vecMonster;

public:
	bool Init();
	void Run();

private:
	int OutputMenu();
	void Insert();
	void OutputMonsterList();
	void Save();
	void Load();

	DECLARE_SINGLE(CEditorMonster)
};

