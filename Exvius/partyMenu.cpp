#include "stdafx.h"
#include "partyMenu.h"

HRESULT partyMenu::init()
{
	_banner[0]= IMAGEMANAGER->addDImage("banner", L"img/ui/characterMenu/partybanner.png", 720, 105);
	_banner[1] = IMAGEMANAGER->addDImage("bannertap", L"img/ui/characterMenu/bannertap.png", 720, 105);
	_party= IMAGEMANAGER->addDImage("party", L"img/ui/characterMenu/partytab.png", 720, 380);
	_buttons[0]= IMAGEMANAGER->addDImage("buttons", L"img/ui/characterMenu/buttons.png", 720, 150);
	_buttons[1] = IMAGEMANAGER->addDImage("buttonlist", L"img/ui/characterMenu/buttonlist.png", 720, 150);
	_buttons[2] = IMAGEMANAGER->addDImage("buttonsell", L"img/ui/characterMenu/buttonsell.png", 720, 150);
	_buttons[3] = IMAGEMANAGER->addDImage("buttonenhance", L"img/ui/characterMenu/buttonenhance.png", 720, 150);
	_buttons[4] = IMAGEMANAGER->addDImage("buttonawaken", L"img/ui/characterMenu/buttonawaken.png", 720, 150);
	

	_button[0] = RectMake(10, 170, 120, 80);
	for (int i = 1; i < 6; i++)
	{
		_button[i] = RectMake(30+(i-1)*80+(i-1)*60, 400, 80, 70);
	}
	for (int i = 6; i < 11; i++)
	{
		_button[i] = RectMake(23 + (i - 6) * 100 + (i - 6) * 40, 535, 100, 100);
	}
	for (int i = 11; i < 15; i++)
	{
		_button[i] = RectMake(24 + (i - 11) * 150 + (i - 11) * 24, 680, 150, 150);
	}

	for (int i = 0; i < UNITMANAGER->getParty().size(); ++i)
	{
		UNITMANAGER->getParty()[i]->changeState(CHARACTER_STATE_MENU);
	}

	banner = 0;
	_tap = 0;
	return S_OK;
}

void partyMenu::release()
{
}

void partyMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if(PtInRect(&_button[0], _ptMouse))
		{
			banner = 1;
		}
		for (int i = 1; i < 6; i++)
		{
			if (PtInRect(&_button[i], _ptMouse))
			{
				UNITMANAGER->setPT(i - 1);
			}
		}
		for (int i = 11; i < 15; i++)
		{
			if (PtInRect(&_button[i], _ptMouse))
			{
				_tap = i - 10;
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
			changetab(_tap + 6);
			_tap = 0;
		}
		else if (_menuSelect > 0)
		{
			changetab(_menuSelect);
			_menuSelect = 0;
		}
		else if (UNITMANAGER->getPT() >= 0)
		{
			changetab(11);
		}
	}
	
}

void partyMenu::render()
{
	_banner[banner]->render(0, 170);
	_party->render(0, 280);
	_buttons[_tap]->render(0, 680);
	
	
	for (int i = 1; i < 6; i++)
	{
		UNITMANAGER->getStand()->render(_button[i].left, _button[i].top);
		if (UNITMANAGER->getParty().size() < i)continue;
		UNITMANAGER->getParty()[i-1]->render(_button[i].left, _button[i].top);
	}
	_menu[_menuSelect]->render(0, WINSIZEY - IMAGEMANAGER->findDImage("menu")->getHeight());
}
