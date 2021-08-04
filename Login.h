#pragma once
#include "stdafx.h"
#include "Define.h"
#include "KeyManager.h"
#include "myJson.h"

extern HINSTANCE hInst;                               
extern HWND g_hWnd;
extern RECT crt;

class Login
{
private:
	HWND myHWND;
	HDC myDC;
	HBITMAP hbitmap;
	HBITMAP holdbitmap;
	BITMAP bit;
	RECT clickStart;
	KeyManager myKey;
	myJson parseJson;
	bool checkStart;
	int bx, by;
	bool myActivation = false;
	int nConnection = 0;
public:
	Login();
	~Login();

	void Initialize(HDC hdc);
	int Progress(int& m_nCurrent);
	void Render(HDC hdc);
};