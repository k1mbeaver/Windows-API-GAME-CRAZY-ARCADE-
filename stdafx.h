// stdafx.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 프로그램에 필요한 추가 헤더
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cassert>
#include <map>
#include <string>
#include <functional>
using namespace std;

//내가 만든 헤더
#include "structure.h"
#include "ImageManager.h"

// SAFE DELETE
#define SAFE_DELETE(p)          {if(p)  {delete   (p);   (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p)    {if(p)  {delete[] (p);   (p)=NULL;}}
#define SAFE_RELEASE(p)         {if(p)  {(p)->release(); (p)=NULL;}}

//싱글톤
#define IMAGEMANAGER ImageManager::getSingleton()

// 전역 변수 선언
struct Vector2
{
    float myX;
    float myY;
};

extern POINT ptMouse;
extern Vector2 myXY;
extern DWORD currentTime;
extern float dDT;
extern float fFrameDelay;
extern int nPlayerWay, nWay;
