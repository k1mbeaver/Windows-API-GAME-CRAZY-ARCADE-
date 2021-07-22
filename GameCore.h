#pragma once
#include "stdafx.h"
#include "Define.h"
#include "DbBuf.h"
//������ ���ӿ� ���õ� Ŭ������ �ִ� ����� �߰��Ѵ�.

class GameCore
{
private:
	//���õ� Ŭ������ �߰�
	HWND g_hWnd;
	HINSTANCE hInst;
	HDC myHDC;
	DbBuf myDbBuf;
	int nCurrent = 0; // ó�� �������� �� Initialize() �ʱ�ȭ�� ���� ����

public:
	GameCore();
	~GameCore();

	void Initialize(); // �ʱ�ȭ
	void Progress(); // ó��
	void Render(); // �׸���

};