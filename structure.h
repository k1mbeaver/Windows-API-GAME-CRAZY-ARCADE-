#pragma once

// -----------------------------------------------------------------------------
// Name: Struct
// Desc: 
// -----------------------------------------------------------------------------
enum IMAGE_LOAD_KIND
{
    LOAD_RESOURCE, // 리소스로부터 생성
    LOAD_FILE,     // 파일로부터 생성
    LOAD_EMPTY,    // 그냥 생성
    LOAD_END
};

typedef struct tagImage
{
    tagImage()
    {
        resID = 0;
        hMemDC = nullptr;
        hBit = nullptr;
        hOBit = nullptr;
        x = 0;
        y = 0;
        width = 0;
        height = 0;
        loadType = LOAD_RESOURCE;
    }

    DWORD resID;        // 리소스 아이디
    HDC hMemDC;         // 메모리 DC
    HBITMAP hBit;       // 비트맵(새로운 비트맵 핸들)
    HBITMAP hOBit;      // 올드 비트맵(기존 비트맵 핸들)
    float x;            // x좌표
    float y;            // y좌표
    int width;          // 이미지 가로크기
    int height;         // 이미지 세로 크기

    BYTE loadType;      // 타입
} IMAGE_INFO, * LPIMAGE_INFO;