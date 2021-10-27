#pragma once
#include "singletonBase.h"
#include "character.h"
#include "equipment.h"

//계산식
#define STAT_CALCULATION(baseStat, level, balancing)\
(baseStat + (level * balancing));

//장비 장착 계산식
#define EQUIP_CALCULATION(baseStat,equip)\
(baseStat + equip);

//장비 탈착 계산식
#define TAKEOFF_CALCULATION(baseStat,equip)\
(baseStat-equip);

class character;
class equipment;

class calculationManager:public singletonBase<calculationManager>
{

private:
	int _money;
	int _rapis;

public:
	HRESULT init();
	void release();
	void update();
	void render();
	
	//능력치 계산
	STAT statCalculation(character* charac);
	
	//장비 합산 능력치 계산
	STAT sumCalculation(character* charac, equipment* part);

	//장비 탈착 능력치 계산
	STAT substractCalculation(character* charac, equipment* part);


	void setMoney(int Money) { _money = Money; }
	int getMoney() { return _money; }

	void setRapis(int Rapis) { _rapis = Rapis; }
	int getRapis() { return _rapis; }

};

