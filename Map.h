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
		float fX = 0; // x좌표
		float fY = 0; // y좌표
		bool BlockExist = false; // 블록 존재 여부
		bool BlockBreak = false; // 블록 파괴 여부
		int nWidth = 0; // 블럭의 가로
		int nHeight = 0; // 블럭의 세로
	} IMAGE_INFO, * LPIMAGE_INFO;
	LPIMAGE_INFO BlockInformation; // 블록 정보
	myJson parseJson;
public:
	Map();
	~Map();

	//Initialize()
	HRESULT Initialize(float m_fX, float m_fY, bool m_BlockExist, bool m_BlockBreak, int m_nWidth, int m_nHeight);
};