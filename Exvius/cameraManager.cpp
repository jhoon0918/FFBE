#include "stdafx.h"
#include "cameraManager.h"

cameraManager::cameraManager()
{
}

cameraManager::~cameraManager()
{
}

HRESULT cameraManager::init(int width, int height)
{
	//backDC와 frontDC크기 설정
	_backWidth = width;
	_backHeight = height;
	_frontWidth = WINSIZEX;
	_frontHeight = WINSIZEY;
	//화면 Rect 생성
	_screen = RectMake(0, 0, WINSIZEX, WINSIZEY);
	//fade화면
	_fadeScreen = IMAGEMANAGER->addDImage("fade_B", L"img/fade_B.png",
		WINSIZEX, WINSIZEY);

	_alpha = 255;
	_fade = NORMAL;

	//설정값
	_count = 0;
	_ratioX = 0.5;
	_ratioY = 0.5;
	_zoom = 2;
	_camY = 0;
	_onMove = false;
	t = 40;
	return S_OK;
}

void cameraManager::release()
{
}

void cameraManager::updateScreen(float standardX, float standardY)
{
	//플레이어 기준으로 화면(_screen)갱신
	//playground.cpp의 update()에서 계속 갱신해주면 됨
	//인수로 기준이 되는 객체의 x, y좌표를 받음(현재는 player의 x, y)

	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow(x, y);
	//갱신
	_screen = RectMake(x, y, _frontWidth / _zoom, _frontHeight);
}

void cameraManager::updateScreen2(float standardX, float standardY)
{
	//플레이어 기준으로 화면(_screen)갱신
	//playground.cpp의 update()에서 계속 갱신해주면 됨
	//인수로 기준이 되는 객체의 x, y좌표를 받음(현재는 player의 x, y)

	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow(x, y);
	//갱신
	_screen = RectMake(x, y, _frontWidth, _frontHeight);
}

void cameraManager::updateScreen3(float standardX, float standardY, RECT rc)
{
	//플레이어 기준으로 화면(_screen)갱신
	//playground.cpp의 update()에서 계속 갱신해주면 됨
	//인수로 기준이 되는 객체의 x, y좌표를 받음(현재는 player의 x, y)

	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow2(x, y, rc.left, rc.right, rc.top, rc.bottom);
	//갱신
	_screen = RectMake(x, y, _frontWidth / _zoom, _frontHeight / _zoom);
}

void cameraManager::updateScreen4(float standardX, float standardY)
{
	//플레이어 기준으로 화면(_screen)갱신
	//playground.cpp의 update()에서 계속 갱신해주면 됨
	//인수로 기준이 되는 객체의 x, y좌표를 받음(현재는 player의 x, y)
	
	if (TIMEMANAGER->getElapsedTime() > 0)
	{
		t++;
	}
	
	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow(x, y);
	//갱신
	_screen = RectMake(x, y, _frontWidth / (2*(t/40)), _frontHeight/(1*(t/30)));
}

void cameraManager::moveCam(int direct)
{
	_onMove = true;

	switch (direct) {
	case 2:	//UP
		_camY = _camY - 10 > -240 ? _camY - 10 : -240;
		break;
	case 3:	//DOWN
		_camY = _camY + 10 < 240 ? _camY + 10 : 240;
		break;
	default:
		break;
	}
}

void cameraManager::resetCam()
{
	if (_camY > 0)
		_camY = _camY - 40 > 0 ? _camY - 40 : 0;
	else if (_camY < 0)
		_camY = _camY + 40 < 0 ? _camY + 40 : 0;
}

void cameraManager::fade()
{
	if (_fade == FADEIN)		fadeIn();
	else if (_fade == FADEOUT)	fadeOut();
}


void cameraManager::fadeIn()
{
	_alpha -= FADE * TIMEMANAGER->getElapsedTime();
	if (_alpha < 0) _alpha = 0;

	if (_alpha == 0) _fade = NORMAL;

	D2D1_RECT_F dest = dRectMake(_screen.left, _screen.top, _frontWidth, _frontHeight);
	D2D1_RECT_F sour = dRectMake(0, 0, _fadeScreen->getWidth(), _fadeScreen->getHeight());
	DTDMANAGER->getRenderTarget()->DrawBitmap(_fadeScreen->getBitmap(), dest,
		_alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sour);
}

