#include "Player.h"
Player::Player() {}
Player::~Player() {}

void Player::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	myDownDC = CreateCompatibleDC(hdc);
	myUpDC = CreateCompatibleDC(hdc);
	myLeftDC = CreateCompatibleDC(hdc);
	myRightDC = CreateCompatibleDC(hdc);
	myJumpDC = CreateCompatibleDC(hdc);
	Downbit = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\player\\down.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Downold = (HBITMAP)SelectObject(myDownDC, Downbit);
	Upbit = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\player\\Up.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Upold = (HBITMAP)SelectObject(myUpDC, Upbit);
	Leftbit = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\player\\Left.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Leftold = (HBITMAP)SelectObject(myLeftDC, Leftbit);
	Rightbit = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\player\\Right.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Rightold = (HBITMAP)SelectObject(myRightDC, Rightbit);
	Jumpbit = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\player\\jump.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Jumpold = (HBITMAP)SelectObject(myJumpDC, Jumpbit);
	GetObject(Downbit, sizeof(BITMAP), &UpDownbit);
	GetObject(Leftbit, sizeof(BITMAP), &LeftRightbit);
	GetObject(Jumpbit, sizeof(BITMAP), &Jumpbitmap);
}

void Player::Progress()
{
}

void Player::Render(HDC hdc)
{
	if (nPlayerWay == 0)
	{
		TransparentBlt(hdc, myXY.myX, myXY.myY, getPlayerUpDownX() / 8, getPlayerUpDownY(), myDownDC, 0, 0, getPlayerUpDownX() / 8, getPlayerUpDownY(), RGB(255, 0, 255));
	}
	switch (nPlayerWay)
	{
	case VK_LEFT:
		TransparentBlt(hdc, myXY.myX, myXY.myY, getPlayerLeftRightX() / 6, getPlayerLeftRightY(), myLeftDC, LRFrameX, 0, getPlayerLeftRightX() / 6, getPlayerLeftRightY(), RGB(255, 0, 255));
		break;
	case VK_UP:
		TransparentBlt(hdc, myXY.myX, myXY.myY, getPlayerUpDownX() / 8, getPlayerUpDownY(), myUpDC, UDFrameX, 0, getPlayerUpDownX() / 8, getPlayerUpDownY(), RGB(255, 0, 255));
		break;
	case VK_RIGHT:
		TransparentBlt(hdc, myXY.myX, myXY.myY, getPlayerLeftRightX() / 6, getPlayerLeftRightY(), myRightDC, LRFrameX, 0, getPlayerLeftRightX() / 6, getPlayerLeftRightY(), RGB(255, 0, 255));
		break;
	case VK_DOWN:
		TransparentBlt(hdc, myXY.myX, myXY.myY, getPlayerUpDownX() / 8, getPlayerUpDownY(), myDownDC, UDFrameX, 0, getPlayerUpDownX() / 8, getPlayerUpDownY(), RGB(255, 0, 255));
		break;
	}

	fFrameDelay += dDT;
	if (fFrameDelay > 0.1f)
	{
		fFrameDelay = 0;
		UDFrameX += 64;
		LRFrameX += 64;
		if (UDFrameX >= 512)
		{
			UDFrameX = 0;
		}

		if (LRFrameX >= 384)
		{
			LRFrameX = 0;
		}
	}
}

void Player::Render(HDC hdc, int nX, int nY)
{
	TransparentBlt(hdc, nX, nY, getPlayerJumpX() / 8, getPlayerJumpY(), myJumpDC, JumpFrameX, 0, getPlayerJumpX() / 8, getPlayerJumpY(), RGB(255, 0, 255));

	fFrameDelay += dDT;
	if (fFrameDelay > 0.5f)
	{
		fFrameDelay = 0;
		JumpFrameX += 64;
		if (JumpFrameX >= 512)
		{
			JumpFrameX = 0;
		}

	}
}

int Player::getPlayerUpDownX()
{
	UpDownX = UpDownbit.bmWidth;
	return UpDownX;
}

int Player::getPlayerUpDownY()
{
	UpDownY = UpDownbit.bmHeight;
	return UpDownY;
}

int Player::getPlayerLeftRightX()
{
	LeftRightX = LeftRightbit.bmWidth;
	return LeftRightX;
}

int Player::getPlayerLeftRightY()
{
	LeftRightY = LeftRightbit.bmHeight;
	return LeftRightY;
}

int Player::getPlayerJumpX()
{
	JumpX = Jumpbitmap.bmWidth;
	return JumpX;
}

int Player::getPlayerJumpY()
{
	JumpY = Jumpbitmap.bmHeight;
	return JumpY;
}