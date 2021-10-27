#include "stdafx.h"
#include "monsterManager.h"

HRESULT monsterManager::init()
{
	mon = MONSTERCODEX->makeMonster(1);
	mon->init();
	vm.push_back(mon);
	vm.push_back(mon);
	return S_OK;
}

void monsterManager::release()
{
}

void monsterManager::update()
{
}

void monsterManager::render()
{
}
