#include "stdafx.h"
#include "broadsword.h"

broadsword::broadsword()
{
	//�̸�
	_name = L"��ε�ҵ�";
	_type = L"�Ѽհ�";
	_num = 1;
	_description = L"���ݷ� +40";
	_equip._att = 40;

	//�ɷ�ġ �Ҵ�
	
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
