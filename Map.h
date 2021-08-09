#pragma once
#include "stdafx.h"
#include "Define.h"
#include "myJson.h"

extern HWND g_hWnd;
extern HINSTANCE hInst;

class Map
{
	typedef struct BlockMap
	{
		float fX = 0; // x��ǥ
		float fY = 0; // y��ǥ
		bool BlockExist = false; // ��� ���� ����
		bool BlockBreak = false; // ��� �ı� ����
		int nWidth = 0; // ���� ����
		int nHeight = 0; // ���� ����
	} IMAGE_INFO, * LPIMAGE_INFO;
	LPIMAGE_INFO BlockInformation; // ��� ����
	myJson parseJson;
public:
	Map();
	~Map();

	//Initialize()
	HRESULT Initialize(float m_fX, float m_fY, bool m_BlockExist, bool m_BlockBreak, int m_nWidth, int m_nHeight);
};