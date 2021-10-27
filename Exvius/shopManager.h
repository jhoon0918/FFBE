#pragma once
#include "singletonBase.h"

class shopManager :public singletonBase<shopManager>
{
public:
	HRESULT init();
	void release();
	void update();
	void render();
};

