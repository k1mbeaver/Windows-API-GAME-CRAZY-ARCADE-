#pragma once
#include "stdafx.h"
#include "Define.h"

class DbBuf
{
private:
	HWND g_hWnd;
	HINSTANCE hInst;
	HDC hDCMain = GetDC(g_hWnd);
	RECT crt;
	HDC hdcBuffer;
	HBITMAP hdcBmp;
	HBITMAP OldBmp;
public:
	DbBuf();
	~DbBuf();

	void Initialize(); // �ʱ�ȭ
	void Progress(); // ó��
	void Render(); // �׸���
};