#pragma once
#include "menubox.h"


class gachaMenu:public menubox
{

private:
	D2D1_RECT_F vd;
	RECT _gtap[2];
	dImage* gachabg;
	dImage* _gbanner;
	dImage* _gacha1[2];
	dImage* _gacha2[2];
	int g1;
	int g2;
	
	RECT _gacha[11];
	dImage* summonbg;
	dImage* star[3];

	RECT next;
	dImage* _next[2];
	int n;

	int h;
	int nl;
	int gachaN[11];


	int frameX[11];
	int alpha;
	float count;

	bool summon;
	bool video;
	bool done;
	bool open;

public:

	HRESULT init();
	void release();
	void update();
	void render();
	void crystalcontrol();
};

