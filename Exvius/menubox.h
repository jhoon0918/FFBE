#pragma once


class menubox
{
protected:
	int _index;
	bool _hidden;
	dImage* _menu[7];
	RECT _tab[6];
	int _menuSelect;
public:
	menubox();
	~menubox();
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render()=0;
	virtual void changetab(int number);
	

	bool getHidden() { return _hidden; }
	void setHidden(bool hidden) { _hidden = hidden; }
};

