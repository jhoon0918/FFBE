#include "stdafx.h"
#include "calculationManager.h"

HRESULT calculationManager::init()
{
	return S_OK;
}

void calculationManager::release()
{
}

void calculationManager::update()
{
}

void calculationManager::render()
{
}

STAT calculationManager::statCalculation(character* charac)
{
	STAT baseStat = charac->getStat();
	STATRB balancing = charac->getRB();
	
	int level = charac->getLevel();

	STAT allStat;

	allStat._hp = STAT_CALCULATION(baseStat._hp, level, balancing._hp);
	allStat._mp = STAT_CALCULATION(baseStat._mp, level, balancing._mp);
	allStat._att = STAT_CALCULATION(baseStat._att, level, balancing._att);
	allStat._mag = STAT_CALCULATION(baseStat._mag, level, balancing._mag);
	allStat._def = STAT_CALCULATION(baseStat._def, level, balancing._def);
	allStat._spr = STAT_CALCULATION(baseStat._spr, level, balancing._spr);

	charac->setReal(allStat);
	return allStat;
}

STAT calculationManager::sumCalculation(character* charac, equipment* part)
{
	STAT baseStat = charac->getReal();
	EQUIP equip = part->getInfo();

	STAT equipStat;

	equipStat._hp = EQUIP_CALCULATION(baseStat._hp, equip._hp);
	equipStat._mp = EQUIP_CALCULATION(baseStat._mp, equip._mp);
	equipStat._att = EQUIP_CALCULATION(baseStat._att, equip._att);
	equipStat._mag = EQUIP_CALCULATION(baseStat._mag,  equip._mag);
	equipStat._def = EQUIP_CALCULATION(baseStat._def,  equip._def);
	equipStat._spr = EQUIP_CALCULATION(baseStat._spr,  equip._spr);


	return equipStat;
}

STAT calculationManager::substractCalculation(character * charac, equipment * part)
{
	STAT baseStat = charac->getReal();
	EQUIP equip = part->getInfo();

	STAT equipStat;

	equipStat._hp = TAKEOFF_CALCULATION(baseStat._hp, equip._hp);
	equipStat._mp = TAKEOFF_CALCULATION(baseStat._mp, equip._mp);
	equipStat._att = TAKEOFF_CALCULATION(baseStat._att, equip._att);
	equipStat._mag = TAKEOFF_CALCULATION(baseStat._mag, equip._mag);
	equipStat._def = TAKEOFF_CALCULATION(baseStat._def, equip._def);
	equipStat._spr = TAKEOFF_CALCULATION(baseStat._spr, equip._spr);


	return equipStat;
}
