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
	HBITMAP Shadowbit;
	HBITMAP Shadowold;
	BITMAP Shadowbitmap;
	myJson parseJson;
	int nDieCount = 0; // �׾����� ��ǥ ���߱�����
	int nDieX, nDieY = 0;
public:
	Shadow();
	~Shadow();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc, int nPlayerState, int nState); // ���� �÷��� ��;
	void Render(HDC hdc, int nState); // �κ��;
	int getWidth(const char* chFileName);
	int getHeight(const char* chFileName);
	float getX(const char* chFileName);
	float getY(const char* chFileName);
};