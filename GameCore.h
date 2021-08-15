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

//나머지 게임에 관련된 클래스가 있는 헤더를 추가한다.
extern HINSTANCE hInst;                                // 현재 인스턴스입니다.
extern HWND g_hWnd;
extern RECT crt;

class GameCore
{
private:
	//관련된 클래스들 추가
	HDC myHDC = GetDC(g_hWnd);
	DbBuf myDbBuf;
	Shadow myShadow;
	BackGround myBackGround;
	Player myPlayer;
	Login myLogin;
	Lobby myLobby;
	Block myBlock;
	Bomb myBomb;
	Collison myCollison;
	myJson parseJson;
	int nCurrent = 0;
	int nFrame = 0;
	int nInitNum = 0;
	int nBombCount = 0;
	Block* myMap[12][27];
	BombInfo* myCreateBomb;
public:
	GameCore();
	~GameCore();

	void Initialize(); // 초기화
	void Progress(); // 처리
	void Render(); // 그리기
	void Release();

};