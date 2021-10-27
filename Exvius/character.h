#pragma once
#include "characterMiscel.h"

class character
{
protected:
	//기본 캐릭터 이미지, 이미지 관련 enum문
	dImage* _currentImage;
	dImage* _stateImage[11];
	dImage* _portrait;
	CHARACTER_STATE _state;

	//프레임 조절 함수
	int _frameX;
	int _frameY;
	float _frameCount;
	bool onDuty;

	//이름, 형식번호, 별등급
	wstring _name;
	int _num;
	int _star;


	//캐릭터 개별 스탯, 착용가능 장비, 장비 부위
	STAT	_cstat;
	ABLE	_equip;
	STATRB _statRB;

	wstring _lefthand;
	wstring _righthand;
	wstring _head;
	wstring _body;
	wstring _acc1;
	wstring _acc2;
	
	//체력 계산 후 현재 체력

	int _currentHP;

	//살았는지 죽었는지 체크용
	bool _life; 
	
	int _lvl;
	float _exp;

	//판매시 가격
	int _price;

	//파티에 넣을 사항
	STAT purestat;
	STAT realstat;

	//턴 이용이 가능한가 아닌가

	bool turn;
	bool phase;

public:
	virtual HRESULT init();
	void release();

	void update();
	void render(float x,float y);

	void frameControl();
	void changeState(CHARACTER_STATE state);

	//----------------------------------접근자-------------

	dImage* getImage() { return _currentImage; }
	CHARACTER_STATE getState() { return _state; }
	dImage* getPortrait() { return _portrait; }

	wstring getName() { return _name; }
	int getNum() { return _num; }

	STAT getStat() { return _cstat; }
	void setStat(STAT stat) { _cstat = stat; }

	ABLE getEquip() { return _equip; }
	void setEquip(ABLE equip) { _equip = equip; }

	wstring getLeft() { return _lefthand; }
	void setLeft(wstring left) { _lefthand = left; }

	wstring getRight() { return _righthand; }
	void setright(wstring right) { _righthand = right; }

	wstring getHead() { return _head; }
	void setHead(wstring head) { _head = head; }

	wstring getBody() { return _body; }
	void setBody(wstring body) { _body = body; }

	wstring getAcc1() { return _acc1; }
	void setAcc1(wstring acc1) { _acc1 = acc1; }

	wstring getAcc2() { return _acc2; }
	void setAcc2(wstring acc2) { _acc2 = acc2; }

	STATRB getRB() { return _statRB; }
	
	bool getLife() { return _life; }
	void setLife(bool life) { _life = life; }

	int getLevel() { return _lvl; }
	void setLevel(int lvl) { _lvl = lvl; }

	float getExp() { return _exp; }
	void setExp(float exp) { _exp = exp; }

	int getPrice() { return _price; }

	int getStar() { return _star; }

	//파티에 넣을 사항
	STAT getPure() { return purestat; }
	void setPure(STAT pure) { purestat = pure; }

	STAT getReal() { return realstat; }
	void setReal(STAT real) { realstat = real; }

	int getCHP() { return _currentHP; }
	void setCHP(int _CHP) { _currentHP = _CHP; }
	

	bool getDuty() { return onDuty; }
	void setDuty(bool duty) { onDuty = duty; }

	int getFrameX() { return _frameX; }
	void setFrameX(int frameX) { _frameX = frameX; }

	bool getTurn() { return turn;}
	void setTurn(bool Turn) { turn = Turn; }

	bool getPhase() { return phase; }
	void setPhase(bool Phase) { phase = Phase; }
};

