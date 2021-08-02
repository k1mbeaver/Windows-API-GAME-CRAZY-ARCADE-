#include "Mark.h"

Mark::Mark() {}
Mark::~Mark() {}

void Mark::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\player\\solo_player.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	holdbitmap = (HBITMAP)SelectObject(myDC, hbitmap);
	myActivation = false;
	nConnection = 0;
}

void Mark::Progress()
{
}

void Mark::Render(HDC hdc)
{
	GetObject(hbitmap, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	TransparentBlt(hdc, myXY.myX + 19, myXY.myY - 30, bx, by, myDC, 0, 0, bx, by, RGB(255, 0, 255));

}