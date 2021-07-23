// 01. GameCore
#include "GameCore.h"


GameCore::GameCore()
{
}

GameCore::~GameCore()
{
	Release();
}

void GameCore::Initialize()
{
	nCurrent = 0; // 0 = main, 1 = GameStart, 2 = GameMenu, 3 = GameOver
	myHDC = GetDC(g_hWnd);
	myBackGround.Initialize(myHDC);
	myDbBuf.Initialize();
	LineTo(myHDC, 100, 800);
	Rectangle(myHDC, 300, 300, 500, 500);
	Ellipse(myHDC, 200, 200, 50, 50);
}

void GameCore::Progress()
{

}

void GameCore::Render()
{
	myBackGround.Render(myHDC);
	myDbBuf.Render();
}

void GameCore::Release()
{
	ReleaseDC(g_hWnd, myHDC);
}