#include "stdafx.h"
#include "battleScene.h"

HRESULT battleScene::init()
{
	background = IMAGEMANAGER->findDImage("background_n");
	battlebg = IMAGEMANAGER->addDImage("townback", L"img/battlebackground/town.png", 720, 1024);
	turn = IMAGEMANAGER->addDImage("turn", L"img/battlebackground/ео.png", 33, 36);
	numbers = IMAGEMANAGER->addFrameDImage("numbers", L"img/battlebackground/turnnumber.png", 24, 480,1,10);
	layer[0] = IMAGEMANAGER->addDImage("battletile", L"img/battlebackground/battletile.png", 350, 150);
	layer[1] = IMAGEMANAGER->addDImage("battlesteady", L"img/battlebackground/battlesteady.png", 350, 150);
	monsterHP= IMAGEMANAGER->addDImage("enemyHP", L"img/battlebackground/healthbaron.png", 572, 78);
	characterHP = IMAGEMANAGER->addDImage("characterHP", L"img/battlebackground/userHPbar.png", 261, 14);

	UI[0] = RectMake(600, 50, 33, 36);
	UI[1] = RectMake(650, 45, 24, 48);
	UI[2] = RectMake(0, 496, 572, 78);
	_mname = dRectMake(150, 480, 300, 50);
	
	
	int j = 0;
	int k = 0;
	for (int i = 0; i < 6; i++)
	{
		if (i / 2 > j)
		{
			j++;
			k += 2;
		}

		_playerStand[i] = RectMake(450 + (i - k) * 130, 300 + 50 * j, 80, 70);
		_playerMove[i] = RectMake(450 + (i - k) * 130, 300 + 50 * j, 80, 70);
		_enemyP[i] = RectMake(50 + (i - k) * 130, 300 + 50 * j, 80, 70);

	}
	j = 0;
	k = 0;
	for (int i = 0; i < 6; i++)
	{
		if (i / 2 > j)
		{
			j++;
			k += 2;
		}
		order[i] = false;
		_playerControl[i] = RectMake(10 + (i - k) * 350+ (i - k)*10, 574 + 150 * j, 350, 150);
		_port[i] = RectMake(30 + (i - k) * 350+ (i - k) * 10, 594 + 150 * j, 56, 38);
		_hp[i] = RectMake(80 + (i - k) * 350 + (i - k) * 10, 674 + 150 * j, 261, 14);
		_name[i] = dRectMake(120 + (i - k) * 350 + (i - k) * 10, 594 + 150 * j, 100, 50);
		_case[i] = dRectMake(250 + (i - k) * 350 + (i - k) * 10, 594 + 150 * j, 100, 50);
	}
	_playerAttack = RectMake(320, 350, 80, 70);
	
	box = 6;
	turnN = 1;
	ori = true;
	attack = false;
	return S_OK;
}

void battleScene::release()
{
}

