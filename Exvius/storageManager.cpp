#include "stdafx.h"
#include "storageManager.h"

HRESULT storageManager::init()
{
	layer = IMAGEMANAGER->findDImage("Ilayer");
	_itemcount = 0;
	_limit = 0;
	
	_back = true;
	_set = false;
	_m = 0;

	return S_OK;
}

void storageManager::release()
{
}

void storageManager::update()
{
}

void storageManager::render()
{
	WCHAR str[128];
	D2D_RECT_F IName[50];
	D2D_RECT_F IDes[50];
	_itemcount = vi.size();
	_limit = 50;

	for (int i = 0; i < vi.size(); ++i)
	{
		IName[i] = dRectMake(layerI[i].left + 100, layerI[i].top+5, 220, 30);
		IDes[i] = dRectMake(layerI[i].left + 100, layerI[i].top + 30, 220, 50);
		swprintf_s(str, L"%s", vi[i]->getName().c_str());
		layer->render(layerI[i].left, layerI[i].top);
		vi[i]->render(layerI[i].left + 35, layerI[i].bottom - 15 - (vi[i]->getImage()->getHeight()));
		DTDMANAGER->printText(str, IName[i], 15);
		swprintf_s(str, L"%s", vi[i]->getDes().c_str());
		DTDMANAGER->printText(str, IDes[i], 15);
	}
}

void storageManager::backon()
{
	if (_back)
	{
		for (int i = 0; i < vi.size(); i++)
		{
			if (layerI[0].top > 300) { layerI[i].bottom -= 1; layerI[i].top -= 1;  }
			else if (layerI[vi.size() - 1].bottom <= 850) { layerI[i].bottom += 1; layerI[i].top += 1; }
		}
	}
	else if (!_back)
	{
		for (int i = 0; i < vi.size(); i++)
		{
			if (_ptMouse.y < _m&&layerI[0].top < 350) { layerI[i].bottom += 3; layerI[i].top += 3;   }
			if (_ptMouse.y > _m && (layerI[vi.size() - 1].bottom > 700)) { layerI[i].bottom -= 3; layerI[i].top -= 3;  }
		}
	}
}

void storageManager::loadI(item* I)
{
	I->init();
	vi.push_back(I);
}

void storageManager::position()
{
	int j = 0;
	int k = 0;

	for (int i = 0; i < vi.size(); ++i)
	{
		if (i / 2 > j)
		{
			j++;
			k += 2;
		}
		layerI[i] = RectMake(10 + (i - k) * 370, 300 + 96 * j, 330, 86);
	}
}
