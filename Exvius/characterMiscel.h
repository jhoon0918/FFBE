#pragma once

typedef struct tagCharacterStat 
{
	float _hp ;
	float _mp ;
	float _att;
	float _mag;
	float _def;
	float _spr;
}STAT, *PSTAT;

typedef struct tagStatReBalance
{
	float _hp;
	float _mp;
	float _att;
	float _mag;
	float _def;
	float _spr;
}STATRB, *PSTATRB;

typedef struct tagEquippable
{
	bool _dagger;
	bool _ohsword;
	bool _thsword;
	bool _blade;
	bool _staff;
	bool _rod;
	bool _bow;
	bool _axe;
	bool _hammer;
	bool _lance;
	bool _harp;
	bool _whip;
	bool _ram;
	bool _gun;
	bool _mace;
	bool _nuckle;
}ABLE, *PABLE;


enum CHARACTER_STATE
{
	CHARACTER_STATE_MENU,
	CHARACTER_STATE_IDLE,
	CHARACTER_STATE_MOVE,
	CHARACTER_STATE_ATTACK,
	CHARACTER_STATE_READY,
	CHARACTER_STATE_MAGIC,
	CHARACTER_STATE_LB,
	CHARACTER_STATE_DYING,
	CHARACTER_STATE_DEAD,
	CHARACTER_STATE_VICTORY,
	END_CHARACTER_STATE
};