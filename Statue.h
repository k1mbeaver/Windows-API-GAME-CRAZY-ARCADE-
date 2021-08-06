#pragma once
#include "stdafx.h"
#include "Define.h"
#include "myJson.h"

extern HINSTANCE hInst;
extern HWND g_hWnd;
extern RECT crt;
class Statue
{
private:
	HWND myHWND;
	BITMAP bit;
	int bx, by;
	HDC myDC;
	HBITMAP Statue1bit, Statue2bit, Statue3bit;
	HBITMAP Statue1old, Statue2old, Statue3old;
	BITMAP Statue1Bitmap, Statue2Bitmap, Statue3Bitmap;
	int nStatue1X, nStatue1Y, nStatue2X, nStatue2Y, nStatue3X, nStatue3Y;
	RECT StatueRect;
	bool myActivation = false;
	int nConnection = 0;
	myJson parseJson;
public:
	Statue();
	~Statue();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
	void Render(HDC hdc, int nX, int nY);
	int getWidth(const char* chFileName);
	int getHeight(const char* chFileName);
	float getX(const char* chFileName);
	float getY(const char* chFileName);
	int getBottom(const char* chFileName);
	int getTop(const char* chFileName);
	RECT getStatueRECT(const char* chFileName);
};