#pragma once

#include "Stage.h"

class CStageHard : public CStage
{
public:
	CStageHard();
	~CStageHard();

public:
	virtual bool Init();
	virtual void Run();
};

