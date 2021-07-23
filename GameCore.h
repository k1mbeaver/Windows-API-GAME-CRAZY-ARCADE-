#pragma once
#include "stdafx.h"
#include "Define.h"
#include "DbBuf.h"
#include "background.h"

//������ ���ӿ� ���õ� Ŭ������ �ִ� ����� �߰��Ѵ�.
extern HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
extern HWND g_hWnd;
extern RECT crt;

class GameCore
{
private:
	//���õ� Ŭ������ �߰�
	HDC myHDC = GetDC(g_hWnd);
	DbBuf myDbBuf;
	BackGround myBackGround;
	Vector2 myXY;
	int nCurrent = 0; // ó�� �������� �� Initialize() �ʱ�ȭ�� ���� ����

public:
	GameCore();
	~GameCore();

	void Initialize(); // �ʱ�ȭ
	void Progress(); // ó��
	void Render(); // �׸���
	void Release();

};