#pragma once
#include "menubox.h"


class itemMenu:public menubox
{
private:
	
	dImage* _banner[2];
	dImage* _itemset;
	dImage* _buttons[3];
	
	RECT _button[8];

	int banner;
	int _tap;
	
public:

	HRESULT init();
	void release();
	void update();
	void render();

};

