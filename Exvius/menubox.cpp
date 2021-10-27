#include "stdafx.h"
#include "menubox.h"

menubox::menubox()
{

	IMAGEMANAGER->addDImage("black", L"img/ui/characterMenu/black out.png", 180, 45);
	IMAGEMANAGER->addDImage("Ilayer", L"img/ui/equipMenu/itemlayer.png", 330, 86);
	_menu[0] = IMAGEMANAGER->addDImage("menu", L"img/scene/undertab.png", 720, 160);
	_menu[1] = IMAGEMANAGER->addDImage("tap1", L"img/scene/undertab1.png", 720, 160);
	_menu[2] = IMAGEMANAGER->addDImage("tap2", L"img/scene/undertab2.png", 720, 160);
	_menu[3] = IMAGEMANAGER->addDImage("tap3", L"img/scene/undertab3.png", 720, 160);
	_menu[4] = IMAGEMANAGER->addDImage("tap4", L"img/scene/undertab4.png", 720, 160);
	_menu[5] = IMAGEMANAGER->addDImage("tap5", L"img/scene/undertab5.png", 720, 160);
	_menu[6] = IMAGEMANAGER->addDImage("tap6", L"img/scene/undertab6.png", 720, 160);

	_tab[0] = RectMake(0, WINSIZEY - 120, 120, 120);
	_tab[1] = RectMake(120, WINSIZEY - 120, 120, 120);
	_tab[2] = RectMake(240, WINSIZEY - 120, 120, 120);
	_tab[3] = RectMake(360, WINSIZEY - 120, 120, 120);
	_tab[4] = RectMake(480, WINSIZEY - 120, 120, 120);
	_tab[5] = RectMake(600, WINSIZEY - 120, 120, 120);

	

	_menuSelect = 0;
}

menubox::~menubox()
{
}

void menubox::changetab(int number)
{
	switch (number)
	{
	//1~6번 기본 메뉴들
	case 1:
		UIMANAGER->changeMenu("main");
		break;
	case 2:
		UIMANAGER->changeMenu("party");
		break;
	case 3:
		UIMANAGER->changeMenu("itemset");
		break;
	case 4:
		break;
	case 5:
		UIMANAGER->changeMenu("gacha");
		break;
	case 6:
		break;
	//파생메뉴 시작 7~10 캐릭터 메뉴
	case 7:
		UIMANAGER->changeMenu("unitlist");
		break;
	case 8:
		UNITMANAGER->setSeller(true);
		UIMANAGER->changeMenu("unitlist");
		break;
	case 9:
		break;
	case 10:
		
		break;
	case 11:
		UNITMANAGER->setBuild(true);
		UIMANAGER->changeMenu("unitlist");

		break;
	case 12:
		UIMANAGER->changeMenu("itemlist");
		break;
	case 13:
		UIMANAGER->changeMenu("equiplist");
		break;
	default:
		break;
	}
}
