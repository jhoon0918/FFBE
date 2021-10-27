#pragma once
#include "menubox.h"

class partyMenu :public menubox
{
private:
	dImage* _banner[2];
	dImage* _party;
	dImage* _buttons[5];
	

	RECT _button[15];

	int banner;
	int _tap;
public:
	 HRESULT init();
	 void release();
	 void update();
	 void render();

};

