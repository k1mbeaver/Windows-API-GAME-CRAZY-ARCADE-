#include "Mark.h"

Mark::Mark() {}
Mark::~Mark() {}

void Mark::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\������ ����\\����� ����� ���͵�\\ũ������ �����̵�\\Crazy Arcade\\Crazy Arcade\\Image\\player\\solo_player.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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

	TransparentBlt(hdc, 290, 110, bx, by, myDC, 0, 0, bx, by, RGB(255, 0, 255));

	//SelectObject(myDC, holdbitmap);
	//DeleteObject(hbitmap);
	//DeleteDC(myDC);
}