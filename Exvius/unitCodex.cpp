#include "stdafx.h"
#include "unitCodex.h"

HRESULT unitCodex::init()
{
	_index = 0;

	setCodex();


	return S_OK;
}

void unitCodex::release()
{
}

void unitCodex::addUnit(UN un)
{
	_index++;
	_unitList.insert(make_pair(_index, un));

}

void unitCodex::setCodex()
{
	addUnit(&unitCodex::rain);
	addUnit(&unitCodex::lasswell);
}
