#pragma once
#include "stdafx.h"
#include "Define.h"

extern HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
extern HWND g_hWnd;
extern RECT crt;

class BitmapImage
{
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

public:
    BitmapImage();
    ~BitmapImage();

    /* init() ==================================*/
    // �� ��Ʈ�� �ʱ�ȭ
    HRESULT init(int width, int height);
    // �̹��� ���ҽ� �ʱ�ȭ
    HRESULT init(const DWORD resID, int width, int height, bool isTrans);

    //const char* fileName
    // �̹��� ���� �ʱ�ȭ
    HRESULT init(const char* fileName, int width, int height, bool isTrans);
    // ������ �̹��� ���Ϸ� �ʱ�ȭ
    HRESULT init(const char* fileName, int width, int height, int frameX, int frameY, bool isTrans);
    HRESULT init(const char* fileName, int x, int y, int width, int height, int frameX, int frameY, bool isTrans);

    // ������
    void release();

    /* render =======================================================================================================*/
    //�׸��� �༮(�Ϲ� ����)
    void render(HDC hdc);
    void render(HDC hdc, int destX, int destY);
    void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
    void renderStretch(HDC hdc, int destX, int destY, int destWidth, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight);

    // �츮 �߰�
    // ���� ����
    void alphaRender(HDC hdc, BYTE alpha);
    void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
    void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

    //�׸��� �༮(������ ����)
    void frameRender(HDC hdc, int destX, int destY);
    void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

    //�׸��� �༮(���� ����)
    void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

    /* DC�� ���´� ============================================================================================= */
    inline HDC getMemDC() { return m_imageInfo->hMemDC; }

    /* �̹����� ��ǥ �ټ�, �̹����� ���� ��ǥ ����, �̹����� ���μ��� ũ�� ��� ================================== */
    // �̹��� ��ǥ x ���
    inline float getX() { return m_imageInfo->x; }
    inline void setX(float x) { m_imageInfo->x = x; }

    // �̹��� ��ǥ y ���
    inline float getY() { return m_imageInfo->y; }
    inline void setY(float y) { m_imageInfo->y = y; }

    // �̹��� ���� ��ǥ ����
    inline void setCenter(float x, float y)
    {
        m_imageInfo->x = x - (m_imageInfo->width / 2);
        m_imageInfo->y = y - (m_imageInfo->height / 2);
    }

    // ���� ���� ũ�� ���
    inline int getWidth() { return m_imageInfo->width; }
    inline int getHeight() { return m_imageInfo->height; }


    /* �ٿ�� �ڽ� (�浹��) ======================================================================================== */
    /*
    inline RECT getBoundingBox()
    {
        RECT rc;
        if (m_imageInfo->frameWidth != 0 && m_imageInfo->frameHeight != 0)
        {
            rc = makeRect(m_imageInfo->x, m_imageInfo->y, m_imageInfo->frameWidth, m_imageInfo->frameHeight);
        }
        else
        {
            rc = makeRect(m_imageInfo->x, m_imageInfo->y, m_imageInfo->width, m_imageInfo->height);
        }
        return rc;
    }
    */



private:
    LPIMAGE_INFO m_imageInfo; //�̹��� ����
    char* m_fileName; //�̹��� ��� �̸�
    bool isTrans; // ������ ���� ���� (����)

                           //�츮�߰�
    BLENDFUNCTION m_blendFunc; //���� ���带 ���� ����
    LPIMAGE_INFO m_blendImage; //���� ���带 ����ϱ� ���� �̹��� ����
};