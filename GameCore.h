#pragma once
#include "stdafx.h"
#include "Define.h"
#include "DbBuf.h"
//나머지 게임에 관련된 클래스가 있는 헤더를 추가한다.

class GameCore
{
private:
	//관련된 클래스들 추가
	HWND g_hWnd;
	HINSTANCE hInst;
	HDC myHDC;
	DbBuf myDbBuf;
	int nCurrent = 0; // 처음 실행했을 때 Initialize() 초기화를 위한 변수

public:
	GameCore();
	~GameCore();

	void Initialize(); // 초기화
	void Progress(); // 처리
	void Render(); // 그리기

};