#include "myJson.h"

void myJson::Initialize()
{
	ifstream ist("Image\\ImageLink.json");
	for (char chP; ist >> chP;)
		str += chP;

	parsingRet = reader.parse(str, root);

}

string& myJson::getMyObjectLink(const char* chFileName)
{
	strObject = "\0";

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		strObject = (*it)["ImageLink"].asString();
	}

	return strObject;
}

int myJson::getMyObjectWidth(const char* chFileName)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)["Width"].asInt();
	}

	return nObject;
}

int myJson::getMyObjectHeight(const char* chFileName)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)["Height"].asInt();
	}

	return nObject;
}

float myJson::getMyObjectX(const char* chFileName)
{
	fObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		fObject = (*it)["LocateX"].asFloat();
	}

	return fObject;

}

float myJson::getMyObjectY(const char* chFileName)
{
	fObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		fObject = (*it)["LocateY"].asFloat();
	}

	return fObject;
}

int myJson::getMyObjectBottomRect(const char* chFileName)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)["BottomRect"].asInt();
	}

	return nObject;
}

int myJson::getMyObjectTopRect(const char* chFileName)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)["TopRect"].asInt();
	}

	return nObject;
}

int myJson::getMyObjectBetweenX(const char* chFileName)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)["BetweenX"].asInt();
	}

	return nObject;
}

int myJson::getMyObjectBetweenY(const char* chFileName)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)["BetweenY"].asInt();
	}

	return nObject;
}

float myJson::getMyObjectX2(const char* chFileName)
{
	fObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		fObject = (*it)["LocateX2"].asFloat();
	}

	return fObject;

}

float myJson::getMyObjectY2(const char* chFileName)
{
	fObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		fObject = (*it)["LocateY2"].asFloat();
	}

	return fObject;
}

// �ʿ� �ִ� ���� ��������
bool myJson::getMapExist(const char* chFileName, int nCount1, int nCount2)
{
	boolObject = false;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		boolObject = (*it)[nCount1][nCount2]["Blockexist"].asBool();
	}

	return boolObject;
}

// �ʿ� �ִ� ���� ��θ� �����´�
string& myJson::getMapBlockLink(const char* chFileName, int nCount1, int nCount2)
{
	strObject = "\0";

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		strObject = (*it)[nCount1][nCount2]["Block"].asString();
	}

	return strObject;
}

// �ʿ� �ִ� ���� �μ����� ���� �ִϸ��̼��� ���Ͽ� �μ����� �� ��Ʈ���� ��θ� �����´�
string& myJson::getMapBreakBlockLink(const char* chFileName, int nCount1, int nCount2)
{
	strObject = "\0";

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		strObject = (*it)[nCount1][nCount2]["BreakBlock"].asString();
	}

	return strObject;
}

// �� ���� X ��ǥ
float myJson::getMapX(const char* chFileName, int nCount1, int nCount2)
{
	fObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		fObject = (*it)[nCount1][nCount2]["LocateX"].asFloat();
	}

	return fObject;
}

// �� ���� Y��ǥ
float myJson::getMapY(const char* chFileName, int nCount1, int nCount2)
{
	fObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		fObject = (*it)[nCount1][nCount2]["LocateY"].asFloat();
	}

	return fObject;
}

// �� ���� �ı� ����
bool myJson::getMapBreak(const char* chFileName, int nCount1, int nCount2)
{
	boolObject = false;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		boolObject = (*it)[nCount1][nCount2]["Break"].asBool();
	}

	return boolObject;
}

int myJson::getMapWidth(const char* chFileName, int nCount1, int nCount2)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)[nCount1][nCount2]["Width"].asInt();
	}

	return nObject;
}

int myJson::getMapHeight(const char* chFileName, int nCount1, int nCount2)
{
	nObject = 0;

	Json::Value myobject = root[chFileName];

	for (Json::ValueIterator it = myobject.begin(); it != myobject.end(); it++)
	{
		nObject = (*it)[nCount1][nCount2]["Height"].asInt();
	}

	return nObject;
}

// ���� BackGround Ŭ�������� ���͵��� �̿��Ͽ� Json�� �о Image* 2���� �迭�� �ֵ��� ��Ե� Initialize���� ������ �ϰ� �о�ͼ� ����ϴ� ������
/*
string myJson::getObjectLink()
{
}
*/