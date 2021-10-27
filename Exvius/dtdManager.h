#pragma once
#include "singletonBase.h"

class dtdManager : public singletonBase<dtdManager>
{
private:
	//Factory, RenderTarget
	ID2D1Factory			*_dFactory;
	ID2D1HwndRenderTarget	*_dRenderTarget;
	ID2D1BitmapRenderTarget	*_dBitRenderTarget;
	ID2D1Bitmap				*_dBitmap;

	//Brush
	ID2D1BitmapBrush		*_dBitmapBrush;
	ID2D1SolidColorBrush	*_dBrush;

	//Text
	IDWriteFactory			*_dWFactory;
	IDWriteTextFormat		*_dWFormat;
	IDWriteTextFormat		*_dWCustomFormat;
	ID2D1SolidColorBrush	*_tBrush;

	bool _clear;

public:
	HRESULT init();
	void release();
	void render(float destX, float destY, float width, float height);

	void beginDraw();
	void endDraw();

	//�簢��
	void Rectangle(D2D1_RECT_F rc);
	void Rectangle(RECT rc);

	//�ؽ�Ʈ ���(front)
	void printTextF(LPCWCHAR text, float x, float y, int width, int height);
	void printTextF(LPCWCHAR text, float x, float y, int width, int height, float size);
	void printTextF(LPCWCHAR text, D2D1_RECT_F rc);
	void printTextF(LPCWCHAR text, D2D1_RECT_F rc, float size);

	//�ؽ�Ʈ ���(backBuffer)
	void printText(LPCWCHAR text, float x, float y, int width, int height);
	void printText(LPCWCHAR text, float x, float y, int width, int height, float size);
	void printText(LPCWCHAR text, D2D1_RECT_F rc);
	void printText(LPCWCHAR text, D2D1_RECT_F rc, float size);


	//���� ��ȯ
	void setRotate(float angle, float x, float y);					//ȸ��
	void setReverse(int axis, float x, float y);					//����
	void setScale(float sizeX, float sizeY, float x, float y);		//ũ������
	//����
	void resetTransform();

	//����� ������ �缳��
	void setBackBuffer(float width, float height);

	void resetBrushColor();
	D2D1_COLOR_F getBrushColor() { return _dBrush->GetColor(); }
	void setBrushColor(D2D1_COLOR_F color) { _dBrush->SetColor(color); }

	ID2D1SolidColorBrush* getBrush() { return _dBrush; }

	void setRenderTarget(ID2D1HwndRenderTarget	*_dRENDERTarget) { _dRenderTarget = _dRENDERTarget; }
	ID2D1HwndRenderTarget* getRenderTarget() { return _dRenderTarget; }
	ID2D1BitmapRenderTarget* getBitRenderTarget() { return _dBitRenderTarget; }

	void setClear(bool clear) { _clear = clear; }
	bool getClear() { return _clear; }
};

