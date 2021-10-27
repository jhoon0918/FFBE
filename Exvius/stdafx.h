#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

//d2d lib
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "WindowsCodecs.lib")


// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "utils.h"
#include "imageManager.h"
#include "txtData.h"
#include "timeManager.h"
#include "sceneManager.h"
#include "soundManager.h"
#include "soundManager.h"
#include "streamManager.h"
#include "dtdManager.h"
#include "dialogManager.h"
#include "cameraManager.h"
#include "calculationManager.h"
#include "equipmentManager.h"
#include "shopManager.h"
#include "storageManager.h"
#include "uiManager.h"
#include "unitCodex.h"
#include "unitManager.h"
#include "itemCodex.h"
#include "equipCodex.h"
#include "monsterCodex.h"
#include "monsterManager.h"




using namespace std;
using namespace SUNFL_UTIL;
using namespace D2D1;

//==================================
// ## 매크로 처리 ## 21.04.23 ##
//==================================

#define WINNAME (LPTSTR)(TEXT("파이널판타지 -Brave Exvius-"))
#define WINSTARTX 50	//윈도우 창 시작좌표 (left)
#define WINSTARTY 0	//윈도우 창 시작좌표 (top)
#define WINSIZEX 1440	//윈도우 가로크기
#define WINSIZEY 1024	//윈도우 세로크기
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND				randomFunction::getSingleton()
#define KEYMANAGER		keyManager::getSingleton()
#define IMAGEMANAGER	imageManager::getSingleton()
#define TIMEMANAGER		timeManager::getSingleton()
#define SCENEMANAGER	sceneManager::getSingleton()
#define SOUNDMANAGER	soundManager::getSingleton()
#define TXTDATA			txtData::getSingleton()
#define STREAMMANAGER streamManager::getSingleton()
#define DTDMANAGER dtdManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define DIALOGMANAGER dialogManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()
#define CALCULATIONMANAGER calculationManager::getSingleton()
#define EQUIPMENTMANAGER equipmentManager::getSingleton()
#define SHOPMANAGER shopManager::getSingleton()
#define STORAGEMANAGER storageManager::getSingleton()
#define UIMANAGER uiManager::getSingleton()
#define UNITCODEX unitCodex::getSingleton()
#define UNITMANAGER unitManager::getSingleton()
#define MONSTERMANAGER monsterManager::getSingleton()
#define MONSTERCODEX monsterCodex::getSingleton()
#define ITEMCODEX itemCodex::getSingleton()
#define EQUIPCODEX equipCodex::getSingleton()




#define SAFE_DELETE(p) { if(p) { delete(p); (p) = nullptr; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[](p); (p) = nullptr; } }
#define SAFE_RELEASE(p) { if(p) { (p)->release(); (p) = NULL; } }
#define SAFE_RELEASE2(p) { if(p) { (p)->Release(); (p) = NULL; } }

//==================================
// ## extern ## 21.04.28 ##
//==================================
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;