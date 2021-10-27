#pragma once
#include "singletonBase.h"
#include "characterHeaders.h"
#include <map>

class unitCodex :public singletonBase<unitCodex>
{
private:
	typedef character*(unitCodex::*UN)();
	typedef map<int, UN> unitList;


private:
	unitList _unitList;

	int _index;



public:
	HRESULT init();
	void release();

	void addUnit(UN un);
	void setCodex();

	character* makeUnit(int num) { return (this->*_unitList[num])(); }

	int getIndex() { return _index; }


	//--------------유닛도감 리스트--------------------

	//Unit No.1~10

	character* rain() { return new Rain; }
	character* lasswell() { return new Lasswell; }

};

