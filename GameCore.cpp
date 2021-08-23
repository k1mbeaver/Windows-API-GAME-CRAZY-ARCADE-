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
	nPlayerState = 0;
	nBombState = 1;
	myHDC = GetDC(g_hWnd);
	myLogin.Initialize(myHDC);
	myLobby.Initialize(myHDC);
	myBackGround.Initialize(myHDC);
	myPlayer.Initialize(myHDC);
	myShadow.Initialize(myHDC);
	myBlock.Initialize(myHDC);
	myBomb.Initialize(myHDC);
	myWave.Initialize(myHDC);
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
		// ��ϰ� �浹ó��
		if (nFrame == 1)
		{
			for (int nIndex = 0; nIndex < 12; nIndex++)
			{
				for (int nJndex = 0; nJndex < 18; nJndex++)
				{
					if (myBlock.getBlockExist(nIndex, nJndex) == true)
					{
						// ��ϵ�� ĳ������ �浹
						myPlayer.pushbackPlayer(myCollison.SetNotInterSect(myPlayer.getPlayerRECT(myXY.myX, myXY.myY), myBlock.getBlockRect(nIndex, nJndex)));

						// ��ϵ�� ���ٱ��� �浹
						if (nBombCount < 20)
						{
							myBlock.PopBlock(myCollison.SetNotInterSect(myBlock.getBlockRect(nIndex, nJndex), myBomb.getHeightPop()), nIndex, nJndex); // ����
							myBlock.PopBlock(myCollison.SetNotInterSect(myBlock.getBlockRect(nIndex, nJndex), myBomb.getWidthPop()), nIndex, nJndex); // ����
						}
					}
				}
			}
			nFrame = 0;
		}

		// �÷����� �����̽� �ٸ� ������, ȭ�鿡 ��ǳ���� �������� ���� ��
		if (nBomb == VK_SPACE && nBombState == 1)
		{
			myBomb.CreateBomb(myXY.myX, myXY.myY);
			// ��ư �ʱ�ȭ
			nBomb = 0;
			// ��ǳ�� ���� ����
			nBombState = 0;
			// Ÿ�̸� ����
			nBombCount = 150;
			// ���ٱ� ������ �ʱ�ȭ
			myWave.InitializeFrameX();
		}

		// ���ٱ�� ĳ������ �浹ó��
		if (nBombCount < 20 && (myCollison.SetNotInterSect(myPlayer.getPlayerRECT(myXY.myX, myXY.myY), myBomb.getHeightPop()) != None 
			|| myCollison.SetNotInterSect(myPlayer.getPlayerRECT(myXY.myX, myXY.myY), myBomb.getWidthPop()) != None)) // ��ǳ���� ������ ���ٱⰡ ���ö�, ĳ���Ͱ� ���ٱ��� ���� �Ǵ� ���ο� �浹��
		{
			nPlayerState = 1; // �÷��̾��� �Ӽ��� �������� ����
			nPlayerTrap = 300; // �����ִ� �ð� ī��Ʈ ����
		}

		if (nPlayerState == 1 && nPlayerTrap == 0) // �����ִ� ���¿��� �ð� �ٵǸ�
		{
			nPlayerState = 2; // �÷��̾��� �Ӽ��� ������� ����
			nCurrent = 3; // ���� ���� 
			nGameOverCount = 300; // ���� ���� ȭ�� ī��Ʈ ����
			myDbBuf.DeleteScreen(); // ȭ�� �ʱ�ȭ
		}

		// ��� �ٻѼ��� ���� ������
		if (myCollison.SetNotInterSect(myPlayer.getPlayerRECT(myXY.myX, myXY.myY), myBackGround.GameOverRECT()) != None)
		{
			nCurrent = 3;
			nGameOverCount = 300; // ���� ���� ȭ�� ī��Ʈ ����
			myDbBuf.DeleteScreen(); // ȭ�� �ʱ�ȭ
		}

		// Ÿ�̸� ���̱�
		nBombCount--;
		nPlayerTrap--;

		// �浹 ������
		nFrame++;
	}

	else if (nCurrent == 3) // ���� ����
	{
		if (nGameOverCount == 0) // ���� ���� ī��Ʈ�� �ٵǸ�
		{
			myDbBuf.DeleteScreen(); // ȭ�� �ʱ�ȭ
			DestroyWindow(g_hWnd); // ����
		}
		// ���� ���� ī��Ʈ ���̱�
		nGameOverCount--;
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
		myShadow.Render(myDbBuf.ReturnBackDC(), nPlayerState, 1);
		// ��ǳ�� ��ü�� ���� �Ҷ�
		if (nBombState == 0)
		{
			// ��ǳ���� ������ ����
			if (nBombCount < 20)
			{
				myWave.Render(myDbBuf.ReturnBackDC(), myBomb.getX(), myBomb.getY()); // ���ٱ� 4����
			}
		}

		myBlock.Render(myDbBuf.ReturnBackDC());

		// ��ǳ�� ��ü�� ���� �Ҷ�
		if (nBombState == 0)
		{
			// ��ǳ���� ������ ��
			if (nBombCount > 20)
			{
				myBomb.Render(myDbBuf.ReturnBackDC()); // ��ǳ�� �ִϸ��̼� ���
			}

			// ��ǳ���� ������ ����
			if (nBombCount < 20)
			{
				myBomb.BombRender(myDbBuf.ReturnBackDC()); // ���ٱ� ���
				if (nBombCount == 0)
				{
					myBomb.DeleteBomb(); // ��ǳ�� �ʱ�ȭ
					nBombState = 1; // ��ǳ�� ���� 1���� �ʱ�ȭ
				}
			}
		}

		myPlayer.Render(myDbBuf.ReturnBackDC(), nPlayerState, 1);
	}

	else if (nCurrent == 3)
	{
		myBackGround.GameOver(myDbBuf.ReturnBackDC());
	}
	myDbBuf.Render();
}

void GameCore::Release()
{
	ReleaseDC(g_hWnd, myHDC);
}