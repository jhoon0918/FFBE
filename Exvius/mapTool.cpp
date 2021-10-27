#include "stdafx.h"
#include "mapTool.h"

HRESULT mapTool::init()
{
	_tileImage[0] = IMAGEMANAGER->addFrameDImage("town1", L"img/tile/town1.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[1] = IMAGEMANAGER->addFrameDImage("town2", L"img/tile/town2.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[2] = IMAGEMANAGER->addFrameDImage("town3", L"img/tile/town3.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[3] = IMAGEMANAGER->addFrameDImage("town4", L"img/tile/town4.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[4] = IMAGEMANAGER->addFrameDImage("darktemple", L"img/tile/dtemple.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[5] = IMAGEMANAGER->addFrameDImage("forest", L"img/tile/forest.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[6] = IMAGEMANAGER->addFrameDImage("ruined forest", L"img/tile/rforest.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[7] = IMAGEMANAGER->addFrameDImage("ruined temple", L"img/tile/rtemple.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[8] = IMAGEMANAGER->addFrameDImage("ship", L"img/tile/ship.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[9] = IMAGEMANAGER->addFrameDImage("ghost_ship", L"img/tile/gship.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[10] = IMAGEMANAGER->addFrameDImage("pirate_cave", L"img/tile/pcave.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[11] = IMAGEMANAGER->addFrameDImage("magma_cave", L"img/tile/mcave.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[12] = IMAGEMANAGER->addFrameDImage("mountain1", L"img/tile/mountain1.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[13] = IMAGEMANAGER->addFrameDImage("mountain2", L"img/tile/mountain2.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[14] = IMAGEMANAGER->addFrameDImage("mountain3", L"img/tile/mountain3.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[15] = IMAGEMANAGER->addFrameDImage("castle", L"img/tile/castle.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	_tileImage[16] = IMAGEMANAGER->addFrameDImage("in_castle", L"img/tile/in_castle.png", 512, 512, SAMPLETILEX, SAMPLETILEY);
	
	_currentTile.tilenumber = 0;
	_currentTile.x = 0;
	_currentTile.y = 0;
	
	Rect = RectMake(50, 0, 1440, WINSIZEY);
	AdjustWindowRect(&Rect, WINSTYLE, false);
	SetWindowPos(_hWnd, NULL, 50, 0, (Rect.right - Rect.left),
		(Rect.bottom - Rect.top), SWP_NOZORDER | SWP_NOMOVE);

	_width = TILEX;
	_height = TILEY;

	_tilenumber = 0;
	background = RectMake(20, 20, TILESIZE * 15, TILESIZE * 15);
	_x = (background.left + background.right) / 2;
	_y = (background.top + background.bottom) / 2;
	_rx = (background.left + background.right) / 2;
	_ry = (background.top + background.bottom) / 2;


	
	CAMERAMANAGER->init(5000, 5000);
	setup();
	return S_OK;

}

void mapTool::release()
{
}

void mapTool::update()
{
	_x = (background.left + background.right) / 2;
	_y = (background.top + background.bottom) / 2;
	_initX = _x / TILESIZE - 8;
	_endX = _x / TILESIZE + 6;
	_initY = _y / TILESIZE - 8;
	_endY = _y / TILESIZE + 6;

	if (_initX < 0)
		_initX = 0;
	if (_endX >= _width)
		_endX = _width - 1;
	if (_initY < 0)
		_initY = 0;
	if (_endY >= _height)
		_endY = _height - 1;

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_tilenumber++;
		setMap();
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_tilenumber--;
		setMap();
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		if (_ctrSelect == CTRL_TERRAINDRAW)_ctrSelect = CTRL_OBJDRAW;
		else _ctrSelect = CTRL_TERRAINDRAW;
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		save();
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		load(name, _width, _height);
	}
	if (KEYMANAGER->isOnceKeyDown('J'))
	{
		_width++;
	}
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		_width--;
	}
	if (KEYMANAGER->isOnceKeyDown('N'))
	{
		_height++;
	}
	if (KEYMANAGER->isOnceKeyDown('M'))
	{
		_height--;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		setup();
	}
	if (_width > TILEX)_width = TILEX;
	if (_height > TILEY)_height = TILEY;
	if (_tilenumber < 0)_tilenumber = 0;
	if (_tilenumber == TILEMAX)_tilenumber = TILEMAX - 1;

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		setMap();
	}
	if (KEYMANAGER->isStayKeyDown(VK_MBUTTON))
	{
		CAMERAMANAGER->updateScreen4(_ptMouse.x, _ptMouse.y);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON)) { _ctrSelect = CTRL_ERASER; setMap(); }
	for (int i = 0; i < _width*_height; ++i)
	{
		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_ry -= 0.01;
			if (_ry <= background.top)
			{
				_ry = background.top;

			}
			if (_tiles[_width*_height - 1].rc.bottom >= background.bottom)
			{


				_tiles[i].rc.top -= 1;
				_tiles[i].rc.bottom -= 1;
			}
		}
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_rx -= 0.01;
			if (_rx <= background.left)
			{
				_rx = background.left;

			}
			if (_tiles[_width - 1].rc.right >= background.right)
			{


				_tiles[i].rc.left -= 1;
				_tiles[i].rc.right -= 1;
			}
		}
		if (KEYMANAGER->isStayKeyDown('S'))
		{
			_ry += 0.01;

			if (_ry >= background.bottom)
			{
				_ry = background.bottom;

			}
			if (_tiles[0].rc.top <= background.top)
			{

				_tiles[i].rc.top += 1;
				_tiles[i].rc.bottom += 1;
			}
		}
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_rx += 0.01;
			if (_rx >= background.right)
			{
				_rx = background.right;
			}
			if (_tiles[0].rc.left <= background.left)
			{


				_tiles[i].rc.left += 1;
				_tiles[i].rc.right += 1;

			}

		}
	}


	sprintf_s(name, "%d_%d.map", _width, _height);
	CAMERAMANAGER->updateScreen2(0, 0);
}

void mapTool::render()
{

	D2D_RECT_F rc = dRectMake(_ptMouse.x, _ptMouse.y, 5, 5);
	D2D_RECT_F _rc = dRectMake(_rx, _ry, 5, 5);
	RECT temp;
	_tileImage[_tilenumber]->render(WINSIZEX - _tileImage[_tilenumber]->getWidth(), 0);
	//맵툴 그리기, 백그라운드 렉트 안에 있는놈들만 보임
	for (int i = 0; i < _width*_height; ++i)
	{
		if (IntersectRect(&temp, &background, &_tiles[i].rc))
		{
			if ((_tiles[i].rc.left + _tiles[i].rc.right) / 2 >= background.left && (_tiles[i].rc.top + _tiles[i].rc.bottom) / 2.3 <= background.bottom)
			{
				_tileImage[_tiles[i].tilenumber]->frameRender(_tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
				_tileImage[_tiles[i].tilenumber]->frameRender(_tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].objFrameX, _tiles[i].objFrameY);
			}
		}
	}


	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		WCHAR str[128];
		for (int i = 0; i < _width*_height; ++i)
		{
			DTDMANAGER->Rectangle(_tiles[i].rc);
		}
		for (int i = 0; i < SAMPLETILEX*SAMPLETILEY; ++i)
		{

			DTDMANAGER->Rectangle(_sampleTile[i].rcTile);
			swprintf_s(str, L"ct.x: %d, ct.y: %d", _currentTile.x, _currentTile.y);
			DTDMANAGER->printText(str, _ptMouse.x, _ptMouse.y, 250, 200);
		}
		swprintf_s(str, L"witdh: %d, height: %d", _width, _height);
		DTDMANAGER->printText(str, _ptMouse.x, _ptMouse.y, 200, 50);
		swprintf_s(str, L"ctr: %d", _ctrSelect);
		DTDMANAGER->printText(str, _ptMouse.x, _ptMouse.y, 250, 450);
		swprintf_s(str, L"time: %f", CAMERAMANAGER->getT());
		DTDMANAGER->printText(str, _ptMouse.x, _ptMouse.y, 250, 350);

		//미니맵 (아 이놈은 왜 움직이냐고 ㅋㅋ)
		for (int i = 0; i < _width*_height; ++i)
		{
			_tileImage[_tiles[i].tilenumber]->frameRender(WINSIZEX - 200 + _tiles[i].rc.left / 6,
				600 + _tiles[i].rc.top / 6,
				_tiles[i].terrainFrameX,
				_tiles[i].terrainFrameY,
				6, 6);

			if (_tiles[i].obj == OBJ_NONE) continue;

			_tileImage[_tiles[i].tilenumber]->frameRender(WINSIZEX - 200 + _tiles[i].rc.left / 6,
				600 + _tiles[i].rc.top / 6,
				_tiles[i].objFrameX,
				_tiles[i].objFrameY,
				4, 4);


		}
	}
	DTDMANAGER->Rectangle(rc);
	DTDMANAGER->Rectangle(_rc);
	DTDMANAGER->Rectangle(background);
}
//맵툴 틀 셋업
void mapTool::setup()
{

	//처음 컨트롤 상태는 지형으로
	_ctrSelect = CTRL_TERRAINDRAW;

	//타일셋 먼저 세팅
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			//타일셋에 렉트를 씌움
			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				(WINSIZEX - _tileImage[_tilenumber]->getWidth()) + j * TILESIZE,
				i * TILESIZE,
				(WINSIZEX - _tileImage[_tilenumber]->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

	//타일 영역
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			SetRect(&_tiles[i * _width + j].rc,
				j * TILESIZE + 20,
				i * TILESIZE + 20,
				j * TILESIZE + TILESIZE + 20,
				i * TILESIZE + TILESIZE + 20);
		}
	}


	for (int i = 0; i < _width * _height; ++i)
	{
		_tiles[i].tilenumber = _tilenumber;
		_tiles[i].terrainFrameX = 5;
		_tiles[i].terrainFrameY = 2;
		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameY = 0;
		_tiles[i].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
		_tiles[i].obj = OBJ_NONE;
	}

}

