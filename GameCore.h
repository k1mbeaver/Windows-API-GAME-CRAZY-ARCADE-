#pragma once
#include "stdafx.h"
//나머지 게임에 관련된 클래스가 있는 헤더를 추가한다.

class GameCore
{
private:
	//관련된 클래스들 추가
	HDC myHDC;
	int nCurrent = 0; // 처음 실행했을 때 Initialize() 초기화를 위한 변수

public:
	GameCore();
	~GameCore();

	void Initialize(); // 초기화
	void Prograss(); // 처리
	void Render(); // 그리기

};