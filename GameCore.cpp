// 01. GameCore
#include "GameCore.h"


GameCore::GameCore()
{
}

GameCore::~GameCore()
{
}

void GameCore::Initialize()
{
	nCurrent = 0; // 0 = main, 1 = GameStart, 2 = GameMenu, 3 = GameOver
	myHDC = GetDC(g_hWnd);
	myDbBuf.Initialize();
}

void GameCore::Progress()
{

}

void GameCore::Render()
{
	myDbBuf.Render();
}