#include "stdafx.h"
#include "Jinn.h"

Jinn::Jinn()
{
	//ÀÌ¸§
	_name = L"Áø";
	_num = 1;
	
	_maxHp = 500000;
	_currentHp = _maxHp;
	_att = 50;
	_mag = 60;
	_def = 10;
	_spr = 10;

}

Jinn::~Jinn()
{
}

HRESULT Jinn::init()
{
	monster::init();
	
	_stateImage[MONSTER_IDLE]= IMAGEMANAGER->addFrameDImage("Jinn Idle", L"img/monster/Jinn/Jinn_idle.png", 576, 191, 4, 1);
	_stateImage[MONSTER_ATTACK] = IMAGEMANAGER->addFrameDImage("Jinn Attack", L"img/monster/Jinn/Jinn_atk.png", 288, 191, 2, 1);

	_patternImage[PATTERN1]= IMAGEMANAGER->addFrameDImage("spreadball", L"img/effect/spreadball.png", 960, 80, 12, 1);
	_patternImage[PATTERN2] = IMAGEMANAGER->addFrameDImage("windbomb", L"img/effect/windbomb.png", 640, 64, 10, 1);
	_patternImage[PATTERN3] = IMAGEMANAGER->addFrameDImage("windcutter", L"img/effect/windcutter.png", 448, 40, 8, 1);

	changeState(MONSTER_IDLE);
	changePattern(PATTERN1);

	return S_OK;
}

void Jinn::update()
{
	if (_currentHp < (_maxHp*0.7))changePattern(PATTERN2);
	if (_currentHp < (_maxHp*0.3))changePattern(PATTERN3);
}
