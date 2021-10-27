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
	//backDC�� frontDCũ�� ����
	_backWidth = width;
	_backHeight = height;
	_frontWidth = WINSIZEX;
	_frontHeight = WINSIZEY;
	//ȭ�� Rect ����
	_screen = RectMake(0, 0, WINSIZEX, WINSIZEY);
	//fadeȭ��
	_fadeScreen = IMAGEMANAGER->addDImage("fade_B", L"img/fade_B.png",
		WINSIZEX, WINSIZEY);

	_alpha = 255;
	_fade = NORMAL;

	//������
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
	//�÷��̾� �������� ȭ��(_screen)����
	//playground.cpp�� update()���� ��� �������ָ� ��
	//�μ��� ������ �Ǵ� ��ü�� x, y��ǥ�� ����(����� player�� x, y)

	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow(x, y);
	//����
	_screen = RectMake(x, y, _frontWidth / _zoom, _frontHeight);
}

void cameraManager::updateScreen2(float standardX, float standardY)
{
	//�÷��̾� �������� ȭ��(_screen)����
	//playground.cpp�� update()���� ��� �������ָ� ��
	//�μ��� ������ �Ǵ� ��ü�� x, y��ǥ�� ����(����� player�� x, y)

	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow(x, y);
	//����
	_screen = RectMake(x, y, _frontWidth, _frontHeight);
}

void cameraManager::updateScreen3(float standardX, float standardY, RECT rc)
{
	//�÷��̾� �������� ȭ��(_screen)����
	//playground.cpp�� update()���� ��� �������ָ� ��
	//�μ��� ������ �Ǵ� ��ü�� x, y��ǥ�� ����(����� player�� x, y)

	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow2(x, y, rc.left, rc.right, rc.top, rc.bottom);
	//����
	_screen = RectMake(x, y, _frontWidth / _zoom, _frontHeight / _zoom);
}

void cameraManager::updateScreen4(float standardX, float standardY)
{
	//�÷��̾� �������� ȭ��(_screen)����
	//playground.cpp�� update()���� ��� �������ָ� ��
	//�μ��� ������ �Ǵ� ��ü�� x, y��ǥ�� ����(����� player�� x, y)
	
	if (TIMEMANAGER->getElapsedTime() > 0)
	{
		t++;
	}
	
	if (!_onMove)
		resetCam();

	float x = standardX;
	float y = standardY + _camY;

	onWindow(x, y);
	//����
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
	/********* �μ� ���� *********/ /*
	HDC frontDC: ���縦 ���� DC (������ �츮�� ���� ȭ��)
	int destX: �츮�� ���� ȭ�鿡�� ������� x��ǥ
	int destY: �츮�� ���� ȭ�鿡�� ������� y��ǥ
	HDC backDC: ������ �� DC (������ �츮�� �׸��� ȭ��)
	bool map: true�� ��ü�� ���, false�� �� ���
	bool mini: true�� �̴ϸ� ���, false�� �� ���
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


	//DC�������� ��Ӻ��縦 ����(ȭ�� ������ ����)
	BitBlt(
		frontDC,				//����޴� DC
		destX,					//����޴� ��ǥ(left)
		destY,					//����޴� ��ǥ(top)
		_frontWidth,			//����Ǵ� ����ũ��
		_frontHeight,			//����Ǵ� ����ũ��
		backDC,					//����Ǵ� DC
		_screen.left, _screen.top,	//����Ǵ� ������ǥ(left, top)
		SRCCOPY);				//�״�� �����ؿ���(���)

}

void cameraManager::onWindow(float & x, float & y)
{
	float width = _frontWidth / _zoom;
	float height = _frontHeight / _zoom;

	//X�� (��, ��)
	if (x - width * _ratioX < 0)
		x = 0;
	else if (x + width * (1 - _ratioX) > _backWidth)
		x = _backWidth - width;
	else
		x -= width * _ratioX;
	//Y�� (��, ��)
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

	//X�� (��, ��)
	if (x - width * _ratioX < initX)
		x = initX;
	else if (x + width * (1 - _ratioX) > endX)
		x = endX - width;
	else
		x -= width * _ratioX;
	//Y�� (��, ��)
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
