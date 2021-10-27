#pragma once
#include "equipment.h"

class broadsword:public equipment
{
public :
	broadsword();
	~broadsword();
	HRESULT init();
	void update();
};

