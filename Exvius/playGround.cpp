#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);
	//SCENEMANAGER->init();
	SCENEMANAGER->changeScene("title");
	
	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();

	
}


void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();
}


void playGround::render()
{
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	if (STREAMMANAGER->getCurrentVideo()) {
		if (STREAMMANAGER->getPosition() < STREAMMANAGER->getLength())
			return;
	}

	DTDMANAGER->beginDraw();
	//================제발 이 사이에 좀 그립시다==========================
	SCENEMANAGER->render();
	
	DTDMANAGER->endDraw();
	//TIMEMANAGER->render(getMemDC());
	//==================================================
	
	DTDMANAGER->render(0,0,WINSIZEX,WINSIZEY);
}


