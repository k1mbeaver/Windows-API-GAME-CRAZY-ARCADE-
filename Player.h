#pragma once
#include "stdafx.h"
#include "Define.h"

extern HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
extern HWND g_hWnd;
extern RECT crt;

class Player
{
private:
	HWND myHWND;
	HDC myDC;
	HBITMAP hbitmap;
	HBITMAP holdbitmap;
	bool myActivation = false;
	int nConnection = 0;
public:
	Player();
	~Player();

	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
};