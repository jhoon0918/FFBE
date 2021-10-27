#pragma once
#include "characterMiscel.h"

class character
{
protected:
	//�⺻ ĳ���� �̹���, �̹��� ���� enum��
	dImage* _currentImage;
	dImage* _stateImage[11];
	dImage* _portrait;
	CHARACTER_STATE _state;

	//������ ���� �Լ�
	int _frameX;
	int _frameY;
	float _frameCount;
	bool onDuty;

	//�̸�, ���Ĺ�ȣ, �����
	wstring _name;
	int _num;
	int _star;


	//ĳ���� ���� ����, ���밡�� ���, ��� ����
	STAT	_cstat;
	ABLE	_equip;
	STATRB _statRB;

	wstring _lefthand;
	wstring _righthand;
	wstring _head;
	wstring _body;
	wstring _acc1;
	wstring _acc2;
	
	//ü�� ��� �� ���� ü��

	int _currentHP;

	//��Ҵ��� �׾����� üũ��
	bool _life; 
	
	int _lvl;
	float _exp;

	//�ǸŽ� ����
	int _price;

	//��Ƽ�� ���� ����
	STAT purestat;
	STAT realstat;

	//�� �̿��� �����Ѱ� �ƴѰ�

	bool turn;
	bool phase;

public:
	virtual HRESULT init();
	void release();

	void update();
	void render(float x,float y);

	void frameControl();
	void changeState(CHARACTER_STATE state);

	//----------------------------------������-------------

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

	//��Ƽ�� ���� ����
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

