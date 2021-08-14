#include "Bomb.h"
Bomb::Bomb() {}
Bomb::~Bomb() {}

void Bomb::Initialize(HDC hdc)
{
	// Initialize에서 각 이미지들의 정보를 저장해 놓으면?

	parseJson.Initialize();
	myDC = CreateCompatibleDC(hdc);
	Bombbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Bomb").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Bombold = (HBITMAP)SelectObject(myDC, Bombbit);
}

void Bomb::Progress()
{
}

void Bomb::Render(HDC hdc) // 게임 플레이 화면 용
{
	TransparentBlt(hdc, myXY.myX + 10, myXY.myY + 60, getWidth("Bomb"), getHeight("Bomb"), myDC, 0, 0, getWidth("Bomb"), getHeight("Bomb"), RGB(255, 0, 255));
}

int Bomb::getWidth(const char* chFileName)
{
	int nWidth;
	nWidth = parseJson.getMyObjectWidth(chFileName);

	return nWidth;
}

int Bomb::getHeight(const char* chFileName)
{
	int nHeight;
	nHeight = parseJson.getMyObjectHeight(chFileName);

	return nHeight;
}	

float Bomb::getX(const char* chFileName)
{
	float fX;
	fX = parseJson.getMyObjectX(chFileName);

	return fX;
}

float Bomb::getY(const char* chFileName)
{
	float fY;
	fY = parseJson.getMyObjectY(chFileName);

	return fY;
}