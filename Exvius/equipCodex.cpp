#include "stdafx.h"
#include "equipCodex.h"

HRESULT equipCodex::init()
{
	_index = 0;

	setCodex();


	return S_OK;
}

void equipCodex::release()
{
}

void equipCodex::addEquip(EN en)
{
	_index++;
	_equipList.insert(make_pair(_index, en));
}

void equipCodex::setCodex()
{
	addEquip(&equipCodex::Broadsword);
}
