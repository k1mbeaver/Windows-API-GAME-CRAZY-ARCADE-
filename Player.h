#pragma once
#include "stdafx.h"
#include "Define.h"
extern HINSTANCE hInst;                              
extern HWND g_hWnd;
extern RECT crt;
class Player
{
private:
	HWND myHWND;
	HDC myDC;
	BITMAP bit;
	int bx, by;
	HDC myDownDC, myUpDC, myLeftDC, myRightDC, myJumpDC;
	HBITMAP Downbit, Upbit, Leftbit, Rightbit, Jumpbit;
	HBITMAP Downold, Upold, Leftold, Rightold, Jumpold;
	BITMAP UpDownbit, LeftRightbit, Jumpbitmap;
	RECT PlayerUDRECT, PlayerRLRECT;
	int UDFrameX, LRFrameX, JumpFrameX;
	int UpDownX, UpDownY, JumpX;
	int LeftRightX, LeftRightY, JumpY;
	bool myActivation = false;
	int nConnection = 0;
public:
	Player();
	~Player();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
	void Render(HDC hdc, int nX, int nY);
	int getPlayerUpDownX();
	int getPlayerUpDownY();
	int getPlayerLeftRightX();
	int getPlayerLeftRightY();
	int getPlayerJumpX();
	int getPlayerJumpY();
	RECT getPlayerRECT();
};