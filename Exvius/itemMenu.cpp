#include "stdafx.h"
#include "itemMenu.h"

HRESULT itemMenu::init()
{
	
	_banner[0] = IMAGEMANAGER->addDImage("Ibanner", L"img/ui/equipMenu/itemsetbanner.png", 720, 166);
	_banner[1] = IMAGEMANAGER->addDImage("Ibannertap", L"img/ui/equipMenu/itemsetbannertap.png", 720, 166);
	
	_itemset = IMAGEMANAGER->addDImage("itemsets", L"img/ui/equipMenu/itemset.png", 720, 256);
	
	_buttons[0] = IMAGEMANAGER->addDImage("Ibuttons", L"img/ui/equipMenu/itemequip.png", 720, 115);
	_buttons[1] = IMAGEMANAGER->addDImage("IbuttonIlist", L"img/ui/equipMenu/itemtapequip.png", 720, 115);
	_buttons[2] = IMAGEMANAGER->addDImage("IbuttonElist", L"img/ui/equipMenu/itemequiptap.png", 720, 115);

	_button[0] = RectMake(10, 170, 120, 80);
	for (int i = 1; i < 6; i++)
	{
		_button[i] = RectMake(18 + (i - 1) * 145, 400, 100, 100);
	}
	for (int i = 6; i < 8; i++)
	{
		_button[i] = RectMake(20 + (i - 6)*350,  680, 330, 115);
	}
	banner = 0;
	_tap = 0;

	return S_OK;
}

void itemMenu::release()
{
}

void itemMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_button[0], _ptMouse))
		{
			banner = 1;
		}
		for (int i = 6; i < 8; i++)
		{
			if (PtInRect(&_button[i], _ptMouse))
			{
				_tap = i -5;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (PtInRect(&_tab[i], _ptMouse))
			{
				_menuSelect = i + 1;

			}
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		if (banner == 1)
		{
			changetab(banner);
			banner = 0;
		}
		else if (_tap > 0)
		{
			changetab(_tap+11);
			_tap = 0;
		}
		else if (_menuSelect > 0)
		{
			changetab(_menuSelect);
			_menuSelect = 0;
		}
	}
	
}

void itemMenu::render()
{

	_banner[banner]->render(0, 120);
	_itemset->render(0, 350);
	_buttons[_tap]->render(0, 680);
	
	


	_menu[_menuSelect]->render(0, WINSIZEY - IMAGEMANAGER->findDImage("menu")->getHeight());
}
