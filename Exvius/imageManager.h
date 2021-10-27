#pragma once
#include "singletonBase.h"
#include "image.h"
#include "dImage.h"
#include <map>

class imageManager : public singletonBase<imageManager>
{
private:
	//first - string
	//second - image*
	typedef map<string, image*>				mapImageList;
	typedef map<string, image*>::iterator	mapImageIter;

	typedef map<string, dImage*>			d2dImageList;
	typedef map<string, dImage*>::iterator	d2dImageIter;

private:
	mapImageList _mImageList;
	d2dImageList _dImageList;

	int _width;
	int _height;

public:
	imageManager();
	~imageManager();

	HRESULT init();
	void release();

	image* addImage(string strKey, int width, int height);
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor, bool blend);

	dImage* addDImage(string strKey, LPCWSTR fileName, int width, int height);

	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor, bool blend);

	dImage* addFrameDImage(string strKey, LPCWSTR fileName, int width, int height, int frameX, int frameY);

	image* findImage(string strKey);
	dImage* findDImage(string strKey);

	BOOL deleteImage(string strKey);
	BOOL deleteDImage(string strKey);

	BOOL deleteAll();

	//void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);
	
	void setWidth(int Width) { _width = Width; }
	void setHeight(int Height) { _height = Height; }
	
};

