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
	myPlayer.Initialize(myHDC);
	myDbBuf.Initialize();
}

void GameCore::Progress()
{

}

void GameCore::Render()
{
	myBackGround.Render(myDbBuf.ReturnBackDC());
	myPlayer.Render(myDbBuf.ReturnBackDC());
	myDbBuf.Render();
}

void GameCore::Release()
{
	ReleaseDC(g_hWnd, myHDC);
}