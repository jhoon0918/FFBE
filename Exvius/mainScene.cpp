#include "stdafx.h"
#include "mainScene.h"

HRESULT mainScene::init()
{
	UIMANAGER->changeMenu("main");
	
	


	_br = new broadsword;
	_br->init();
	
	
	
	_background = IMAGEMANAGER->findDImage("background_n");
	_userInfo = IMAGEMANAGER->addDImage("userinfo", L"img/scene/userInfo.png", 720, 120);

	gapm = 0;
	gapr = 0;
	money = CALCULATIONMANAGER->getMoney();
	rapis = CALCULATIONMANAGER->getRapis();

	return S_OK;
}

void mainScene::release()
{
}

void mainScene::update()
{
	money = CALCULATIONMANAGER->getMoney();
	rapis = CALCULATIONMANAGER->getRapis();
	UIMANAGER->update();
	//_ra->update();
	//_la->update();
	_br->update();
	
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		
	
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		
	}
	
	/*if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_ra->setPure( CALCULATIONMANAGER->statCalculation(_ra));
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		if ((_ra->getEquip()._ohsword == true) && (_br->getType() == L"ÇÑ¼Õ°Ë")&&(_ra->getLeft()==L"empty"))
		{
			_ra->setLeft(_br->getName());
			_ra->setReal(CALCULATIONMANAGER->sumCalculation(_ra, _br));
		}
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		if ((_ra->getLeft()) == _br->getName())
		{
			_ra->setLeft(L"empty");
			_ra->setReal(CALCULATIONMANAGER->substractCalculation(_ra, _br));
		}
	}
	*/
	
}

void mainScene::render()
{
	D2D_RECT_F rc = dRectMake(500, 700, 100, 100);
	WCHAR str[128];
	
	_background->render(0, 0);
	UIMANAGER->render();
	_userInfo->render(0, 0);
	
	for (int i = 0; i < 10; i++)
	{
		if(money>power(10,i))gapm = 30 + i * 32;
	}
	for (int i = 0; i < 10; i++)
	{
		if (rapis > power(10, i))gapr = 30 + i * 32;
	}


	swprintf_s(str, L"%d", money);
	DTDMANAGER->printText(str, 210, 3,gapm,0,30);
	swprintf_s(str, L"%d", rapis);
	DTDMANAGER->printText(str, 690, 3, gapr, 0, 30);
	
	
	
	//swprintf_s(str, L"hp: %d, mp: %d, att: %d, mag: %d def: %d, spr: %d", (int)_ra->getReal()._hp, (int)_ra->getReal()._mp, (int)_ra->getReal()._att, (int)_ra->getReal()._mag, (int)_ra->getReal()._def, (int)_ra->getReal()._spr);
	//DTDMANAGER->printText(str, 300, 400, 500, 500, 30);
	//swprintf_s(str, L"%d", (int)vc.size());
	//DTDMANAGER->printText(str, 500, 500, 500, 500, 30);
	

	
}
