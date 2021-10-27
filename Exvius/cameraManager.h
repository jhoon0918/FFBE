#pragma once
#include "singletonBase.h"
#include "image.h"

#define FADE	300

enum CAMERAFADE {
	FADEOUT = -1,
	NORMAL,
	FADEIN,
	ENDFADE
};

class cameraManager : public singletonBase<cameraManager>
{
private:
	//ī�޶� ���ߴ� ȭ�� ũ��(WINSIZEX, WINSIZEY)�� ��ǥ(left, right, top, bottom)
	RECT _screen;

	int _backWidth, _backHeight;	//backDC ũ��
	int _frontWidth, _frontHeight;	//frontDC ũ��
	//fade
	dImage* _fadeScreen;
	float _alpha;
	CAMERAFADE _fade;

	//ī�޶� ������
	float _count;	//������ �� ����ϴ� count
	float _ratioX;	//�߽��� ��ġ ���� (x)
	float _ratioY;	//�߽��� ��ġ ���� (y)
	float _zoom;	//Ȯ����
	float _camY;	//ī�޶� �ø��� ������
	bool _onMove;	//ī�޶� �ø��� ������ �Ǻ�
	float t;
public:
	cameraManager();
	~cameraManager();

	HRESULT init(int width, int height);
	void release();

	//ī�޶� ��ġ(screen) ����
	void updateScreen(float standardX, float standardY);
	void updateScreen2(float standardX, float standardY);
	void updateScreen3(float standardX, float standardY, RECT rc);
	void updateScreen4(float standardX, float standardY);
	void moveCam(int direct);
	void resetCam();

	//FadeIN, FadeOUT
	void fade();
	void fadeIn();
	void fadeOut();

	//ī�޶� ����
	void vibrateScreen(float standardX, float standardY,
		float magnitude = 5.0f, float interval = 0);
	void vibrateScreenOut(float standardX, float standardY,
		float magnitude = 5.0f, float interval = 0);

	//ī�޶� ���
	void render(HDC frontDC, int destX, int destY, HDC backDC, int ver = 1);

	//ī�޶� ����ó��
	void onWindow(float& x, float& y);
	void onWindow2(float& x, float& y, float initX, float endX, float initY, float endY);

	void setBackScreenSize(float width, float height);

	//============ ������ ============//
	RECT getScreen() { return _screen; }

	//void setFrontScreenSize(float width, float height) { _frontWidth = width, _frontHeight = height; }
	float getBackScreenWidth() { return _backWidth; }
	float getBackScreenHeight() { return _backHeight; }

	float getAlpha() { return _alpha; }

	void setFade(CAMERAFADE fade) { _fade = fade; }
	CAMERAFADE getFade() { return _fade; }

	void setRatioX(float ratio) { _ratioX = ratio; }
	float getRatioX() { return _ratioX; }
	void setRatioY(float ratio) { _ratioY = ratio; }
	float getRatioY() { return _ratioY; }

	void setZoom(float zoom) { _zoom = zoom; }
	float getZoom() { return _zoom; }

	void setCamY(float count) { _camY = count; }
	float getCamY() { return _camY; }

	void setMove(bool b) { _onMove = b; }
	bool getMove() { return _onMove; }
	
	void setT(float T) { t = T; }
	float getT() { return t; }
};

