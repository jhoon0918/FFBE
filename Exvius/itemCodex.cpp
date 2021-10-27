#include "stdafx.h"
#include "itemCodex.h"

HRESULT itemCodex::init()
{
	_index = 0;

	setCodex();


	return S_OK;
}

void itemCodex::release()
{
}

void itemCodex::addItem(ITN itn)
{
	_index++;
	_itemList.insert(make_pair(_index, itn));
}

void itemCodex::setCodex()
{
	addItem(&itemCodex::Potion);
}
