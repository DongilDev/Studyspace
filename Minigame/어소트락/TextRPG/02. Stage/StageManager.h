#pragma once

#include "value.h"

class CStageManager
{
private:
	vector<class CStage*> m_vecStage;
	
	enum MENU
	{
		MENU_NONE,
		MENU_EASY,
		MENU_NORMAL,
		MENU_HARD,
		MENU_BACK
	};

public:
	bool Init();
	void Run();

private:
	bool CreateStage(STAGE_TYPE eType);
	int OutputMenu();

	DECLARE_SINGLE(CStageManager)
};

