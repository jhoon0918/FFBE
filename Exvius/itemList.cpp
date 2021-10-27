#include "stdafx.h"
#include "itemList.h"

HRESULT itemList::init()
{
	_banner[0] = IMAGEMANAGER->addDImage("ILbanner", L"img/ui/equipMenu/itembanner.png", 720, 166);
	_banner[1] = IMAGEMANAGER->addDImage("ILbannertap", L"img/ui/equipMenu/itembannertap.png", 720, 166);

	_black = IMAGEMANAGER->findDImage("black");

	backsheet = RectMake(0, 400, 720, 480);
	_button = RectMake(10, 170, 120, 80);
	banner = 0;

	return S_OK;
}

void itemList::release()
{
}

void itemList::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		STORAGEMANAGER->setM(_ptMouse.y);
		if (PtInRect(&_button, _ptMouse))
		{
			banner = 1;
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
			changetab(banner+2);
			banner = 0;
		}
		else if (_menuSelect > 0)
		{
			changetab(_menuSelect);
			_menuSelect = 0;
		}
		if (!STORAGEMANAGER->getBack())STORAGEMANAGER->setBack(true);
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&backsheet, _ptMouse))
		{
			STORAGEMANAGER->setBack(false);
		}
	}
	STORAGEMANAGER->backon();

}

void itemList::render()
{
	WCHAR str[128];

	swprintf_s(str, L"%d / %d", STORAGEMANAGER->getCount(), STORAGEMANAGER->getLimit());
	
	STORAGEMANAGER->render();
	_banner[banner]->render(0, 120);
	_black->render(500, 784);
	DTDMANAGER->printText(str, 635, 833, 200, 100, 30);

	_menu[_menuSelect]->render(0, WINSIZEY - IMAGEMANAGER->findDImage("menu")->getHeight());
}
