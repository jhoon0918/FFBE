#include "stdafx.h"
#include "character.h"

HRESULT character::init()
{
	_life = true;
	_equip._axe = false;
	_equip._blade = false;
	_equip._bow = false;
	_equip._dagger = false;
	_equip._gun = false;
	_equip._hammer = false;
	_equip._harp = false;
	_equip._lance = false;
	_equip._mace = false;
	_equip._nuckle = false;
	_equip._ohsword = false;
	_equip._ram = false;
	_equip._rod = false;
	_equip._staff = false;
	_equip._thsword = false;
	_equip._whip = false;
	
	_lefthand = L" ";
	_righthand = L" ";
	_head = L" ";
	_body = L" ";
	_acc1 = L" ";
	_acc2 = L" ";
	
	onDuty = true;

	turn = true;
	phase = false;

	return S_OK;
}

void character::release()
{
}

void character::update()
{

}

void character::render(float  x,float y)
{
	frameControl();
	_currentImage->frameRender(x, y, _frameX, _frameY);
}

void character::frameControl()
{
	if (onDuty)
	{
		_frameCount += TIMEMANAGER->getElapsedTime();
		if (_frameCount > 0.12)
		{
			if (_frameX >= _currentImage->getMaxFrameX() && (_state == CHARACTER_STATE_LB || _state == CHARACTER_STATE_ATTACK || _state == CHARACTER_STATE_VICTORY))
			{
				_frameX = 0;
				changeState(CHARACTER_STATE_IDLE);
			}
			else if (_frameX >= _currentImage->getMaxFrameX() && !(_state == CHARACTER_STATE_LB || _state == CHARACTER_STATE_ATTACK || _state == CHARACTER_STATE_VICTORY))
			{
				_frameX = 0;
			}
			else if (_state == CHARACTER_STATE_DEAD || _state == CHARACTER_STATE_DYING || _state == CHARACTER_STATE_MENU)
			{
				_frameX = 0;
			}
			else _frameX++;
			_frameCount = 0;

		}
	}
}

void character::changeState(CHARACTER_STATE state)
{
	_state = state;
	_currentImage = _stateImage[_state];
	_frameX = 0;
	_frameCount = 0;

}

