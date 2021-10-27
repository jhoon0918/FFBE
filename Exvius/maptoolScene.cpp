#include "stdafx.h"
#include "maptoolScene.h"

HRESULT maptoolScene::init()
{
	_maptool = new mapTool;
	_maptool->init();
	return S_OK;
}

void maptoolScene::release()
{
}

void maptoolScene::update()
{
	_maptool->update();

}

void maptoolScene::render()
{
	_maptool->render();
}
