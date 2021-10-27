#pragma once
#include "gameNode.h"
#include "mapTool.h"

class maptoolScene:public gameNode
{
private:
	mapTool* _maptool;
	

public:
	HRESULT init();
	void release();
	void update();
	void render();
};

