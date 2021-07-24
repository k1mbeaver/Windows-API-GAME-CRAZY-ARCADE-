#include "background.h"

BackGround::BackGround() {}
BackGround::~BackGround() {}

void BackGround::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade\\Crazy Arcade\\Image\\BackGround.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
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

	BitBlt(hdc, 0, 0, 1424, 720, myDC, 0, 0, SRCCOPY);

	SelectObject(myDC, holdbitmap);
	DeleteObject(hbitmap);
	DeleteDC(myDC);
}