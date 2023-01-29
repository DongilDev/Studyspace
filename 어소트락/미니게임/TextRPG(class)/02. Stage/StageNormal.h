#pragma once

#include "Stage.h"

class CStageNormal : public CStage
{
public:
	CStageNormal();
	~CStageNormal();

public:
	virtual bool Init();
	virtual void Run();
};