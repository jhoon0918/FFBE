#pragma once
#include "singletonBase.h"
#include "equipment.h"

class equipmentManager :public singletonBase<equipmentManager>
{
private:
	typedef vector<equipment*>				vEquipment;
	typedef vector<equipment*>::iterator	viEquipment;
	
private:
	
	vEquipment			ve;
	viEquipment			vie;

	dImage* layer;
	RECT layerE[50];

	int _equipcount;
	int _limit;
	int _m;

	bool _back;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void backon();
	void loadE(equipment* E);
	void position();

	dImage* getLayer() { return layer; }

	vEquipment getEQ() { return ve; }

	viEquipment getIEQ() { return vie; }

	bool getBack() { return _back; }
	void setBack(bool Back) { _back = Back; }

	int getLimit() { return _limit; }
	void setLimit(int limit) { _limit = limit; }

	int getCount() { return _equipcount; }
	void setCount(int count) { _equipcount = count; }

	int getM() { return _m; }
	void setM(int M) { _m = M; }
};

