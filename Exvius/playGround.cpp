#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);
	//SCENEMANAGER->init();
	SCENEMANAGER->changeScene("title");
	
	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
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
	//================���� �� ���̿� �� �׸��ô�==========================
	SCENEMANAGER->render();
	
	DTDMANAGER->endDraw();
	//TIMEMANAGER->render(getMemDC());
	//==================================================
	
	DTDMANAGER->render(0,0,WINSIZEX,WINSIZEY);
}


