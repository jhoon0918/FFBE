#pragma once
#include "singletonBase.h"
#include "itemHeaders.h"
#include <map>

class itemCodex: public singletonBase<itemCodex>
{
private:
	typedef item*(itemCodex::*ITN)();
	typedef map<int, ITN> itemList;


private:
	itemList _itemList;

	int _index;



public:
	HRESULT init();
	void release();

	void addItem(ITN itn);
	void setCodex();

	item* makeItem(int num) { return (this->*_itemList[num])(); }

	int getIndex() { return _index; }


	//--------------���ֵ��� ����Ʈ--------------------

	//Unit No.1~10

	item* Potion() { return new potion; }
	//item* lasswell() { return new Lasswell; }


};

