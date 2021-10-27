#include "stdafx.h"
#include "Rain.h"


Rain::Rain()
{
	//이름
	_name = L"레인";
	_num = 1;
	_star = 3;
	
	//레벨 초기화 및 캐릭터 기본능력치 설정

	_lvl = 1;
	_exp = _lvl * 500;
	
	_cstat._hp = 203;
	_cstat._mp = 51	;
	_cstat._att = 42;
	_cstat._mag = 27;
	_cstat._def = 46;
	_cstat._spr = 28;

	//레벨당 보정값 설정

	_statRB._hp		= 143;
	_statRB._mp		= 1.5;
	_statRB._att	= 9.5;
	_statRB._mag	= 3.8;
	_statRB._def	= 5.7;
	_statRB._spr	= 1.9;


	_price = 600;

	_equip._ohsword = true;
	_equip._thsword = true;
	_equip._axe = true;
	
	
}

Rain::~Rain()
{
}

HRESULT Rain::init()
{
	character::init();
	
	_stateImage[CHARACTER_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("Rain idle", L"img/character/rain/rain idle.png", 792, 85, 8, 1);
	_stateImage[CHARACTER_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("Rain move", L"img/character/rain/rain move.png", 396, 85, 4, 1);
	_stateImage[CHARACTER_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("Rain attck", L"img/character/rain/rain attack.png", 2280, 106, 15, 1);
	_stateImage[CHARACTER_STATE_READY] = IMAGEMANAGER->addFrameDImage("Rain ready", L"img/character/rain/rain ready.png", 396, 85, 4, 1);
	_stateImage[CHARACTER_STATE_MAGIC] = IMAGEMANAGER->addFrameDImage("Rain magic", L"img/character/rain/rain magic.png", 396, 85, 4, 1);
	_stateImage[CHARACTER_STATE_LB] = IMAGEMANAGER->addFrameDImage("Rain lb", L"img/character/rain/rain lb.png", 4966, 158, 26, 1);
	_stateImage[CHARACTER_STATE_DYING] = IMAGEMANAGER->addFrameDImage("Rain dying", L"img/character/rain/rain dying.png", 99, 85, 1, 1);
	_stateImage[CHARACTER_STATE_DEAD] = IMAGEMANAGER->addFrameDImage("Rain dead", L"img/character/rain/rain dead.png", 99, 85, 1, 1);
	_stateImage[CHARACTER_STATE_VICTORY] = IMAGEMANAGER->addFrameDImage("Rain victory", L"img/character/rain/rain victory.png", 1188, 85, 12, 1);
	_stateImage[CHARACTER_STATE_MENU] = IMAGEMANAGER->addFrameDImage("Rain menu", L"img/character/rain/rain menu.png", 60, 50, 1, 1);

	_portrait = IMAGEMANAGER->addFrameDImage("Rain portrait", L"img/character/rain/rain portrait.png", 56, 38, 1, 1);
	_equip._ohsword = true;
	_equip._thsword = true;
	_equip._axe = true;
	changeState(CHARACTER_STATE_MENU);

	return S_OK;
}

void Rain::update()
{

}
