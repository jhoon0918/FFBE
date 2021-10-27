#include "stdafx.h"
#include "unitManager.h"

HRESULT unitManager::init()
{
	_stand = IMAGEMANAGER->addDImage("withstand", L"img/scene/characterStand.png", 80, 70);
	_selling[0] = IMAGEMANAGER->addDImage("sell tab", L"img/ui/characterMenu/selling tab.png", 720, 180);
	_selling[1] = IMAGEMANAGER->addDImage("sell tap", L"img/ui/characterMenu/selling tap.png", 720, 180);
	_selling[2] = IMAGEMANAGER->addDImage("reset tap", L"img/ui/characterMenu/selling reset.png", 720, 180);

	_sell[0] = RectMake(255, 765, 210, 85);
	_sell[1] = RectMake(510, 780, 165, 60);


	//À¯´Ö ÆÇ¸Å »¡°£ Å¥ºê
	_cube = IMAGEMANAGER->addDImage("cube", L"img/ui/characterMenu/redcube.png", 48, 36);

	sell = 0;
	_selector = 0;
	tmp = _selector;
	m = 0;
	

	_back = true;

	
	

	_position = true;
	_unitcount = 0;
	_limit = 0;
	ml = 0;
	pt = -1;
	_seller = false;
	_build = false;
	return S_OK;
}

void unitManager::release()
{
}

void unitManager::update()
{
	for (int i = 0; i < party.size(); i++)
	{
		party[i]->update();
	}

}

void unitManager::render()
{
	WCHAR str[128];
	
	if (tmp != _selector)
	{
		merlist.clear();
		ml = 0;
		gain = 0;
		tmp = _selector;
	}
	

	if (_selector == 0)
	{
		if(_position)
		{
			position();
			_position = false;
		}
		
		_unitcount = vc.size();
		_limit = 100;
		for (int i = 0; i < vc.size(); i++)
		{
			_stand->render(standR[i].left, standR[i].top);
			vc[i]->render(standR[i].left + 5, (standR[i].bottom - 20 - (vc[i]->getImage()->getHeight())));
		}
		
	}
	else if (_selector == 1)
	{
		if (_position)
		{
			position();
			_position = false;
		}
		_unitcount = vc2.size();
		_limit = 50;
		for (int i = 0; i < vc2.size(); i++)
		{
			_stand->render(standR[i].left, standR[i].top);
			vc2[i]->render(standR[i].left + 5, (standR[i].bottom - 20 - (vc2[i]->getImage()->getHeight())));
		}
		
	}
	else if (_selector == 2)
	{
		if (_position)
		{
			position();
			_position = false;
		}
		_unitcount = all.size();
		_limit = 150;

		for (int i = 0; i < all.size(); i++)
		{
			_stand->render(standR[i].left, standR[i].top);
			all[i]->render(standR[i].left + 5, (standR[i].bottom - 20 - (all[i]->getImage()->getHeight())));
		}
	}
	if (_seller&&_selector!=2)
	{
		_selling[sell]->render(0, 684);
		for (int i = 0; i < 2; i++)
		{
			DTDMANAGER->Rectangle(_sell[i]);
		}
		for (int i = 0; i < merlist.size(); i++)
		{

			DTDMANAGER->Rectangle(merchant[i]);
			_cube->render(merchant[i].left, merchant[i].top);
			swprintf_s(str, L"%d", i + 1);
			DTDMANAGER->printText(str, (merchant[i].left + merchant[i].right) / 2 + 18, (merchant[i].top + merchant[i].bottom) / 2, 48, 36, 18);
			swprintf_s(str, L"%d", ml);
			DTDMANAGER->printText(str, 350, 720, 200, 50, 30);
			swprintf_s(str, L"%d", gain);

			DTDMANAGER->printText(str, 600, 720, 200, 50, 30);
		}
	}
}

void unitManager::render(int x, int y, int i)
{
	_stand->render(x+10, y);
	gacha[i]->render(x + 15, (y+50-gacha[i]->getImage()->getHeight()));
}




