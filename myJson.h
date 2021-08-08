#pragma once
#include "stdafx.h"
#pragma warning(disable : 4996)

class myJson
{
private:
public:
	string str;
	string strObject;
	int nObject;
	float fObject;
	bool boolObject;
	bool parsingRet;
	Json::Reader reader;
	Json::Value root;

	void Initialize();
	string& getMyObjectLink(const char* chFileName);
	int getMyObjectWidth(const char* chFileName);
	int getMyObjectHeight(const char* chFileName);
	float getMyObjectX(const char* chFileName);
	float getMyObjectY(const char* chFileName);
	float getMyObjectX2(const char* chFileName);
	float getMyObjectY2(const char* chFileName);
	int getMyObjectBottomRect(const char* chFileName);
	int getMyObjectTopRect(const char* chFileName);
	int getMyObjectBetweenX(const char* chFileName);
	int getMyObjectBetweenY(const char* chFileName);
	bool getMapExist(const char* chFileName, int nCount1, int nCount2);
	string& getMapBlock(const char* chFileName, int nCount1, int nCount2);
	string& getMapBreakBlock(const char* chFileName, int nCount1, int nCount2);
	float getMapX(const char* chFileName, int nCount1, int nCount2);
	float getMapY(const char* chFileName, int nCount1, int nCount2);
	bool getMapBreak(const char* chFileName, int nCount1, int nCount2);

	//string getObjectLink();
};