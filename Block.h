#pragma once
#include "stdafx.h"
#include "Define.h"
extern HINSTANCE hInst;
extern HWND g_hWnd;
extern RECT crt;
class Block
{
private:
	HWND myHWND;
	BITMAP bit;
	int bx, by;
	HDC Block1DC, Block2DC, Block3DC, Block4DC, Block5DC, BlockBreak1DC, BlockBreak2DC, BlockBreak3DC, BlockBreak4DC, BlockBreak5DC;
	HBITMAP Block1bit, Block2bit, Block3bit, Block4bit, Block5bit, BlockBreak1bit, BlockBreak2bit, BlockBreak3bit, BlockBreak4bit, BlockBreak5bit;
	HBITMAP Block1old, Block2old, Block3old, Block4old, Block5old, BlockBreak1old, BlockBreak2old, BlockBreak3old, BlockBreak4old, BlockBreak5old;
	BITMAP Blockbit, BlockBreakbit;
	int nBreakFrameX;
	int nBreakX, nBreakY, nGeneralX, nGeneralY;
	bool myActivation = false;
	int nConnection = 0;
public:
	Block();
	~Block();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc);
	void Render(HDC hdc, int nX, int nY);
};