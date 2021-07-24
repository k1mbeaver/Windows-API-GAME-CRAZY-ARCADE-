#pragma once
#include "stdafx.h"
#include "Define.h"

extern HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
extern HWND g_hWnd;
extern RECT crt;

class DbBuf
{
private:
	HWND myhWnd;
	HDC hDCMain;
	HDC hdcBuffer; // �޸𸮿� �׷��� dc
	HBITMAP hdcBmp; // hDCMain�� ����ϴ� �� ����
	Vector2 myXY;
public:
	DbBuf();
	~DbBuf();

	bool Initialize(); // �ʱ�ȭ
	void Progress(); // ó��
	void Render(); // �׸���
	void Destroy(); // �޸� ����
	HDC ReturnBackDC();
};