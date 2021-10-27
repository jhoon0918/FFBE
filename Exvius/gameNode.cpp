#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{
	_managerInit = false;

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_managerInit = managerInit;

	if (_managerInit)
	{
		
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		SCENEMANAGER->init();
		SOUNDMANAGER->init();
		TXTDATA->init();
		STREAMMANAGER->init();
		DTDMANAGER->init();
		CAMERAMANAGER->init(WINSIZEX,WINSIZEY);
		CALCULATIONMANAGER->init();
		
		UIMANAGER->init();
		EQUIPMENTMANAGER->init();
		
		SHOPMANAGER 	->init();
		STORAGEMANAGER	->init();
		UNITCODEX 		->init();
		UNITMANAGER		->init();
		ITEMCODEX		->init();
		EQUIPCODEX		->init();
		MONSTERCODEX	->init();
		MONSTERMANAGER->init();

	}

	return S_OK;
}

void gameNode::release()
{
	if (_managerInit)
	{
		
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();

		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();

		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();


		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();

		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
		
		TXTDATA->release();
		TXTDATA->releaseSingleton();

		STREAMMANAGER->release();
		STREAMMANAGER->releaseSingleton();

		DTDMANAGER->release();
		DTDMANAGER->releaseSingleton();

		CAMERAMANAGER->release();
		CAMERAMANAGER->releaseSingleton();

		CALCULATIONMANAGER->release();
		CALCULATIONMANAGER->releaseSingleton();

		EQUIPMENTMANAGER->release();
		EQUIPMENTMANAGER->releaseSingleton();

		MONSTERMANAGER->release();
		MONSTERMANAGER->releaseSingleton();
		
		SHOPMANAGER->release();
		SHOPMANAGER->releaseSingleton();
		
		STORAGEMANAGER->release();
		STORAGEMANAGER->releaseSingleton();
		
		UIMANAGER->release();
		UIMANAGER->releaseSingleton();
		
		UNITCODEX->release();
		UNITCODEX->releaseSingleton();
		
		UNITMANAGER->release();
		UNITMANAGER->releaseSingleton();
		
		ITEMCODEX->release();
		ITEMCODEX->releaseSingleton();
		
		EQUIPCODEX->release();
		EQUIPCODEX->releaseSingleton();

		MONSTERCODEX->release();
		MONSTERCODEX->releaseSingleton();

		CoUninitialize();
	}
}

void gameNode::update()
{
	
}

void gameNode::render()
{
}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC         hdc; //얘 찐 중요합니...


	switch (iMessage)
	{
	
		//마우스 움직이면 여기서 메세지 발생
	case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>(LOWORD(lParam));
			_ptMouse.y = static_cast<float>(HIWORD(lParam));


	break;
			
	case WM_KEYDOWN:

		switch (wParam)
		{
			case VK_ESCAPE:
				PostQuitMessage(0);
			break;
		}
	break;


			//윈도우 창 부쉬는(?) 
	case WM_DESTROY:
		//윈도우 종료함수
			PostQuitMessage(0);
	return 0;
	}


	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	
}
