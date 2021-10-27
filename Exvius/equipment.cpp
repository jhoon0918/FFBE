#include "stdafx.h"
#include "equipment.h"

HRESULT equipment::init()
{
	_equip._weapon = true;
	_equip._hp = 0;
	_equip._mp = 0;
	_equip._att = 0;
	_equip._mag = 0;
	_equip._def = 0;
	_equip._spr = 0;

	return S_OK;
}

void equipment::release()
{
}

void equipment::update()
{
}

void equipment::render(float x, float y)
{
	_Image->render(x, y);
}