void battleScene::update()
{
	if (ori == true)
	{
		for (int i = 0; i < UNITMANAGER->getParty().size(); ++i)
		{
			UNITMANAGER->getParty()[i]->changeState(CHARACTER_STATE_IDLE);
			if (i == UNITMANAGER->getParty().size() - 1)
			{
				ori = false;
				break;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		//for (int i = 0; i < 6; i++)
		//{
		//	if (PtInRect(&_tab[i], _ptMouse))
		//	{
		//		_menuSelect = i + 1;
		//	}
		//}
		//if (PtInRect(&_tap[0], _ptMouse))
		//{
		//	wt = 1;
		//}
		//else if (PtInRect(&_tap[1], _ptMouse))
		//{
		//	et = 1;
		//}
		for (int i = 0; i < UNITMANAGER->getParty().size(); i++)
		{
			if (!attack&&UNITMANAGER->getParty()[i]->getTurn()==true)
			{
				if (PtInRect(&_playerControl[i], _ptMouse))
				{
					attack = true;
					box = i;
					UNITMANAGER->battleframe(CHARACTER_STATE_MOVE, i);
				}
			}
		}
		for (int i = 0; i < MONSTERMANAGER->getVm().size(); i++)
		{
			if (PtInRect(&_enemyP[i], _ptMouse))
			{
				swprintf_s(tmp, L"%s", MONSTERMANAGER->getVm()[i]->getName().c_str());
			}
		}

	}
	if (box != 6)
	{
		boxmove(box);
	}
}

void battleScene::render()
{
	WCHAR str[128];
	background->render(0, 0);
	battlebg->render(0, 0, 0, 300, 720, 574);
	for (int i = 0; i < 6; i++)
	{
		layer[0]->render(_playerControl[i].left, _playerControl[i].top);

	}
	turn->render(UI[0].left, UI[0].top);
	numbers->frameRender(UI[1].left, UI[1].top, 0, turnN);

	for (int i = 0; i < MONSTERMANAGER->getVm().size(); i++)
	{
		MONSTERMANAGER->getVm()[i]->render(_enemyP[i].left, _enemyP[i].top);
		DTDMANAGER->Rectangle(_enemyP[i]);
	}
	for (int i = 0; i < UNITMANAGER->getParty().size(); i++)
	{
		DTDMANAGER->Rectangle(_playerStand[i]);
		DTDMANAGER->Rectangle(_playerMove[i]);
		if (UNITMANAGER->getParty().size() < i)continue;
		UNITMANAGER->getParty()[i]->getPortrait()->render(_port[i].left, _port[i].top);
		swprintf_s(str, L"%s", UNITMANAGER->getParty()[i]->getName().c_str());
		DTDMANAGER->printText(str, _name[i], 20);
		if (UNITMANAGER->getParty()[i]->getTurn())
		{
			swprintf_s(str, L"Able");
		}
		else
		{
			swprintf_s(str, L"Disable");
		}
		DTDMANAGER->printText(str, _case[i],15);
		
		characterHP->render(_hp[i].left, _hp[i].top);
		if (UNITMANAGER->getParty()[i]->getState() == CHARACTER_STATE_IDLE)
			UNITMANAGER->battleframe(CHARACTER_STATE_IDLE, i);
		if (UNITMANAGER->getParty()[i]->getState() == CHARACTER_STATE_ATTACK||CHARACTER_STATE_LB)
		{
			UNITMANAGER->getParty()[i]->render(_playerMove[i].left - UNITMANAGER->getParty()[i]->getImage()->getFrameWidth() / 2, (_playerMove[i].bottom - UNITMANAGER->getParty()[i]->getImage()->getHeight()));
		}
		else
		{
			UNITMANAGER->getParty()[i]->render(_playerMove[i].left, (_playerMove[i].bottom - UNITMANAGER->getParty()[i]->getImage()->getHeight()));
		}
	}
	DTDMANAGER->Rectangle(_playerAttack);
	monsterHP->render(UI[2].left, UI[2].top);
	DTDMANAGER->printText(tmp, _mname,30);
}


void battleScene::boxmove(int b)
{

	if (!UNITMANAGER->getParty()[b]->getPhase() && UNITMANAGER->getParty()[b]->getTurn())
	{

		if (_playerMove[b].left <= _playerAttack.left) { _playerMove[b].left = _playerAttack.left; _playerMove[b].right = _playerAttack.right; }
		else
		{
			_playerMove[b].left -= 3;
			_playerMove[b].right -= 3;
		}
		if (b < 4)
		{
			if (_playerMove[b].top >= _playerAttack.top) { _playerMove[b].bottom = _playerAttack.bottom; _playerMove[b].top = _playerAttack.top; }
			else
			{
				if (b < 2)
				{
					_playerMove[b].top += 1;
					_playerMove[b].bottom += 1;
				}
				else if (2 <= b < 4)
				{
					_playerMove[b].top == _playerAttack.top;
					_playerMove[b].bottom == _playerAttack.bottom;
				}

			}
		}
		else
		{
			if (_playerMove[b].top >= _playerAttack.top)
			{
				_playerMove[b].top -= 1;
				_playerMove[b].bottom -= 1;
			}
			else if (_playerMove[b].top <= _playerAttack.top)
			{
				_playerMove[b].bottom = _playerAttack.bottom; _playerMove[b].top = _playerAttack.top;
			}
		}
	}
	if (_playerMove[b].left == _playerAttack.left&&_playerMove[b].top == _playerAttack.top && (UNITMANAGER->getParty()[b]->getTurn() == true))
	{
		if(b<2)	UNITMANAGER->battleframe(CHARACTER_STATE_ATTACK, b, UNITMANAGER->getParty()[b]->getTurn());
		else UNITMANAGER->battleframe(CHARACTER_STATE_LB, b, UNITMANAGER->getParty()[b]->getTurn());
		UNITMANAGER->getParty()[b]->setTurn(false);
	}
	else if (_playerMove[b].left == _playerAttack.left&&_playerMove[b].top == _playerAttack.top && UNITMANAGER->getParty()[b]->getState() == CHARACTER_STATE_IDLE)
	{
		UNITMANAGER->getParty()[b]->setPhase(true);
		UNITMANAGER->battleframe(CHARACTER_STATE_MOVE, b);
	}
	if (UNITMANAGER->getParty()[b]->getPhase())
	{
		if (_playerMove[b].right >= _playerStand[b].right) { _playerMove[b].left = _playerStand[b].left; _playerMove[b].right = _playerStand[b].right; }
		else
		{
			_playerMove[b].left += 3;
			_playerMove[b].right += 3;
		}
		if (b < 4)
		{
			if (_playerMove[b].top <= _playerStand[b].top) { _playerMove[b].bottom = _playerStand[b].bottom; _playerMove[b].top = _playerStand[b].top; }
			else
			{
				if (b < 2)
				{
					_playerMove[b].top -= 1;
					_playerMove[b].bottom -= 1;
				}
				else if (2 <= b < 4)
				{
					_playerMove[b].top == _playerAttack.top;
					_playerMove[b].bottom == _playerAttack.bottom;
				}
			}
		}
		else
		{
			if (_playerMove[b].top <= _playerStand[b].top)
			{
				_playerMove[b].top += 1;
				_playerMove[b].bottom += 1;
			}
			else if (_playerMove[b].top >= _playerAttack.top)
			{
				_playerMove[b].bottom = _playerAttack.bottom; _playerMove[b].top = _playerAttack.top;
			}
		}
	}
	if (_playerMove[b].left == _playerStand[b].left&&_playerMove[b].top == _playerStand[b].top && (UNITMANAGER->getParty()[b]->getPhase() == true))
	{
		UNITMANAGER->getParty()[b]->setPhase(false);
		UNITMANAGER->getParty()[b]->changeState(CHARACTER_STATE_IDLE);
		attack = false;
	}
}