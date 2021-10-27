#pragma once
#include "gameNode.h"


class battleScene:public gameNode
{
private:
	dImage* background;
	dImage* battlebg;
	dImage*	layer[2];
	dImage* turn;
	dImage* numbers;
	dImage* monsterHP;
	dImage* characterHP;

	RECT UI[3];
	RECT _enemyP[6];
	RECT _playerStand[6];
	RECT _playerAttack;
	RECT _playerMove[6];
	RECT _playerControl[6];
	RECT _port[6];
	RECT _hp[6];
	D2D1_RECT_F _mname;
	D2D1_RECT_F _name[6];
	D2D1_RECT_F _case[6];

	WCHAR tmp[128];
	int turnN;
	int box;

	bool order[6];
	bool ori;
	bool attack;
	
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void boxmove(int b);
};

