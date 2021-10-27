#pragma once
#include "singletonBase.h"
#include "character.h"
#include "equipment.h"

//����
#define STAT_CALCULATION(baseStat, level, balancing)\
(baseStat + (level * balancing));

//��� ���� ����
#define EQUIP_CALCULATION(baseStat,equip)\
(baseStat + equip);

//��� Ż�� ����
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
	
	//�ɷ�ġ ���
	STAT statCalculation(character* charac);
	
	//��� �ջ� �ɷ�ġ ���
	STAT sumCalculation(character* charac, equipment* part);

	//��� Ż�� �ɷ�ġ ���
	STAT substractCalculation(character* charac, equipment* part);


	void setMoney(int Money) { _money = Money; }
	int getMoney() { return _money; }

	void setRapis(int Rapis) { _rapis = Rapis; }
	int getRapis() { return _rapis; }

};

