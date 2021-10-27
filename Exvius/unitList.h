#pragma once
#include "menubox.h"

class unitList: public menubox
{

private:
	dImage* _banner[2];
	dImage* _selection[3];
	RECT _selecttab[3];
	
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

