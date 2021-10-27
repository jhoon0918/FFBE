#pragma once

enum MONSTER_STATE
{
	MONSTER_IDLE,
	MONSTER_ATTACK,
	MONSTER_END
};
enum MONSTER_PATTERN
{
	PATTERN1,
	PATTERN2,
	PATTERN3,
	PATTERN4,
	PATTERN5,
	PATTERN_END
};
class monster
{
protected:
	//기본 몬스터 이미지, 이미지 관련 진행

	dImage* _currentImage;
	dImage* _currentPattern;
	dImage* _stateImage[2];
	dImage* _patternImage[5];
	MONSTER_STATE _state;
	MONSTER_PATTERN _pattern;

	//프레임 조절 함수
	int _frameX;
	int _frameY;
	int _framepX;
	int _framepY;
	float _frameCount;
	float _framepCount;
	bool onDuty;

	//이름, 형식번호
	wstring _name;
	int _num;


	//스탯, 최대 체력, 현재 체력
	float _maxHp;
	float _currentHp;
	float _def;
	float _spr;
	float _att;
	float _mag;
	
	//살았는지 죽었는지
	bool _life;
	
	//턴인지 아닌지, 패턴인지 아닌지
	bool turn;
	bool pattern;
	bool phase;

	//죽었을때 사라지는건 알파값으로 채용
	float _alpha;

public:

	virtual HRESULT init();
	void release();
	void update();
	void render(float x, float y);
	void prender(float x, float y);

	void frameControl();
	void patternControl();
	void changeState(MONSTER_STATE state);
	void changePattern(MONSTER_PATTERN pattern);

	//---------------------접근자-----------------------

	dImage* getImage() { return _currentImage; }
	MONSTER_STATE getState() { return _state; }
	MONSTER_PATTERN getMPattern() { return _pattern; }

	wstring getName() { return _name; }
	int getNum() { return _num; }

	float getMaxHP() { return _maxHp; }
	float getHP() { return _currentHp; }
	void setHP(float currentHP) { _currentHp = currentHP; }

	float getDef() { return _def; }
	void setDef(float Def) { _def = Def; }

	float getSpr() { return _spr; }
	void setSpr(float Spr) { _spr = Spr; }
	
	float getAtt() { return _att; }
	void setAtt(float Att) { _att = Att; }

	float getMag() { return _mag; }
	void setMag(float Mag) { _mag = Mag; }

	bool getLife() { return _life; }
	void setLife(bool life) { _life = life; }

	bool getDuty() { return onDuty; }
	void setDuty(bool duty) { onDuty = duty; }

	int getFrameX() { return _frameX; }
	void setFrameX(int frameX) { _frameX = frameX; }

	bool getTurn() { return turn; }
	void setTurn(bool Turn) { turn = Turn; }

	bool getPhase() { return phase; }
	void setPhase(bool Phase) { phase = Phase; }

};

