#pragma once
#include "singletonBase.h"

class Player;
class Item;
class Skill;

class dialogManager : public singletonBase<dialogManager>
{
private:
	typedef vector<LPCWCHAR>			dialog;
	typedef vector<LPCWCHAR>::iterator	dialogIter;

	typedef vector<wstring>				battleLog;
	typedef vector<wstring>::iterator	battleIter;

private:
	//��ȭâ
	dImage* _back;
	dImage* _border;
	dImage* _leftBorder;
	dImage* _rightBorder;


	//��ȭ log�� ���� vector
	LPCWCHAR _currentFileName;
	dialog _storyMetaData;
	int _metaDataNum;

	//��� ��ȣ, ���� ��� ��, �ӵ� ī��Ʈ
	int _scriptNum;
	int _size;
	float _count;

	//���̾�α� ��� ����
	bool _print;



	//���� log�� ���� vector
	battleLog _battleLog;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void loadMetaData(LPCWCHAR fileName);
	void loadScript();



	void resetTimer();
	//==================  �α� �߰�  ==================//
	void addItemLog(Player* player, Item* item);
	void addExpLog(Player* player, int exp);
	void levelUPLog(Player* player, int level);

	void useSkillLog(Player* player, Skill* skill);
	void failSkillLog();

	void greatSkillLog();
	void worseSkillLog();
	void noneSkillLog();

	void hitDamageLog(Player* player, int damage);





	bool getPrint() { return _print; }
	void setPrint(bool print) { _print = print; }


	battleLog* getBattleLog() { return &_battleLog; }
};