void mapTool::setMap()
{
	//타일셋에 내가 그리고싶은 타일 또는 오브젝트 클릭
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; ++i)
	{
		_sampleTile[i].tilenumber = _tilenumber;

		if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
		{
			_currentTile.tilenumber = _sampleTile[i].tilenumber;
			_currentTile.x = _sampleTile[i].terrainFrameX;
			_currentTile.y = _sampleTile[i].terrainFrameY;
			break;
		}
	}

	for (int i = 0; i < _width * _height; ++i)
	{
		if (PtInRect(&_tiles[i].rc, _ptMouse) && PtInRect(&background, _ptMouse))
		{
			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
				_tiles[i].tilenumber = _currentTile.tilenumber;
				_tiles[i].terrainFrameX = _currentTile.x;
				_tiles[i].terrainFrameY = _currentTile.y;

				_tiles[i].terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_OBJDRAW)
			{
				_tiles[i].tilenumber = _currentTile.tilenumber;
				_tiles[i].objFrameX = _currentTile.x;
				_tiles[i].objFrameY = _currentTile.y;

				_tiles[i].obj = objSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_ERASER)
			{
				_tiles[i].objFrameX = NULL;
				_tiles[i].objFrameY = NULL;
				_tiles[i].obj = OBJ_NONE;
			}
			InvalidateRect(_hWnd, NULL, false);
			break;
		}


	}

}


