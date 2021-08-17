#pragma once
#include "stdafx.h"
#include "Define.h"
#include "DbBuf.h"
#include "background.h"
#include "Player.h"
#include "Login.h"
#include "Lobby.h"
#include "Block.h"
#include "Shadow.h"
#include "Collison.h"
#include "Bomb.h"
#include "myJson.h"
#include "Wave.h"

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
	Shadow myShadow;
	BackGround myBackGround;
	Player myPlayer;
	Login myLogin;
	Lobby myLobby;
	Block myBlock;
	Bomb myBomb;
	Wave myWave;
	Collison myCollison;
	myJson parseJson;
	int nCurrent = 0;
	int nFrame = 0;
	int nInitNum = 0;
	int nBombCount = 0; // ��ǳ�� Ÿ�̸�
	int nBombState = 0;
	int nPopFrameX = 0; // ���ٱ� ������
	Block* myMap[12][27];
public:
	GameCore();
	~GameCore();

	void Initialize(); // �ʱ�ȭ
	void Progress(); // ó��
	void Render(); // �׸���
	void Release();
};