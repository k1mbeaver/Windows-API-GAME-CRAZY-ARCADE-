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
	myActivation = false;
	nConnection = 0;
}

void Player::Progress()
{
}

void Player::Render(HDC hdc)
{
	GetObject(Downbit, sizeof(BITMAP), &UpDownbit);
	UpDownX = UpDownbit.bmWidth;
	UpDownY = UpDownbit.bmHeight;

	GetObject(Leftbit, sizeof(BITMAP), &LeftRightbit);
	LeftRightX = LeftRightbit.bmWidth;
	LeftRightY = LeftRightbit.bmHeight;

	if (nPlayerWay == 0)
	{
		TransparentBlt(hdc, myXY.myX, myXY.myY, UpDownX / 8, UpDownY, myDownDC, 0, 0, UpDownX / 8, UpDownY, RGB(255, 0, 255));
	}
	switch (nPlayerWay)
	{
	case VK_LEFT:
		TransparentBlt(hdc, myXY.myX, myXY.myY, LeftRightX / 6, LeftRightY, myLeftDC, LRFrameX, 0, LeftRightX / 6, LeftRightY, RGB(255, 0, 255));
		break;
	case VK_UP:
		TransparentBlt(hdc, myXY.myX, myXY.myY, UpDownX / 8, UpDownY, myUpDC, UDFrameX, 0, UpDownX / 8, UpDownY, RGB(255, 0, 255));
		break;
	case VK_RIGHT:
		TransparentBlt(hdc, myXY.myX, myXY.myY, LeftRightX / 6, LeftRightY, myRightDC, LRFrameX, 0, LeftRightX / 6, LeftRightY, RGB(255, 0, 255));
		break;
	case VK_DOWN:
		TransparentBlt(hdc, myXY.myX, myXY.myY, UpDownX / 8, UpDownY, myDownDC, UDFrameX, 0, UpDownX / 8, UpDownY, RGB(255, 0, 255));
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
	GetObject(Jumpbit, sizeof(BITMAP), &Jumpbitmap);
	JumpX = Jumpbitmap.bmWidth;
	JumpY = Jumpbitmap.bmHeight;

	TransparentBlt(hdc, nX, nY, JumpX / 8, JumpY, myJumpDC, JumpFrameX, 0, JumpX / 8, JumpY, RGB(255, 0, 255));

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