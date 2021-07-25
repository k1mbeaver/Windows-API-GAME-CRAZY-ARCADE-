#pragma once
#include "stdafx.h"
#include "Define.h"
#include "DbBuf.h"
#include "background.h"
#include "Player.h"
#include "Shadow.h"
#include "Mark.h"
#include "Login.h"
#include "Lobby.h"

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
	Shadow myShadow;
	Mark myMark;
	Login myLogin;
	Lobby myLobby;
	Vector2 myXY;
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