#include "stdafx.h"
#include "titleScene.h"

HRESULT titleScene::init()
{

	IMAGEMANAGER->addDImage("background_n", L"img/scene/background_n.png", 720, 1024);
	_screen = IMAGEMANAGER->addDImage("title", L"img/scene/title.png", 720, 1024);
	_layer = IMAGEMANAGER->addFrameDImage("playLayer", L"img/scene/titlelayer.png", 10140, 100, 20, 1);

	_maptool = RectMake(600, 22, 100, 45);


	_frameX = 0;
	_frameY = 0;
	_frameCount = 0;


	return S_OK;
}

void titleScene::release()
{
	CAMERAMANAGER->init(0,0);

}

void titleScene::update()
{
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if(PtInRect(&_maptool,_ptMouse))SCENEMANAGER->changeScene("maptool");
		else
		{
			SCENEMANAGER->changeScene("main");
			TXTDATA->loadGame();
		}
	}
	
	CAMERAMANAGER->updateScreen(0, 0);
	//if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))CAMERAMANAGER->updateScreen4(_ptMouse.x, _ptMouse.y);
	//if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))CAMERAMANAGER->setT(40);
	
	_frameCount+=TIMEMANAGER->getElapsedTime();
	if (_frameCount > 0.12)
	{	
		if (_frameX > _layer->getMaxFrameX())
			_frameX = 0;
		_frameX++;
		_frameCount = 0;
		
	}
	
}

void titleScene::render()
{
	
	D2D_RECT_F rc = dRectMake(635, 25, 300, 25);
	_screen->render(0, 0);
	_layer->frameRender(107, 700,_frameX,_frameY);
	DTDMANAGER->printText(L"¸Ê", rc);
}

