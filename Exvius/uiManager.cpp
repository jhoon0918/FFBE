#include "stdafx.h"
#include "uiManager.h"
#include "menuHeaders.h"

menubox* uiManager::_currentMenu = NULL;

HRESULT uiManager::init()
{
	_currentMenu = NULL;

	


	addMenu("main", new mainMenu);
	addMenu("unit", new equipMenu);
	addMenu("party", new partyMenu);
	addMenu("unitlist", new unitList);
	addMenu("gacha", new gachaMenu);
	addMenu("itemset", new itemMenu);
	addMenu("itemlist", new itemList);
	addMenu("equiplist", new equipList);

	return S_OK;
}

void uiManager::release()
{
	//메뉴 release
	menuboxI miList = _menulist.begin();

	for (; miList != _menulist.end();)
	{
		if (miList->second != NULL)
		{
			if (miList->second == _currentMenu) miList->second->release();
			SAFE_DELETE(miList->second);
			miList = _menulist.erase(miList);
		}
		else ++miList;
	}

	_menulist.clear();
}

void uiManager::update()
{
	if (_currentMenu)_currentMenu->update();	
}

void uiManager::render()
{
	if (_currentMenu)_currentMenu->render();
}

menubox * uiManager::addMenu(string Name, menubox * menu)
{
	if(!menu) return nullptr;

	_menulist.insert(make_pair(Name, menu));
	
	return menu;
}

HRESULT uiManager::changeMenu(string Name)
{
	menuboxI find = _menulist.find(Name);

	if (find == _menulist.end())return E_FAIL;

	if (find->second == _currentMenu)return S_OK;

	if (SUCCEEDED(find->second->init()))
	{
		// 현재 메뉴를 릴리즈 함수 실행시켜주고
		if (_currentMenu)_currentMenu->release();

		//바꾸려는 메뉴로 체인지

		_currentMenu = find->second;

		return S_OK;
	}


	return E_NOTIMPL;
}
