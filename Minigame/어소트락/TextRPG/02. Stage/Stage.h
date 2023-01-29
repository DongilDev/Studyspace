#pragma once

#include "value.h"

class CStage
{
public:
	CStage();
	virtual ~CStage();

protected:
	enum MENU
	{
		MENU_NONE,
		MENU_ATTACK,
		MENU_BACK
	};

	enum BATTLE_FLAG
	{
		BF_NONE,
		BF_PLAYER_DIE,
		BF_MONSTER_DIE
	};

public:
	virtual bool Init() = 0;
	virtual void Run() = 0;

protected:
	void OutputStageName(char* pName);
	int OutputMenu();
	BATTLE_FLAG BattleAttack(class CPlayer* pPlayer, class CMonster* pMonster);
};

