#pragma once
#include "stdafx.h"
#include "Define.h"
#include "BitmapImage.h"

extern HINSTANCE hInst;                                // 현재 인스턴스입니다.
extern HWND g_hWnd;
extern RECT crt;

class Player
{
private:
	HWND myHWND;
	HDC myDownDC, myUpDC, myLeftDC, myRightDC;
	HBITMAP Downbit, Upbit, Leftbit, Rightbit;
	HBITMAP Downold, Upold, Leftold, Rightold;
	BITMAP UpDownbit, LeftRightbit;
	int UDFrameX, LRFrameX;
	int UpDownX, UpDownY;
	int LeftRightX, LeftRightY;
	bool myActivation = false;
	int nConnection = 0;
public:
	Player();
	~Player();

	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
};