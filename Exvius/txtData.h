#pragma once
#include "singletonBase.h"
#include <vector>
#include <string>

struct tagIniData
{
	LPCWCHAR subject;
	LPCWCHAR title;
	LPCWCHAR body;
};


class txtData : public singletonBase<txtData>
{

private: 

	typedef vector<tagIniData>				arrIniData;
	typedef vector<tagIniData>::iterator	arrIniDataIter;

	typedef vector<arrIniData>				arrIniDatas;
	typedef vector<arrIniData>::iterator	arrIniDatasIter;

private:
	arrIniDatas _vIniData;
	WCHAR _currentTxt[128];
	
public:
	txtData();
	~txtData();

	HRESULT init();
	void release();

	void loadGame();
	void saveGame();



	//initData
	void addData(LPCWCHAR subject, LPCWCHAR title, LPCWCHAR body);
	void iniSave(LPCWCHAR fileName);

	LPCWCHAR loadDataString(LPCWCHAR fileName, LPCWCHAR subject, LPCWCHAR title, int size);
	LPCWCHAR loadDataString2(LPCWCHAR fileName, wstring subject, LPCWCHAR title, int size);
	int loadDataInterger(LPCWCHAR fileName, LPCWCHAR subject, LPCWCHAR title);

	//Save
	void txtSave(const char* saveFileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);

	
	void wtxtSave(const char* saveFileName, vector<LPCWCHAR> vwStr);
	LPCWCHAR wvectorArrayCombine(vector<LPCWCHAR> vArray);

	//Load
	vector<string> txtLoad(const char* loadFileName);
	vector<string> charArraySeparation(char charArray[]);

	vector<LPCWCHAR> wtxtLoad(LPCWCHAR loadFileName);
	vector<LPCWCHAR> wcharArraySeparation(WCHAR charArray[]);
};

