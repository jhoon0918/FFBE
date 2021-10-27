#pragma once
#include "singletonBase.h"
#include "monsterHeaders.h"
#include <map>

class monsterCodex:public singletonBase<monsterCodex>
{
private:
	typedef monster*(monsterCodex::*MN)();
	typedef map<int, MN> monsterList;

private:
	monsterList _monsterList;

	int _index;

public:
	HRESULT init();
	void release();

	void addMonster(MN mn);
	void setCodex();

	monster* makeMonster(int num) { return (this->*_monsterList[num])(); }

	int getIndex() { return _index; }


	//--------------유닛도감 리스트--------------------

	//Unit No.1~10

	monster* jinn() { return new Jinn; }


};

