#include "background.h"

BackGround::BackGround() {}
BackGround::~BackGround() {}

void BackGround::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, L"../image/right.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	holdbitmap = (HBITMAP)SelectObject(myDC, hbitmap);
	myActivation = false;
	nConnection = 0;
}

void BackGround::Progress()
{
}

void BackGround::Render(HDC hdc)
{
	TransparentBlt(hdc, nConnection, 0, crt.right, crt.bottom, myDC, 0, 0, crt.right, crt.bottom, RGB(255, 0, 255));
}