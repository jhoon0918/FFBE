#pragma once
#include "singletonBase.h"
#include "character.h"




class unitManager :public singletonBase<unitManager>
{
private:
	typedef vector<character*>					vcharacter;
	typedef vector<character*>::iterator		vicharacter;

	typedef map<int, int>		intt;

private:

	dImage* _stand;
	RECT standR[100];
	
	int _unitcount;
	int _limit;

	character* ch;
	vcharacter vc;
	vicharacter vic;
	vcharacter vc2;
	vicharacter vic2;
	vcharacter all;
	vicharacter alli;

	vcharacter gacha;
	vicharacter gachai;
	
	vcharacter party;
	vicharacter partyi;

	CHARACTER_STATE shift;

	bool _position;

	dImage* _selling[3];
	RECT _sell[2];
	int sell;
	
	dImage* _cube;

	RECT merchant[50];
	int gain;

	intt merlist;
	int ml;

	intt ptlist;
	int pt;

	int _selector;
	int tmp;
	int m;
	bool _back;
	bool _seller;
	bool _build;
	bool attack;

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void render(int x,int  y, int i);

	
	void selling();
	void backon();
	void loadC(character* c);
	void loadM(character* m);
	void loadP(character* p);
	void loadA();

	void position();
	void buildP();
	void battleframe(CHARACTER_STATE state, int number,bool continuous=false);
	void attackMove(int b,int moveX,int moveX1, int moveY, int moveY1, int placeX, int placeX1, int placeY,int placeY1,int returnX,int returnX1,int returnY, int returnY1);


	void gachaOn(character* g);
	void gachaFinish();


	vcharacter getVC() { return vc; }
	vicharacter getVIC() { return vic; }

	vcharacter getVC2() { return vc2; }
	vicharacter getVIC2() { return vic2; }

	vcharacter	getAll() { return all; }
	vicharacter getAllI() { return alli; }

	vcharacter getGacha() { return gacha; }
	vicharacter getGachaI() { return gachai; }

	vcharacter getParty() { return party; }
	vicharacter getPartyI() { return partyi; }

	dImage* getStand() { return _stand; }

	intt getMerlist() { return merlist; }

	intt getPtlist() { return ptlist; }

	int getUnitCount() { return _unitcount; }
	void setUnitCount(int UnitCount) { _unitcount = UnitCount; }

	int getLimit() { return _limit; }
	void setLimit(int Limit) { _limit = Limit; }


	int getSell() { return sell; }
	void setSell(int Sell) { sell = Sell; }

	int getGain() { return gain; }
	void setGain(int Gain) { gain = Gain; }

	int getML() { return ml; }
	void setML(int ML) { ml = ML; }

	int getSelector() { return _selector; }
	void setSelector(int Selector) { _selector = Selector; }

	int getM() { return m; }
	void setM(int M) { m = M; }

	int getPT() { return pt; }
	void setPT(int PT) { pt = PT; }

	bool getBack() { return _back; }
	void setBack(bool BACK) { _back = BACK; }

	bool getPosition() { return _position; }
	void setPosition(bool Position) { _position=Position; }

	bool getSeller() { return _seller; }
	void setSeller(bool Seller) { _seller = Seller; }

	bool getBuild() { return _build; }
	void setBuild(bool Build) { _build = Build; }

	bool getAttack() { return attack; }
	void setAttack(bool Attack) { attack = Attack; }
};

