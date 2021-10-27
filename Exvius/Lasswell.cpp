#include "stdafx.h"
#include "Lasswell.h"

Lasswell::Lasswell()
{
	//이름
	_name = L"라스웰";
	_num = 2;
	_star = 4;

	//레벨 초기화 및 캐릭터 기본능력치 설정

	_lvl = 1;
	_exp = _lvl * 500;

	_cstat._hp = 186;
	_cstat._mp = 62;
	_cstat._att = 51;
	_cstat._mag = 31;
	_cstat._def = 41;
	_cstat._spr = 21;

	//레벨당 보정값 설정

	_statRB._hp = 122;
	_statRB._mp = 2.1;
	_statRB._att = 11.2;
	_statRB._mag = 4.1;
	_statRB._def = 3.8;
	_statRB._spr = 1.8;


	_price = 500;

	_equip._ohsword = true;
	_equip._thsword = true;
	_equip._blade = true;


}

Lasswell::~Lasswell()
{
}

HRESULT Lasswell::init()
{
	character::init();

	_stateImage[CHARACTER_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("lasswell idle", L"img/character/lasswell/lasswell idle.png", 460, 80, 4, 1);
	_stateImage[CHARACTER_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("lasswell move", L"img/character/lasswell/lasswell move.png", 115, 80, 1, 1);
	_stateImage[CHARACTER_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("lasswell attck", L"img/character/lasswell/lasswell attack.png", 3930, 138, 10, 1);
	_stateImage[CHARACTER_STATE_READY] = IMAGEMANAGER->addFrameDImage("lasswell ready", L"img/character/lasswell/lasswell ready.png", 1380, 80, 12, 1);
	_stateImage[CHARACTER_STATE_MAGIC] = IMAGEMANAGER->addFrameDImage("lasswell magic", L"img/character/lasswell/lasswell magic.png", 460, 80, 4, 1);
	_stateImage[CHARACTER_STATE_LB] = IMAGEMANAGER->addFrameDImage("lasswell lb", L"img/character/lasswell/lasswell lb.png", 7860, 138, 20, 1);
	_stateImage[CHARACTER_STATE_DYING] = IMAGEMANAGER->addFrameDImage("lasswell dying", L"img/character/lasswell/lasswell dying.png", 115, 80, 1, 1);
	_stateImage[CHARACTER_STATE_DEAD] = IMAGEMANAGER->addFrameDImage("lasswell dead", L"img/character/lasswell/lasswell dead.png", 115, 80, 1, 1);
	_stateImage[CHARACTER_STATE_VICTORY] = IMAGEMANAGER->addFrameDImage("lasswell victory", L"img/character/lasswell/lasswell victory.png", 1840, 80, 16, 1);
	_stateImage[CHARACTER_STATE_MENU] = IMAGEMANAGER->addFrameDImage("lasswell menu", L"img/character/lasswell/lasswell menu.png", 70, 50, 1, 1);

	_portrait = IMAGEMANAGER->addFrameDImage("lasswell portrait", L"img/character/lasswell/lasswell portrait.png", 56, 38, 1, 1);
	_equip._ohsword = true;
	_equip._thsword = true;
	_equip._blade = true;
	changeState(CHARACTER_STATE_MENU);


	return S_OK;
}

void Lasswell::update()
{
}
