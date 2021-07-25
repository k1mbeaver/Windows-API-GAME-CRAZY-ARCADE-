#pragma once
#include "stdafx.h"
#include "Define.h"

extern HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
extern HWND g_hWnd;
extern RECT crt;

class Shadow
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
	Shadow();
	~Shadow();

	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
};