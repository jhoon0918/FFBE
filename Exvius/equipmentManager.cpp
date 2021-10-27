#include "stdafx.h"
#include "equipmentManager.h"

HRESULT equipmentManager::init()
{
	layer = IMAGEMANAGER->findDImage("Ilayer");
	
	_equipcount= 0;
	_limit = 0;

	_back = true;
	_m = 0;
	return S_OK;
}

void equipmentManager::release()
{
}

void equipmentManager::update()
{
}

void equipmentManager::render()
{
	WCHAR str[128];
	D2D_RECT_F EName[50];
	D2D_RECT_F EDes[50];
	_equipcount = ve.size();
	_limit = 50;

	for (int i = 0; i < ve.size(); ++i)
	{
		EName[i] = dRectMake(layerE[i].left + 100, layerE[i].top + 5, 220, 30);
		EDes[i] = dRectMake(layerE[i].left + 100, layerE[i].top + 30, 220, 50);
		swprintf_s(str, L"%s", ve[i]->getName().c_str());
		layer->render(layerE[i].left, layerE[i].top);
		ve[i]->render(layerE[i].left + 35, layerE[i].bottom - 25 - (ve[i]->getImage()->getHeight()));
		DTDMANAGER->printText(str, EName[i], 15);
		swprintf_s(str, L"%s", ve[i]->getDes().c_str());
		DTDMANAGER->printText(str, EDes[i], 15);
	}
}

void equipmentManager::backon()
{
	if (_back)
	{
		for (int i = 0; i < ve.size(); i++)
		{
			if (layerE[0].top > 300) { layerE[i].bottom -= 1; layerE[i].top -= 1; }
			else if (layerE[ve.size() - 1].bottom <= 850) { layerE[i].bottom += 1; layerE[i].top += 1; }
		}
	}
	else if (!_back)
	{
		for (int i = 0; i < ve.size(); i++)
		{
			if (_ptMouse.y < _m&&layerE[0].top < 350) { layerE[i].bottom += 3; layerE[i].top += 3; }
			if (_ptMouse.y > _m && (layerE[ve.size() - 1].bottom > 700)) { layerE[i].bottom -= 3; layerE[i].top -= 3; }
		}
	}
}

void equipmentManager::loadE(equipment * E)
{
	E->init();
	ve.push_back(E);
}

void equipmentManager::position()
{
	int j = 0;
	int k = 0;

	for (int i = 0; i < ve.size(); ++i)
	{
		if (i / 2 > j)
		{
			j++;
			k += 2;
		}
		layerE[i] = RectMake(10 + (i - k) * 370, 300 + 96 * j, 330, 86);
	}
}
