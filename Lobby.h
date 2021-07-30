#pragma once
#include "stdafx.h"
#include "Define.h"
#include "KeyManager.h"


extern HINSTANCE hInst;                             
extern HWND g_hWnd;
extern RECT crt;
class Lobby
{
private:
	//map<string, BitmapImage*> BazziList;
	HWND myHWND;
	HDC myDC1, myDC2;
	HBITMAP hbitmap1, hbitmap2;
	HBITMAP holdbitmap1, holdbitmap2;
	BITMAP bit;
	KeyManager myKey;
	RECT clickStart;
	bool checkStart;
	int FrameX = 0, FrameY = 0;
	int bx, by;
	bool myActivation = false;
	int nConnection = 0;
public:
	Lobby();
	~Lobby();
	void Initialize(HDC hdc);
	int Progress(int& m_nCurrent);
	void Render(HDC hdc);
};