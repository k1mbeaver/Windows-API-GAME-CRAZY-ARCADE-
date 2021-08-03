#pragma once
#include "stdafx.h"
#include "Define.h"

extern HWND g_hWnd;
extern HINSTANCE hInst;

class Image
{
	typedef struct tagImage
	{
		tagImage()
		{
			hMemDC = nullptr; // �޸� DC
			hBit = nullptr; // ��Ʈ�� (���ο� ��Ʈ�� �ڵ�)
			hObit = nullptr; // �õ� ��Ʈ�� (���� ��Ʈ�� �ڵ�)
			fX = 0; // x��ǥ
			fY = 0; // y��ǥ
			nWidth = 0; // ����
			nHeight = 0; // ����
			nCurrentFrameX = 0;
			nCurrentFrameY = 0;
			nMaxFrameX = 0;
			nMaxFrameY = 0;
			nFrameWidth = 0;
			nFrameHeight = 0;
		}
		HDC hMemDC; // �޸� DC
		HBITMAP hBit; // ��Ʈ�� (���ο� ��Ʈ�� �ڵ�)
		HBITMAP hObit; // �õ� ��Ʈ�� (���� ��Ʈ�� �ڵ�)
		float fX; // x��ǥ
		float fY; // y��ǥ
		int nWidth; // ����
		int nHeight; // ����
		int nCurrentFrameX; // ���� ������ X
		int nCurrentFrameY; // ���� ������ Y
		int nMaxFrameX; // �ִ� ������ X
		int nMaxFrameY; // �ִ� ������ Y
		int nFrameWidth;
		int nFrameHeight;
	} IMAGE_INFO, *LPIMAGE_INFO;
	LPIMAGE_INFO imageInformation; // �̹��� ����
	string strFileName; // �̹��� ��� �̸�
	bool isTrans; // TransParent ����Ұ���
public:
	Image();
	~Image();

	//Initialize()
	HRESULT Initialize(string m_strFileName, int nWidth, int nHeight, float fX, float fY, bool m_isTrans);

	//Render()
	void Render(HDC hdc, float fX, float fY);

	// DC�� ���´�
	HDC getMemDC() { return imageInformation->hMemDC; }

	// �̹����� ��ǥ ��� �� ����, �̹����� ���� ��ǥ ����, �̹����� ���μ��� ���
	
	// �̹����� ��ǥ 
	float getX() { return imageInformation->fX; }
	void getX(float fX) { imageInformation->fX = fX; }
	float getY() { return imageInformation->fY; }
	void getY(float fY) { imageInformation->fY = fY; }

	// �̹����� ����
	void setCenter(float fX, float fY)
	{
		imageInformation->fX = fX - (imageInformation->nWidth / 2);
		imageInformation->fY = fY - (imageInformation->nHeight / 2);
	}

	// ���� X
	float getCenterX()
	{
		return imageInformation->nMaxFrameX <= 0 ? imageInformation->fX + (imageInformation->nWidth / 2) : imageInformation->fX + (imageInformation->nFrameWidth / 2);
		/*
		if (imageInformation->nMaxFrameX <= 0) return imageInformation->fX + (imageInformation->nWidth / 2);
		else return imageInformation->fX + (imageInformation->nFrameWidth / 2);
		*/
	}

	// ���� Y
	float getCenterY()
	{
		return imageInformation->nMaxFrameY <= 0 ? imageInformation->fY + (imageInformation->nHeight / 2) : imageInformation->fY + (imageInformation->nFrameHeight / 2);
		/*
		if (imageInformation->nMaxFrameY <= 0) return imageInformation->fY + (imageInformation->nHeight / 2);
		else return imageInformation->fY + (imageInformation->nFrameHeight / 2);
		*/
	}

	// ����, ���� ũ�� ���
	int getWidth() { return imageInformation->nWidth; }
	int getHeight() { return imageInformation->nHeight; }

	// �浹 ó�� (�ٿ�� �ڽ�)
	RECT getBoundingBOX()
	{
		RECT rc;
		if (imageInformation->nFrameWidth != 0 && imageInformation->nFrameHeight != 0)
		{
			rc = makeRect(imageInformation->fX, imageInformation->fY, imageInformation->nFrameWidth, imageInformation->nFrameHeight);
		}

		else
		{
			rc = makeRect(imageInformation->fX, imageInformation->fY, imageInformation->nWidth, imageInformation->nHeight);
		}
	}

	RECT makeRect(float fX, float fY, int nWidth, int nHeight)
	{
		RECT rc = { fX, fY, fX + nWidth, fY + nHeight };
		return rc;
	}
};