#pragma once

// -----------------------------------------------------------------------------
// Name: Struct
// Desc: 
// -----------------------------------------------------------------------------
enum IMAGE_LOAD_KIND
{
    LOAD_RESOURCE, // ���ҽ��κ��� ����
    LOAD_FILE,     // ���Ϸκ��� ����
    LOAD_EMPTY,    // �׳� ����
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

    DWORD resID;        // ���ҽ� ���̵�
    HDC hMemDC;         // �޸� DC
    HBITMAP hBit;       // ��Ʈ��(���ο� ��Ʈ�� �ڵ�)
    HBITMAP hOBit;      // �õ� ��Ʈ��(���� ��Ʈ�� �ڵ�)
    float x;            // x��ǥ
    float y;            // y��ǥ
    int width;          // �̹��� ����ũ��
    int height;         // �̹��� ���� ũ��

    BYTE loadType;      // Ÿ��
} IMAGE_INFO, * LPIMAGE_INFO;