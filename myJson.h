#pragma once
#include "stdafx.h"
#pragma warning(disable : 4996)

class myJson
{
private:
public:
	string str;
	bool parsingRet;
	Json::Reader reader;
	Json::Value root;

	void Initialize();
	string getMyObjectLink(const char* chFileName);
	int getMyObjectWidth(const char* chFileName);
	int getMyObjectHeight(const char* chFileName);
	float getMyObjectX(const char* chFileName);
	float getMyObjectY(const char* chFileName);
	//string getObjectLink();
};