void unitManager::selling()
{
	
	if (PtInRect(&_sell[0], _ptMouse))
	{
		int p = 0;
		sell = 1;
		if (_selector == 0)
		{
			for (int i = 0; i <= vc.size() + p; i++)
			{
				if (merlist.find(i) != merlist.end())
				{
					vc.erase(vc.begin() + (i - p));
					p++;
				}
			}
		}
		else if (_selector == 1)
		{
			for (int i = 0; i <= vc2.size() + p; i++)
			{
				if (merlist.find(i) != merlist.end())
				{
					vc2.erase(vc2.begin() + (i - p));
					p++;
				}
			}
		}

		CALCULATIONMANAGER->setMoney(CALCULATIONMANAGER->getMoney() + gain);
		merlist.clear();
		ml = 0;
		gain = 0;
		TXTDATA->saveGame();
		loadA();
	}

	else if (PtInRect(&_sell[1], _ptMouse))
	{
		sell = 2;
		merlist.clear();
		ml = 0;
		gain = 0;
	}

	if (_selector == 0)
	{
		for (int i = 0; i < vc.size(); i++)
		{
			if (PtInRect(&standR[i], _ptMouse))
			{
				if (merlist.find(i) == merlist.end())
				{
					merlist.insert(make_pair(i, ml));
					merchant[ml] = RectMake(standR[i].left, standR[i].bottom - 36, 48, 36);

					gain = gain + vc[i]->getPrice();
					ml++;
				}
			}
		}
	}
	else if (_selector == 1)
	{
		for (int i = 0; i < vc2.size(); i++)
		{
			if (PtInRect(&standR[i], _ptMouse))
			{
				if (merlist.find(i) == merlist.end())
				{
					merlist.insert(make_pair(i, ml));
					merchant[ml] = RectMake(standR[i].left, standR[i].bottom - 36, 48, 36);

					gain = gain + vc2[i]->getPrice();
					ml++;
				}
			}
		}
	}
	else
	{
		merlist.clear();
		ml = 0;
		gain = 0;
	}

}
void unitManager::backon()
{
	if (_back)
	{
		for (int i = 0; i < all.size(); i++)
		{
			if (standR[0].top > 400) { standR[i].bottom -= 1; standR[i].top -= 1; merchant[i].bottom -= 1; merchant[i].top -= 1;}
			else if (standR[all.size() - 1].bottom <= 850) { standR[i].bottom += 1; standR[i].top += 1; merchant[i].bottom += 1; merchant[i].top += 1;}
		}
	}
	else if (!_back)
	{
		for (int i = 0; i < all.size(); i++)
		{
			if (_ptMouse.y < m&&standR[0].top < 500) { standR[i].bottom += 3; standR[i].top += 3;  merchant[i].bottom += 3; merchant[i].top += 3;}
			if (_ptMouse.y > m && (standR[all.size() - 1].bottom > 700)) { standR[i].bottom -= 3; standR[i].top -= 3; merchant[i].bottom -= 3; merchant[i].top -= 3;}
		}
	}
}

void unitManager::loadC(character* c)
{
	c->init();
	vc.push_back(c);
}

void unitManager::loadM(character* m)
{
	m->init();
	vc2.push_back(m);
}

void unitManager::loadP(character * p)
{
	p->init();
	party.push_back(p);
}

void unitManager::loadA()
{
	int j = 0;
	all.clear();
	for (int i = 0; i < (vc.size() + vc2.size()); i++)
	{
		if (i < vc.size())j = vc[i]->getNum();
		else j = vc2[i-vc.size()]->getNum();
		ch=UNITCODEX->makeUnit(j);
		ch->init();
		all.push_back(ch);
	}
}

void unitManager::position()
{
	int j = 0;
	int k = 0;
	for (int i = 0; i < all.size(); i++)
	{

		if (i / 5 > j)
		{
			j++;
			k += 5;
		}

		standR[i] = RectMake(60 + (i - k) * 130, 400 + 120 * j, 80, 70);
	}
}

