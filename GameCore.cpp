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
	myLogin.Initialize(myHDC);
	myLobby.Initialize(myHDC);
	myBackGround.Initialize(myHDC);
	myShadow.Initialize(myHDC);
	myMark.Initialize(myHDC);
	myPlayer.Initialize(myHDC);
	myBlock.Initialize(myHDC);
	myStatue.Initialize(myHDC);
	myDbBuf.Initialize();
}

void GameCore::Progress()
{
	if (nCurrent == 0)
	{
		nInitNum = myLogin.Progress(nCurrent);
		if (nInitNum == 1)
		{
			myDbBuf.DeleteScreen();
		}
	}
	if (nCurrent == 1)
	{
		nInitNum = myLobby.Progress(nCurrent);
		if (nInitNum == 1)
		{
			myDbBuf.DeleteScreen();
		}
	}

	else if (nCurrent == 2)
	{
		myCollison.SetNotInterSect(myPlayer.getPlayerRECT(), myStatue.getStatue3RECT());
	}
}

void GameCore::Render()
{
	if (nCurrent == 0)
	{
		myLogin.Render(myDbBuf.ReturnBackDC());
	}

	else if (nCurrent == 1)
	{
		myLobby.Render(myDbBuf.ReturnBackDC());
		myShadow.Render(myDbBuf.ReturnBackDC(), 270, 140);
		myPlayer.Render(myDbBuf.ReturnBackDC(), 270, 140);
	}

	else if (nCurrent == 2)
	{
		myBackGround.Render(myDbBuf.ReturnBackDC());
		myBlock.Render(myDbBuf.ReturnBackDC());
		myStatue.Render(myDbBuf.ReturnBackDC());
		myShadow.Render(myDbBuf.ReturnBackDC());
		myMark.Render(myDbBuf.ReturnBackDC());
		myPlayer.Render(myDbBuf.ReturnBackDC());
	}
	myDbBuf.Render();
}

void GameCore::Release()
{
	ReleaseDC(g_hWnd, myHDC);
}