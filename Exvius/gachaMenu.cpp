#include "stdafx.h"
#include "gachaMenu.h"

HRESULT gachaMenu::init()
{
	gachabg= IMAGEMANAGER->addDImage("gachabg", L"img/ui/gacha/gachabackground.png", 720, 1024);
	_gbanner = IMAGEMANAGER->addDImage("gachab", L"img/ui/gacha/gachabanner.png", 620, 360);
	_gacha1[0]=IMAGEMANAGER->addDImage("gacha1", L"img/ui/gacha/gacha.png", 275, 115);
	_gacha1[1] = IMAGEMANAGER->addDImage("gacha1tap", L"img/ui/gacha/gachatap.png", 275, 115);

	_gacha2[0] = IMAGEMANAGER->addDImage("gacha2", L"img/ui/gacha/11gacha.png", 275, 115);
	_gacha2[1] = IMAGEMANAGER->addDImage("gacha2tap", L"img/ui/gacha/11gachatap.png", 275, 115);

	summonbg= IMAGEMANAGER->addDImage("summonbg", L"img/ui/gacha/summonbg.png", 720, 584);

	_next[0] = IMAGEMANAGER->addDImage("next", L"img/ui/gacha/next.png", 200, 100);
	_next[1] = IMAGEMANAGER->addDImage("nexttap", L"img/ui/gacha/nexttap.png", 200, 100);

	star[0] = IMAGEMANAGER->addFrameDImage("3star", L"img/ui/gacha/3star.png", 800, 135, 8, 1);
	star[1] = IMAGEMANAGER->addFrameDImage("4star", L"img/ui/gacha/4star.png", 800, 135, 8, 1);
	star[2] = IMAGEMANAGER->addFrameDImage("5star", L"img/ui/gacha/5star.png", 800, 135, 8, 1);


	next = RectMake(260, 700, 200, 100);
	_gtap[0] = RectMake(50, 700, 275, 115);
	_gtap[1] = RectMake(395, 700, 275, 115);

	g1 = 0;
	g2 = 0;
	n = 0;
	h = 0;
	nl = 0;
	alpha = 0;
	count = 0;

	summon = false;
	video = false;
	done = false;
	open = false;
	vd = dRectMake(0, 0, 720, 1024);
	return S_OK;
}

void gachaMenu::release()
{
}

void gachaMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 6; i++)
		{
			if (PtInRect(&_tab[i], _ptMouse))
			{
				_menuSelect = i + 1;
			}
		}
		if (!summon)
		{
			if (PtInRect(&_gtap[0], _ptMouse))
			{
				g1 = 1;
			}
			else if (PtInRect(&_gtap[1], _ptMouse))
			{
				g2 = 1;
			}
		}
		if (summon)
		{
			if (!open)open = true;
			if (PtInRect(&next, _ptMouse))
			{
				n = 1;
			}
		}

	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		if (_menuSelect > 0)
		{
			changetab(_menuSelect);
			_menuSelect = 0;
		}
		if (g1 > 0)
		{
			video = true;
		}
		else if (g2 > 0)
		{
			video = true;
		}
		if (n > 0)
		{
			n = 0;
			h = 0;
			nl = 0;
			summon = false;
			done = false;
			
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (STREAMMANAGER->getCurrentVideo() != NULL)
		{
			STREAMMANAGER->closeVideo();
			summon = true;
			video = false;
		}
	}
	if (video&&(g1>0||g2>0))
	{
		open = false;
		alpha = 0;
		UNITMANAGER->gachaFinish();
		g1=0;
		g2=0;
		STREAMMANAGER->startVideo("gacha",vd);

		if (STREAMMANAGER->getPosition() >= STREAMMANAGER->getLength())
		{
			
			STREAMMANAGER->closeVideo();
			summon = true;
			video = false;
		}
		
	}
	
	else if (summon)
	{
		int characN = 0;
		if (!done)
		{
			for (int i = 0; i < 11; i++)
			{
				if (i % 5 == 0 && i != 0)
				{
					h++; nl += 5;
				}
				characN = RND->getFromIntTo(1, UNITCODEX->getIndex()+1);
				UNITMANAGER->gachaOn(UNITCODEX->makeUnit(characN));
				if (UNITMANAGER->getGacha()[i]->getStar() == 3)
				{
					gachaN[i] = 0;
				}
				else if (UNITMANAGER->getGacha()[i]->getStar() == 4)
				{
					gachaN[i] = 1;
				}
				else if (UNITMANAGER->getGacha()[i]->getStar() == 5)
				{
					gachaN[i] = 2;
				}
				_gacha[i] = RectMake(20 + (i - nl) * 145, 300 + h * 135, 100, 135);
			}
		}
		done = true;
		if(open)
		crystalcontrol();
	}
	
	
}

void gachaMenu::render()
{
	WCHAR str[128];

	
	gachabg->render(0, 0);

	if(!summon)
	{ 
		_gbanner->render(50, 250);
		_gacha1[g1]->render(_gtap[0].left, _gtap[0].top);
		_gacha2[g2]->render(_gtap[1].left, _gtap[1].top);
	}
	if (summon)
	{
		
		summonbg->render(0, 280);
		for (int i = 0; i < 11; i++)
		{
			UNITMANAGER->render(_gacha[i].left, _gacha[i].top + 50, i);
			DTDMANAGER->Rectangle(_gacha[i]);
			star[gachaN[i]]->frameRender(_gacha[i].left, _gacha[i].top, alpha, 0);
			
		}
		if(open)
		_next[n]->render(next.left, next.top);
	}
	
	_menu[_menuSelect]->render(0, WINSIZEY - IMAGEMANAGER->findDImage("menu")->getHeight());
}

void gachaMenu::crystalcontrol()
{
	count += TIMEMANAGER->getElapsedTime();
	if (count >0.1)
	{
		if (alpha > star[0]->getMaxFrameX())
			alpha = star[0]->getMaxFrameX() + 1;
		else alpha++;
		count = 0;
	}
	
}
