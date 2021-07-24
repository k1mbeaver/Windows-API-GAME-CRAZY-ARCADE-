#include "Player.h"

Player::Player() {}
Player::~Player() {}

void Player::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, L"right.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	holdbitmap = (HBITMAP)SelectObject(myDC, hbitmap);
	myActivation = false;
	nConnection = 0;
}

void Player::Progress()
{
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc, 300, 300, 500, 500);
}