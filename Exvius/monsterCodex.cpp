#include "stdafx.h"
#include "monsterCodex.h"

HRESULT monsterCodex::init()
{
	_index = 0;
	
	setCodex();

	return S_OK;
}

void monsterCodex::release()
{
}

void monsterCodex::addMonster(MN mn)
{
	_index++;
	_monsterList.insert(make_pair(_index, mn));

}

void monsterCodex::setCodex()
{
	addMonster(&monsterCodex::jinn);
}
