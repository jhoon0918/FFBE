#pragma once
#include "singletonBase.h"
#include "item.h"
#include <map>

class storageManager :public singletonBase<storageManager>
{
private:
	typedef vector<item*>				vitem;
	typedef vector<item*>::iterator		viitem;

	typedef map<int, int>				setorder;

private:
	
	dImage* layer;
	RECT layerI[50];

	int _itemcount;
	int _limit;
	int _m;

	vitem		vi;
	viitem		vii;

	setorder itemset;

	
	bool _back;
	bool _set;
	
	
	
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void backon();
	void loadI(item* I);
	void position();

	dImage* getLayer() { return layer; }

	vitem getItem() { return vi; }
	
	viitem getIItem() { return vii;}
	
	setorder getOrder() { return itemset; }


	bool getBack() { return _back; }
	void setBack(bool Back) { _back = Back; }

	bool getSet() { return _set; }
	void setSet(bool Set) { _set = Set; }

	int getLimit() { return _limit; }
	void setLimit(int limit) { _limit = limit; }
	
	int getCount() { return _itemcount; }
	void setCount(int count) { _itemcount = count; }

	int getM() { return _m; }
	void setM(int M) { _m = M; }
};

