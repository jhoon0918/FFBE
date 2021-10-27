#pragma once
#include "tilebase.h"

class mapTool
{
private:
	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile _tiles[TILEX * TILEY];

	dImage* _tileImage[TILEMAX];
	RECT background;
	RECT Rect;

	char name[128];

	int _pos[2];
	int _ctrSelect;
	int _x;
	int _y;
	float _rx;
	float _ry;

	int _width;
	int _height;

	int _t;
	int index;
	int _tilenumber;

	int _initX;
	int _endX;
	int _initY;
	int _endY;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void setup();
	void setMap();

	void save();
	void load(const char* name, int width, int height);


	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
};

