#pragma once
#include "singletonBase.h"
#include "menubox.h"

class uiManager :public singletonBase<uiManager>
{
private:
	typedef map<string, menubox*>				menuboxList;
	typedef map<string, menubox*>::iterator		menuboxI;


private:
	
	//�޴� ����Ʈ
	menuboxList _menulist;

	//���� �޴�
	static menubox*	_currentMenu;

	bool _open;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	menubox* addMenu(string Name, menubox* menu);
	HRESULT changeMenu(string Name);


	menubox* getCurrentMenu() { return _currentMenu; }


	bool getOpen() { return _open; }
	void setOepn(bool open) { _open = open; }



};