void unitManager::buildP()
{
	if (_selector == 0)
	{
		for (int i = 0; i < vc.size(); i++)
		{
			if (PtInRect(&standR[i], _ptMouse))
			{
				if (party.size()>pt&&party[pt] != NULL) 
				{ party.erase(party.begin() + pt); }
				
				party.push_back(vc[i]);
				pt = -1;
				UIMANAGER->changeMenu("party");
				TXTDATA->saveGame();
			}
		}
		
	}
	else if (_selector == 1)
	{
		for (int i = 0; i < vc2.size(); i++)
		{
			if (PtInRect(&standR[i], _ptMouse))
			{
				if (party.size() > pt&&party[pt] != NULL)
				{
					party.erase(party.begin() + pt);
				}

				party.push_back(vc2[i]);

				pt = -1;
				UIMANAGER->changeMenu("party");
				TXTDATA->saveGame();
			}
		}
	}
	else if (party.size() > 5)
	{
		party.clear();
	}
	else
	{
		pt = -1;
	}
}

void unitManager::battleframe(CHARACTER_STATE state, int number, bool continuous)
{
	
	if (!continuous&&state!=shift)
	{
		shift = state;
		party[number]->changeState(state);
		if (party[number]->getImage()->getMaxFrameX() == party[number]->getFrameX())
		{
			party[number]->setFrameX(0);
		}
	}
	else if(continuous)
	{
		party[number]->changeState(state);
		
	}
	
}

void unitManager::attackMove(int b, int moveX, int moveX1, int moveY, int moveY1, int placeX, int placeX1, int placeY, int placeY1, int returnX, int returnX1, int returnY, int returnY1)
{
		if (!party[b]->getPhase() && party[b]->getTurn())
		{

			if (moveX <= placeX) { moveX = placeX; moveX1 = placeX1; }
			else
			{
				moveX -= 1;
				moveX1 -= 1;
			}
			if (b < 4)
			{
				if (moveY >= placeY) { moveY1 = placeY1; moveY = placeY; }
				else
				{
					if (b < 2)
					{
						moveY += 1;
						moveY1 += 1;
					}
					else if (2 <= b < 4)
					{
						moveY == placeY;
						moveY1 == placeY1;
					}

				}
			}
			else
			{
				if (moveY >= placeY)
				{
					moveY -= 1;
					moveY1 -= 1;
				}
				else if (moveY <= placeY)
				{
					moveY1 = placeY1; moveY = placeY;
				}
			}
		}
		else if (moveX == placeX&& moveY == placeY && party[b]->getTurn() == true)
		{
			battleframe(CHARACTER_STATE_ATTACK, b, party[b]->getTurn());
			party[b]->setTurn(false);
		}
		else if (moveX == placeX&&moveY == placeY && party[b]->getState() == CHARACTER_STATE_IDLE)
		{
			party[b]->setPhase(true);
			battleframe(CHARACTER_STATE_MOVE, b);
		}
		else if (party[b]->getPhase())
		{
			if (moveX1 >= returnX1) { moveX = returnX; moveX1 = returnX1; }
			else
			{
				moveX += 1;
				moveX1 += 1;
			}
			if (moveY <= returnY) { moveY1 = returnY1; moveY = returnY; }
			else
			{
				if (b < 2)
				{
					moveY -= 1;
					moveY1 -= 1;
				}
				else if (2 <= b < 4)
				{
					moveY == placeY;
					moveY1 == placeY1;
				}
				else if (4 <= b < 6)
				{
					moveY += 1;
					moveY1 += 1;
				}
			}
		}
		else if (moveX == returnX&&moveY == returnY && party[b]->getPhase() == true)
		{
			party[b]->setPhase(false);
			party[b]->changeState(CHARACTER_STATE_IDLE);
			attack = false;
		}

}

void unitManager::gachaOn(character* g)
{
	g->init();
	gacha.push_back(g);
	vc.push_back(g);
	TXTDATA->saveGame();
	loadA();
}

void unitManager::gachaFinish()
{
	gacha.clear();
}

