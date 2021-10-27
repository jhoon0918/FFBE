#pragma once
#include "menubox.h"

class equipMenu:public menubox
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update() ;
	virtual void render() ;
};

