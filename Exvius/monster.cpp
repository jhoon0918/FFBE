#include "stdafx.h"
#include "monster.h"

HRESULT monster::init()
{
	_life = true;

	
	_alpha = 1.0;

	onDuty = true;
	
	turn = false;
	phase = false;
	pattern = true;

	return S_OK;
}

void monster::release()
{
}

void monster::update()
{
}

void monster::render(float x, float y)
{
	frameControl();
	_currentImage->frameRender(x, y, _frameX, _frameY, _alpha);
}

void monster::prender(float x, float y)
{
	patternControl();
	_currentPattern->frameRender(x, y, _framepX, _framepY);
}


void monster::frameControl()
{
	if (onDuty)
	{
		_frameCount += TIMEMANAGER->getElapsedTime();
		if (_frameCount > 0.12)
		{
			if (_frameX >= _currentImage->getMaxFrameX())
			{
				_frameX = 0;
			}
			else _frameX++;
			_frameCount = 0;
		}
	}
}

void monster::patternControl()
{
	if (pattern)
	{
		_framepCount += TIMEMANAGER->getElapsedTime();
		if (_frameCount > 0.12)
		{
			if (_framepX >= _currentPattern->getMaxFrameX())
			{
				_framepX = 0;
				pattern = false;
			}
			else _framepX++;
			_framepCount = 0;
		}
	}
}

void monster::changeState(MONSTER_STATE state)
{
	_state = state;
	_currentImage = _stateImage[_state];
	_frameX = 0;
	_frameCount = 0;
}

void monster::changePattern(MONSTER_PATTERN pattern)
{
	_pattern = pattern;
	_currentPattern = _patternImage[_pattern];
	_framepX = 0;
	_framepCount = 0;
}
