#pragma once

class item
{
protected:
	//������ �̹���
	dImage* _image;

	//������ Ÿ�� ȸ�� / ������ / �̸� / ���� / ���Ĺ�ȣ / ��ġ

	bool _restore;
	bool _dealt;

	wstring _name;
	wstring _description;
	int _num;
	int _amount;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(float x, float y);

	//--------------------������----------------------

	dImage* getImage() { return _image; }
	

	bool getRes() { return _restore; }
	void setRes(bool res) { _restore = res; }

	bool getDeal() { return _dealt; }
	void setDeal(bool deal) { _dealt = deal; }

	wstring getName() { return _name; }
	void setName(wstring name) { _name = name; }

	wstring getDes() { return _description; }
	void setDes(wstring des) { _description = des; }

	int getNum() { return _num; }

	int getAmount() { return _amount; }
	void setAmount(int amount) { _amount = amount; }

	



};

