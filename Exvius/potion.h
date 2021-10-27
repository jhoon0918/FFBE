#pragma once
#include "item.h"

class potion:public item
{
private:
	
public:
	potion();
	~potion();
	HRESULT init();
	void update();
};

