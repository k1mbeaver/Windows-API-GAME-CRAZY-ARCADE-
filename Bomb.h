#pragma once
#include "stdafx.h"
#include "Define.h"
#include "myJson.h"

extern HINSTANCE hInst;
extern HWND g_hWnd;
extern RECT crt;

typedef struct BombPosition
{
	float fX = 0; // x��ǥ
	float fY = 0; // y��ǥ
	bool myExist = false;
}BombInfo;

class Bomb
{
private:
	HWND myHWND;
	HDC myDC;
	int nBombCount = 0;
	int nBombSecond = 0;
	HBITMAP Bombbit, BombPopbit;
	HBITMAP Bombold, BombPopold;
	BITMAP Bombbitmap, BombPopbitmap;
	myJson parseJson;
	BombInfo myCreateBomb;
	int FrameX, BombFrameX = 0;
	int PopFrameX = 0;
public:
	Bomb();
	~Bomb();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc); // ��ǳ�� ��ġ
	void BombRender(HDC hdc); // ��ǳ�� ���Ľ�
	int getWidth(const char* chFileName);
	int getHeight(const char* chFileName);
	float getX();
	float getY();
	void CreateBomb(float m_fX, float m_fY);
	void DeleteBomb();
	bool ExistBomb();
	RECT getWidthPop();
	RECT getHeightPop();
};