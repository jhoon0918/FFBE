#include "stdafx.h"
#include "unitList.h"
HRESULT unitList::init()
{

	_banner[0] = IMAGEMANAGER->addDImage("Ubanner", L"img/ui/characterMenu/unitbanner.png", 720, 166);
	_banner[1] = IMAGEMANAGER->addDImage("Ubannertap", L"img/ui/characterMenu/unitbannertap.png", 720, 166);

	_selection[0] = IMAGEMANAGER->addDImage("normal", L"img/ui/characterMenu/normal.png", 720, 94);
	_selection[1] = IMAGEMANAGER->addDImage("material", L"img/ui/characterMenu/material.png", 720, 94);
	_selection[2] = IMAGEMANAGER->addDImage("all", L"img/ui/characterMenu/all.png", 720, 94);

	_selecttab[0] = RectMake(0, 320, 240, 60);
	_selecttab[1] = RectMake(240, 320, 240, 60);
	_selecttab[2] = RectMake(480, 320, 240, 60);

	//유닛 카운트 백그라운드 검은색
	_black = IMAGEMANAGER->findDImage("black");
	
	_button = RectMake(10, 170, 120, 80);
	backsheet = RectMake(0, 400, 720, 480);
	banner = 0;
	if (UNITMANAGER->getSeller())
	{
		UNITMANAGER->selling();
	}
	return S_OK;
}

void unitList::release()
{
	UNITMANAGER->setSelector(0);
	UNITMANAGER->setSeller(false);
}

void unitList::update()
{

	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (UNITMANAGER->getSeller())
		{
			UNITMANAGER->selling();
		}
		else if (UNITMANAGER->getBuild())
		{
			UNITMANAGER->buildP();
		}
		UNITMANAGER->setM(_ptMouse.y);
		for (int i = 0; i < 3; i++)
		{
			if (PtInRect(&_selecttab[i], _ptMouse))
			{
				UNITMANAGER->setSelector(i);
				UNITMANAGER->setPosition(true);
			}
		}

		for (int i = 0; i < 6; i++)
		{
			if (PtInRect(&_tab[i], _ptMouse))
			{
				_menuSelect = i + 1;
			}
		}
		if (PtInRect(&_button, _ptMouse))
		{
			banner = 1;
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		if (_menuSelect > 0)
		{
			changetab(_menuSelect);
			_menuSelect = 0;
		}
		if (banner > 0)
		{
			changetab(banner + 1);
			banner = 0;
		}
		if (!UNITMANAGER->getBack())UNITMANAGER->setBack(true);
		if (UNITMANAGER->getSell() > 0)UNITMANAGER->setSell(0);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&backsheet, _ptMouse))
		{
			UNITMANAGER->setBack(false);
		}
	}
	UNITMANAGER->backon();
}

void unitList::render()
{
	WCHAR str[128];
	

	UNITMANAGER->render();
	_selection[UNITMANAGER->getSelector()]->render(0, 286);
	_banner[banner]->render(0, 120);
	
	if (UNITMANAGER->getSeller())
	{
		_black->render(500, 634);

		swprintf_s(str, L"%d / %d", UNITMANAGER->getUnitCount(), UNITMANAGER->getLimit());
		DTDMANAGER->printText(str, 635, 683, 200, 100, 30);
	}
	else
	{
		_black->render(500, 784);
		
		swprintf_s(str, L"%d / %d", UNITMANAGER->getUnitCount(), UNITMANAGER->getLimit());
		DTDMANAGER->printText(str, 635, 833, 200, 100, 30);
	}
	


	_menu[_menuSelect]->render(0, WINSIZEY - IMAGEMANAGER->findDImage("menu")->getHeight());
	
	
}
