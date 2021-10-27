#include "stdafx.h"
#include "item.h"

HRESULT item::init()
{
	_restore = false;
	_dealt = false;
	_amount = 0;

	_name = L" ";
	_description = L" ";
	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render(float x, float y)
{
	_image->render(x, y);
}
