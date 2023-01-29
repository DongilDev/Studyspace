#pragma once

#include "value.h"

class CEditorCore
{
public:
	bool Init();
	void Run();

private:
	int OutputMenu();

	DECLARE_SINGLE(CEditorCore)

};

