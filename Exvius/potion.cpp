#include "stdafx.h"
#include "potion.h"

potion::potion()
{
	

	_name = L"����";
	_description = L"ü���� 200 ȸ���Ѵ�";
	_restore = true;
	_amount = 200;
	_num = 1;

}

potion::~potion()
{
}

HRESULT potion::init()
{
	_image = IMAGEMANAGER->addDImage("����", L"img/ui/itemMenu/potion.png", 38, 60);
	return S_OK;
}

void potion::update()
{
}
