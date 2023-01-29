#pragma once

#include "Stage.h"

class CStageEasy : public CStage
{
public:
	CStageEasy();
	~CStageEasy();

public:
	virtual bool Init();
	virtual void Run();
};