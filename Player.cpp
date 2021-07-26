#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade\\Crazy Arcade\\Image\\player\\down\\down1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	holdbitmap = (HBITMAP)SelectObject(myDC, hbitmap);
	myActivation = false;
	nConnection = 0;
}

void Player::Progress()
{
}

void Player::Render(HDC hdc)
{
	GetObject(hbitmap, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	TransparentBlt(hdc, myXY.myX, myXY.myY, bx, by, myDC, 0, 0, bx, by, RGB(255, 0, 255));

	//SelectObject(myDC, holdbitmap);
	//DeleteObject(hbitmap);
	//DeleteDC(myDC);
}