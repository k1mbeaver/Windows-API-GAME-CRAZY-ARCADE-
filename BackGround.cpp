#include "Background.h"

BackGround::BackGround() {}
BackGround::~BackGround() {}

void BackGround::Initialize(HDC hdc)
{
	parseJson.Initialize();
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BackGround").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	holdbitmap = (HBITMAP)SelectObject(myDC, hbitmap);
	myActivation = false;
	nConnection = 0;
}

void BackGround::Progress()
{
}

void BackGround::Render(HDC hdc)
{
	GetObject(hbitmap, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, 0, 0, bx, by, myDC, 0, 0, SRCCOPY);

	//SelectObject(myDC, holdbitmap);
	//DeleteObject(hbitmap);
	//DeleteDC(myDC);
}