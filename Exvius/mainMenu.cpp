#include "stdafx.h"
#include "mainMenu.h"

HRESULT mainMenu::init()
{
	
	_layer = IMAGEMANAGER->addDImage("layer", L"img/scene/mainlayer.png", 720, 330);
	_battle = IMAGEMANAGER->addDImage("battle1", L"img/battlebackground/ItemWorld.png", 720, 1024);
	_world[0]=IMAGEMANAGER->addDImage("worldI",L"img/battlebackground/world.png", 300, 252);
	_world[1] = IMAGEMANAGER->addDImage("worldIT", L"img/battlebackground/worldtap.png", 300, 252);
	_expedition[0]=IMAGEMANAGER->addDImage("expediI",L"img/battlebackground/expedition.png", 300, 219);
	_expedition[1]=IMAGEMANAGER->addDImage("expediIT",L"img/battlebackground/expeditiontap.png", 300, 219);

	int j = 0;
	int k = 0;

	for (int i = 0; i < 5; i++)
	{
		if (i / 2 > j)
		{
			j++;
			k += 2;
		}

		_party[i]= RectMake(450 + (i - k) * 130, 300 + 50 * j, 80, 70);
		_move[i] = RectMake(450 + (i - k) * 130, 300 + 50 * j, 80, 70);
	}

	_tap[0] = RectMake(20, 550, 300, 250);
	_tap[1] = RectMake(405, 583, 300, 217);
	_attack = RectMake(320, 350, 80, 70);

	ori = true;
	attack = false;
	box=6;

	wt = 0;
	et = 0;

	return S_OK;
}

void mainMenu::release()
{
}

void mainMenu::update()
{
	if (ori==true)
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
		for (int i = 0; i < 6; i++)
		{
			if (PtInRect(&_tab[i], _ptMouse))
			{
				_menuSelect = i + 1;
			}
		}
		if (PtInRect(&_tap[0], _ptMouse))
		{
			wt = 1;
		}
		else if (PtInRect(&_tap[1], _ptMouse))
		{
			et = 1;
		}
		for (int i = 0; i < UNITMANAGER->getParty().size(); i++)
		{
			if (!attack)
			{
				if (PtInRect(&_party[i], _ptMouse))
				{

					attack = true;
					box = i;
					UNITMANAGER->battleframe(CHARACTER_STATE_MOVE, i);
				}
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
		else if (wt > 0)
		{
			wt = 0;
			SCENEMANAGER->changeScene("battle");
		}
		else if (et > 0)
		{
			et = 0;
		}
	}
	if (box != 6)
	{
		boxmove(box);
	}
}

void mainMenu::render()
{
	
	_battle->render(0, 0, 0, 250, 720, 534);
	_layer->render(0, 534);

	_world[wt]->render(20, 550);
	_expedition[et]->render(405, 583);

	for (int i = 0; i < UNITMANAGER->getParty().size(); i++)
	{
		if (UNITMANAGER->getParty().size() < i)continue;
		if(UNITMANAGER->getParty()[i]->getState()==CHARACTER_STATE_IDLE)
		UNITMANAGER->battleframe(CHARACTER_STATE_IDLE,i);
		if (UNITMANAGER->getParty()[i]->getState() == CHARACTER_STATE_ATTACK)
		{
			UNITMANAGER->getParty()[i]->render(_move[i].left-UNITMANAGER->getParty()[i]->getImage()->getFrameWidth()/2, (_move[i].bottom - UNITMANAGER->getParty()[i]->getImage()->getHeight()));
		}
		else
		{
			UNITMANAGER->getParty()[i]->render(_move[i].left, (_move[i].bottom - UNITMANAGER->getParty()[i]->getImage()->getHeight()));
		}
	}
	
	_menu[_menuSelect]->render(0, WINSIZEY - IMAGEMANAGER->findDImage("menu")->getHeight());

	//for (int i = 0; i < 6; i++)
	//{
	//	DTDMANAGER->Rectangle(_party[i]);
	//	DTDMANAGER->Rectangle(_move[i]);
	//}
	//for(int i =0;i<2;i++)
	//{
	//	DTDMANAGER->Rectangle(_tap[i]);
	//}
	//DTDMANAGER->Rectangle(_attack);
}

void mainMenu::boxmove(int b)
{

		if (!UNITMANAGER->getParty()[b]->getPhase()&&UNITMANAGER->getParty()[b]->getTurn())
		{
			
			if (_move[b].left <= _attack.left) { _move[b].left = _attack.left; _move[b].right = _attack.right; }
			else
			{
				_move[b].left -= 3;
				_move[b].right -= 3;
			}
			if (b < 4)
			{
				if (_move[b].top >= _attack.top) { _move[b].bottom = _attack.bottom; _move[b].top = _attack.top; }
				else
				{
					if (b < 2)
					{
						_move[b].top += 1;
						_move[b].bottom += 1;
					}
					else if (2 <= b < 4)
					{
						_move[b].top == _attack.top;
						_move[b].bottom == _attack.bottom;
					}

				}
			}
			else
			{
				if (_move[b].top >= _attack.top)
				{
					_move[b].top -= 1;
					_move[b].bottom -= 1;
				}
				else if (_move[b].top <= _attack.top)
				{
					_move[b].bottom = _attack.bottom; _move[b].top = _attack.top;
				}
			}
		}
		if (_move[b].left == _attack.left&&_move[b].top == _attack.top && (UNITMANAGER->getParty()[b]->getTurn() == true))
		{
			UNITMANAGER->battleframe(CHARACTER_STATE_ATTACK, b, UNITMANAGER->getParty()[b]->getTurn());
			UNITMANAGER->getParty()[b]->setTurn(false);
		}
		else if (_move[b].left == _attack.left&&_move[b].top == _attack.top && UNITMANAGER->getParty()[b]->getState() == CHARACTER_STATE_IDLE)
		{
			UNITMANAGER->getParty()[b]->setPhase(true);
			UNITMANAGER->battleframe(CHARACTER_STATE_MOVE, b);
		}
		if (UNITMANAGER->getParty()[b]->getPhase())
		{
			if (_move[b].right >= _party[b].right) { _move[b].left = _party[b].left; _move[b].right = _party[b].right; }
			else
			{
				_move[b].left += 3;
				_move[b].right += 3;
			}
			if(b<4)
			{
				if (_move[b].top <= _party[b].top) { _move[b].bottom = _party[b].bottom; _move[b].top = _party[b].top; }
				else
				{
					if (b < 2)
					{
						_move[b].top -= 1;
						_move[b].bottom -= 1;
					}
					else if (2 <= b < 4)
					{
						_move[b].top == _attack.top;
						_move[b].bottom == _attack.bottom;
					}
				}
			}
			else
			{
				if (_move[b].top <= _party[b].top)
				{
					_move[b].top += 1;
					_move[b].bottom += 1;
				}
				else if (_move[b].top >= _attack.top)
				{
					_move[b].bottom = _attack.bottom; _move[b].top = _attack.top;
				}
			}
		}
		if (_move[b].left == _party[b].left&&_move[b].top == _party[b].top && (UNITMANAGER->getParty()[b]->getPhase() == true))
		{
			UNITMANAGER->getParty()[b]->setPhase(false);
			UNITMANAGER->getParty()[b]->changeState(CHARACTER_STATE_IDLE);
			attack = false;
		}
}
