#pragma once
#include "singletonBase.h"

class partyManager :public singletonBase<partyManager>
{
public:
	HRESULT init();
	void release();
	void update();
	void render();
};

