#pragma once
#include "gameNode.h"
#include "broadsword.h"

class mainScene :public gameNode
{


private:
	dImage* _userInfo;
	dImage* _background;
	
	
	int money;
	int rapis;
	int gapm;
	int gapr;

	broadsword* _br;

	

	

	

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void changescene();
	
};

