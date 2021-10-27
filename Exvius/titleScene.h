#pragma once
#include "gameNode.h"
class titleScene:public gameNode
{
private:
	dImage* _screen;
	dImage* _layer;
	RECT _maptool;

	float _frameCount;
	int _frameX;
	int _frameY;

public:
	HRESULT init();
	void release();
	void update();
	void render();
};

