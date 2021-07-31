#pragma once
#include "stdafx.h"
#include "Define.h"
extern HINSTANCE hInst;
extern HWND g_hWnd;
extern RECT crt;
class Statue
{
private:
	HWND myHWND;
	BITMAP bit;
	int bx, by;
	HDC Stone1DC, Stone2DC, Stone3DC, Statue1DC, Statue2DC, Statue3DC;
	HBITMAP Stone1bit, Stone2bit, Stone3bit, Statue1bit, Statue2bit, Statue3bit;
	HBITMAP Stone1old, Stone2old, Stone3old, Statue1old, Statue2old, Statue3old;
	BITMAP StoneBitmap, Statue1Bitmap, Statue2Bitmap, Statue3Bitmap;
	int nStoneX, nStoneY, nStatue1X, nStatue1Y, nStatue2X, nStatue2Y, nStatue3X, nStatue3Y;
	bool myActivation = false;
	int nConnection = 0;
public:
	Statue();
	~Statue();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
	void Render(HDC hdc, int nX, int nY);
	int getStoneX();
	int getStoneY();
	int getStatue1X();
	int getStatue1Y();
	int getStatue2X();
	int getStatue2Y();
	int getStatue3X();
	int getStatue3Y();
};