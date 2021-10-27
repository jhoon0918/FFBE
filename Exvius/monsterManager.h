#pragma once
#include "monster.h"
#include "singletonBase.h"


class monsterManager:public singletonBase<monsterManager>
{
private:
	typedef vector<monster*>				vmonster;
	typedef vector<monster*>::iterator		vimonster;

private:

	monster* mon;
	vmonster vm;
	vimonster vim;


public:
	HRESULT init();
	void release();
	void update();
	void render();

	vmonster getVm() { return vm; }
	vimonster getVim() { return vim; }
};