void mapTool::save()
{
	HANDLE file;
	DWORD write;


	file = CreateFile(name, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tiles, sizeof(tagTile)*_width*_height, &write, NULL);

	CloseHandle(file);
}

void mapTool::load(const char * name, int width, int height)
{
	HANDLE file;
	DWORD read;

	file = CreateFile(name, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile)*width*height, &read, NULL);

	CloseHandle(file);
}

TERRAIN mapTool::terrainSelect(int frameX, int frameY)
{
	if (frameX == 1 && frameY == 0)
	{
		return TR_CEMENT;
	}
	else if (frameX == 2 && frameY == 0)
	{
		return TR_DESERT;
	}
	else if (frameX == 3 && frameY == 0)
	{
		return TR_GRASS;
	}
	else if (frameX == 4 && frameY == 0)
	{
		return TR_WATER;
	}

	return TR_GRASS;
}

OBJECT mapTool::objSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 0)
	{
		return OBJ_TANK1;
	}
	else if (frameX == 0 && frameY == 8)
	{
		return OBJ_TANK2;
	}
	else if (frameX == 0 && frameY == 1)
	{
		return OBJ_BLOCK1;
	}
	else if (frameX == 0 && frameY == 2)
	{
		return OBJ_BLOCK3;
	}
	else if (frameX == 15 && frameY == 3)
	{
		return OBJ_BLOCKS;
	}

	return OBJ_BLOCK1;
}
