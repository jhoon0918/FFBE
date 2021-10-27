#include "stdafx.h"
#include "broadsword.h"

broadsword::broadsword()
{
	//이름
	_name = L"브로드소드";
	_type = L"한손검";
	_num = 1;
	_description = L"공격력 +40";
	_equip._att = 40;

	//능력치 할당
	
}

broadsword::~broadsword()
{
}

HRESULT broadsword::init()
{
	_Image=IMAGEMANAGER->addDImage("broadsword", L"img/equipment/weapon/broadsword.png", 37, 37);

	return S_OK;
}

void broadsword::update()
{
}