void cameraManager::fadeOut()
{
	_alpha += FADE * TIMEMANAGER->getElapsedTime();
	if (_alpha > 1.0) _alpha = 1.0;

	if (_alpha == 1.0) _fade = NORMAL;

	D2D1_RECT_F dest = dRectMake(_screen.left, _screen.top, _frontWidth, _frontHeight);
	D2D1_RECT_F sour = dRectMake(0, 0, _fadeScreen->getWidth(), _fadeScreen->getHeight());
	DTDMANAGER->getRenderTarget()->DrawBitmap(_fadeScreen->getBitmap(), dest,
		_alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sour);
}

void cameraManager::vibrateScreen(float standardX, float standardY, float magnitude, float interval)
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= interval) {
		updateScreen(standardX + RND->getFromFloatTo(-magnitude, magnitude),
			standardY + RND->getFromFloatTo(-magnitude, magnitude));
		_count = 0;
	}
}

void cameraManager::vibrateScreenOut(float standardX, float standardY, float magnitude, float interval)
{
	_count += TIMEMANAGER->getElapsedTime();
	if (_count >= interval) {
		float x = standardX;
		float y = standardY + _camY;

		onWindow(x, y);
		_screen = RectMake(x + RND->getFromFloatTo(-magnitude, magnitude),
			y + RND->getFromFloatTo(-magnitude, magnitude),
			_frontWidth, _frontHeight);
		_count = 0;
	}
}

void cameraManager::render(HDC frontDC, int destX, int destY, HDC backDC, int ver)
{
	/********* 인수 설명 *********/ /*
	HDC frontDC: 복사를 받을 DC (실제로 우리가 보는 화면)
	int destX: 우리가 보는 화면에서 출력해줄 x좌표
	int destY: 우리가 보는 화면에서 출력해줄 y좌표
	HDC backDC: 복사해 올 DC (실제로 우리가 그리는 화면)
	bool map: true면 전체맵 출력, false면 안 출력
	bool mini: true면 미니맵 출력, false면 안 출력
	*/


	if (_zoom != 1.0) {
		StretchBlt(
			backDC,
			_screen.left,
			_screen.top,
			_frontWidth,
			_frontHeight,
			backDC,
			_screen.left,
			_screen.top,
			_frontWidth / _zoom,
			_frontHeight / _zoom,
			SRCCOPY);
	}

	if (_fade == FADEIN)		fadeIn();
	else if (_fade == FADEOUT)	fadeOut();

#ifdef _DEBUG
	//PRINTMANAGER->print(backDC, 1700, 2000, "_fade : %d", _fade);
	//PRINTMANAGER->print(backDC, 1700, 2200, "_alpha : %f", _alpha);
#endif // _DEBUG


	//DC영역간의 고속복사를 해줌(화면 깜빡임 방지)
	BitBlt(
		frontDC,				//복사받는 DC
		destX,					//복사받는 좌표(left)
		destY,					//복사받는 좌표(top)
		_frontWidth,			//복사되는 가로크기
		_frontHeight,			//복사되는 세로크기
		backDC,					//복사되는 DC
		_screen.left, _screen.top,	//복사되는 시작좌표(left, top)
		SRCCOPY);				//그대로 복사해오기(모드)

}

void cameraManager::onWindow(float & x, float & y)
{
	float width = _frontWidth / _zoom;
	float height = _frontHeight / _zoom;

	//X축 (좌, 우)
	if (x - width * _ratioX < 0)
		x = 0;
	else if (x + width * (1 - _ratioX) > _backWidth)
		x = _backWidth - width;
	else
		x -= width * _ratioX;
	//Y축 (상, 하)
	if (y - height * _ratioY < 0)
		y = 0;
	else if (y + height * (1 - _ratioY) > _backHeight)
		y = _backHeight - height;
	else
		y -= height * _ratioY;
}

void cameraManager::onWindow2(float & x, float & y, float initX, float endX, float initY, float endY)
{
	float width = _frontWidth / _zoom;
	float height = _frontHeight / _zoom;

	//X축 (좌, 우)
	if (x - width * _ratioX < initX)
		x = initX;
	else if (x + width * (1 - _ratioX) > endX)
		x = endX - width;
	else
		x -= width * _ratioX;
	//Y축 (상, 하)
	if (y - height * _ratioY < initY)
		y = initY;
	else if (y + height * (1 - _ratioY) > endY)
		y = endY - height;
	else
		y -= height * _ratioY;
}

void cameraManager::setBackScreenSize(float width, float height)
{
	_backWidth = width, _backHeight = height;
	
	DTDMANAGER->setBackBuffer(width, height);
}
