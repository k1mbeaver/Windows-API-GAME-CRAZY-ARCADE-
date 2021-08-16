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
	nBombState = 1;
	myHDC = GetDC(g_hWnd);
	myLogin.Initialize(myHDC);
	myLobby.Initialize(myHDC);
	myBackGround.Initialize(myHDC);
	myPlayer.Initialize(myHDC);
	myShadow.Initialize(myHDC);
	myBlock.Initialize(myHDC);
	myBomb.Initialize(myHDC);
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
		if (nFrame == 5)
		{
			// 블록들과 캐릭터의 충돌
			for (int nIndex = 0; nIndex < 12; nIndex++)
			{
				for (int nJndex = 0; nJndex < 18; nJndex++)
				{
					if (myBlock.getBlockExist(nIndex, nJndex) == true)
					{
						myPlayer.pushbackPlayer(myCollison.SetNotInterSect(myPlayer.getPlayerRECT(myXY.myX, myXY.myY), myBlock.getBlockRect(nIndex, nJndex)));
					}
				}
			}
			nFrame = 0;
		}

		// 플레이중 스페이스 바를 누르고, 화면에 물풍선이 존재하지 않을 때
		if (nBomb == VK_SPACE && nBombState == 1)
		{
			myBomb.CreateBomb(myXY.myX, myXY.myY);
			// 버튼 초기화
			nBomb = 0;
			// 물풍선 남은 갯수
			nBombState = 0;
			// 타이머 시작
			nBombCount = 100;
		}

		// 타이머 줄이기
		nBombCount--;

		// 충돌 프레임
		nFrame++;
	}
}

void GameCore::Render()
{
	if (nCurrent == 0)
	{
		myLogin.Render(myDbBuf.ReturnBackDC());
		//myImageManager.Render("BazziDown1", myDbBuf.ReturnBackDC());
	}

	else if (nCurrent == 1)
	{
		myLobby.Render(myDbBuf.ReturnBackDC());
		myShadow.Render(myDbBuf.ReturnBackDC(), 1);
		myPlayer.Render(myDbBuf.ReturnBackDC(), 1);
	}

	else if (nCurrent == 2)
	{
		myBackGround.Render(myDbBuf.ReturnBackDC());
		myShadow.Render(myDbBuf.ReturnBackDC());
		myBlock.Render(myDbBuf.ReturnBackDC());

		// 물풍선 객체가 존재 할때
		if (nBombState == 0)
		{
			// 물풍선이 터지기 전
			if (nBombCount > 10)
			{
				myBomb.Render(myDbBuf.ReturnBackDC());
			}

			// 물풍선이 터지는 시점
			if (nBombCount < 10)
			{
				myBomb.BombRender(myDbBuf.ReturnBackDC());
				if (nBombCount == 0)
				{
					myBomb.DeleteBomb();
					nBombState = 1;
				}
			}
		}

		myPlayer.Render(myDbBuf.ReturnBackDC());
	}
	myDbBuf.Render();
}

void GameCore::Release()
{
	ReleaseDC(g_hWnd, myHDC);
}