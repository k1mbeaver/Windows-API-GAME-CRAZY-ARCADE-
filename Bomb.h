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
	string filename;
	int nWidth, nHeight;
	float fX, fY;
	BITMAP bit;
	int bx, by;
	int nBombCount = 0;
	int nBombSecond = 0;
	bool BombExist;
	HBITMAP Bombbit, BombPopbit;
	HBITMAP Bombold, BombPopold;
	BITMAP Bombbitmap, BombPopbitmap;
	myJson parseJson;
	int FrameX;
	bool myActivation = false;
	int nConnection = 0;
public:
	Bomb();
	~Bomb();
	void Initialize(HDC hdc);
	void Progress();
	void Render(HDC hdc, float fX, float fY); // ��ǳ�� ��ġ
	void BombRender(HDC hdc, float fX, float fY); // ��ǳ�� ���Ľ�
	int getWidth(const char* chFileName);
	int getHeight(const char* chFileName);
	float getX();
	float getY();
	BombInfo* CreateBomb(float m_fX, float m_fY);
	void DeleteBomb(BombInfo* m_myCreateBomb);
	bool ExistBomb(BombInfo* m_myCreateBomb);
};