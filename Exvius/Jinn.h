#pragma once
#include "monster.h"

class Jinn:public monster
{
private:

public:
	Jinn();
	~Jinn();
	HRESULT init();
	void update();
};

