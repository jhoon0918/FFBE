#pragma once

typedef struct EQUIPMENT
{
	bool _weapon;
	float _hp;
	float _mp;
	float _att;
	float _mag;
	float _def;
	float _spr;

}EQUIP, *PEQUIP;
class equipment
{
protected:
	//��� �̹���

	dImage* _Image;
	
	//��� �̸�,Ÿ��, ��� ����, ���Ĺ�ȣ
	
	wstring _name;
	wstring _type;
	wstring _description;
	int _num;

	//��� ����
	
	EQUIP _equip;



public:
	virtual HRESULT init();
	void release();

	void update();
	void render(float x, float y);

	//----------------������--------------
	dImage* getImage() { return _Image; }

	wstring getName() { return _name; }
	void setName(wstring name) { _name = name; }

	wstring getType() { return _type; }
	void setType(wstring type) { _type = type; }

	int getNum() { return _num; }

	EQUIP getInfo() { return _equip; }
	void setInfo(EQUIP info) { _equip = info; }

	wstring getDes() { return _description; }
	void setDes(wstring des) { _description = des; }


};

