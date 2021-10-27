#pragma once
#include "singletonBase.h"
#include "equipHeaders.h"
#include <map>


class equipCodex:public singletonBase<equipCodex>
{
private:
	typedef equipment*(equipCodex::*EN)();
	typedef map<int, EN> equipList;


private:
	equipList _equipList;

	int _index;



public:
	HRESULT init();
	void release();

	void addEquip(EN en);
	void setCodex();

	equipment* makeEquip(int num) { return (this->*_equipList[num])(); }

	int getIndex() { return _index; }


	//--------------���ֵ��� ����Ʈ--------------------

	//Unit No.1~10

	equipment* Broadsword() { return new broadsword; }
	//euqipment* lasswell() { return new Lasswell; }


};

