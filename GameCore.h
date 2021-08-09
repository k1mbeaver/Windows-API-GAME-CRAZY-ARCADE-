#pragma once
#include "stdafx.h"
#include "Define.h"
#include "DbBuf.h"
#include "background.h"
#include "Player.h"
#include "Login.h"
#include "Lobby.h"
#include "Block.h"
#include "Statue.h"
#include "ImageManager.h"
#include "Collison.h"
#include "myJson.h"
//#include "ImageManager.h"

//������ ���ӿ� ���õ� Ŭ������ �ִ� ����� �߰��Ѵ�.
extern HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
extern HWND g_hWnd;
extern RECT crt;

class GameCore
{
private:
	//���õ� Ŭ������ �߰�
	HDC myHDC = GetDC(g_hWnd);
	DbBuf myDbBuf;
	BackGround myBackGround;
	Player myPlayer;
	Login myLogin;
	Lobby myLobby;
	Block myBlock;
	Statue myStatue;
	Collison myCollison;
	//ImageManager myImageManager;
	myJson parseJson;
	int nCurrent = 0;
	int nInitNum = 0;

public:
	GameCore();
	~GameCore();

	void Initialize(); // �ʱ�ȭ
	void Progress(); // ó��
	void Render(); // �׸���
	void Release();

};