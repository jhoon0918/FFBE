#pragma once
#include "menubox.h"

class mainMenu:public menubox
{

private:
	dImage* _layer;
	dImage* _battle;
	dImage* _world[2];
	dImage* _expedition[2];
	
	RECT _party[6];
	RECT _move[6];
	RECT _tap[2];
	RECT _attack;
	
	int wt;
	int et;
	int box;
	
	bool ori;
	bool attack;

public:
	HRESULT init();
	void release();
	void update() ;
	void render() ;

	void boxmove(int b);
};

