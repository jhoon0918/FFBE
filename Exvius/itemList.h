#pragma once
#include "menubox.h"

class itemList: public menubox
{
private:
	dImage* _banner[2];

	RECT _button;
	RECT backsheet;

	dImage* _black;

	int banner;

public:
	HRESULT init();
	void release();
	void update();
	void render();
};

