#pragma once
#include "stdafx.h"
#include "Define.h"
#include "BlockManager.h"
#include "myJson.h"
extern HINSTANCE hInst;
extern HWND g_hWnd;
extern RECT crt;
class Block
{
private:
	HWND myHWND;
	BITMAP bit;
	int bx, by;
	HDC myDC;
	BlockManager* myBlockManager;
	HBITMAP Block1bit, Block2bit, Block3bit, Block4bit, Block5bit, BlockBreak1bit, BlockBreak2bit, BlockBreak3bit, BlockBreak4bit, BlockBreak5bit;
	HBITMAP Block1old, Block2old, Block3old, Block4old, Block5old, BlockBreak1old, BlockBreak2old, BlockBreak3old, BlockBreak4old, BlockBreak5old;
	BITMAP Blockbit, BlockBreakbit;
	myJson parseJson;
	HBITMAP Stone1bit, Stone2bit, Stone3bit, Stone4bit;
	HBITMAP Stone1old, Stone2old, Stone3old, Stone4old;
	BITMAP StoneBitmap, lowStoneBitmap;
	int nStoneX, nStoneY;
	RECT StoneRECT ,BlockRECT;
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
	int getWidth(const char* chFileName);
	int getHeight(const char* chFileName);
	float getX(const char* chFileName);
	float getY(const char* chFileName);
	float getX2(const char* chFileName);
	float getY2(const char* chFileName);
	int getBetweenX(const char* chFileName);
	int getBetweenY(const char* chFileName);
};