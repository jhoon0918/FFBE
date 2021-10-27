#include "stdafx.h"
#include "potion.h"

potion::potion()
{
	

	_name = L"포션";
	_description = L"체력을 200 회복한다";
	_restore = true;
	_amount = 200;
	_num = 1;

}

potion::~potion()
{
}

HRESULT potion::init()
{
	_image = IMAGEMANAGER->addDImage("포션", L"img/ui/itemMenu/potion.png", 38, 60);
	return S_OK;
}

void potion::update()
{
}
