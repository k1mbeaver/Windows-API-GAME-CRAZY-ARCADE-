#pragma once
#include "stdafx.h"
#include "Define.h"
#include "myJson.h"

extern HINSTANCE hInst;
extern HWND g_hWnd;
extern RECT crt;

class Shadow
{
private:
	HWND myHWND;
	HDC myDC;
	string filename;
	int nWidth, nHeight;
	float fX, fY;
	BITMAP bit;
	int bx, by;
	HBITMAP Shadowbit;
	HBITMAP Shadowold;
	BITMAP Shadowbitmap;
	myJson parseJson;
	bool myActivation = false;
	int nConnection = 0;
public:
	Shadow();
	~Shadow();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc); // 게임 플레이 용;
	void Render(HDC hdc, int nState); // 로비용;
	int getWidth(const char* chFileName);
	int getHeight(const char* chFileName);
	float getX(const char* chFileName);
	float getY(const char* chFileName);
};