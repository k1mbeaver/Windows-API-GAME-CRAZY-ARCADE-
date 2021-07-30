
#pragma once
#include "stdafx.h"
#include "Define.h"

extern HINSTANCE hInst;                             
extern HWND g_hWnd;
extern RECT crt;

class BackGround
{
private:
	HWND myHWND;
	HDC myDC;
	HBITMAP hbitmap;
	HBITMAP holdbitmap;
	BITMAP bit;
	int bx, by;
	bool myActivation = false;
	int nConnection = 0;
public:
	BackGround();
	~BackGround();

	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
};