#include "Image.h"

Image::Image()
{
}

HRESULT Image::Initialize(string m_strFileName, int nWidth, int nHeight, float fX, float fY, bool m_isTrans)
{
	HDC hdc = GetDC(g_hWnd);

	imageInformation = new IMAGE_INFO;
	imageInformation->hMemDC = CreateCompatibleDC(hdc); 
	imageInformation->hBit = (HBITMAP)LoadImage(hInst, m_strFileName.c_str(), IMAGE_BITMAP, nWidth, nHeight, LR_LOADFROMFILE); // 이부분부터 문제가 있음
	imageInformation->hObit = (HBITMAP)SelectObject(imageInformation->hMemDC, imageInformation->hBit);
	imageInformation->nWidth = nWidth;
	imageInformation->nHeight = nHeight;
	imageInformation->fX = fX;
	imageInformation->fY = fY;

	// 파일 이름
	strFileName = m_strFileName;

	// transparent 설정
	isTrans = m_isTrans;

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}

void Image::Render(HDC hdc, float fX, float fY)
{
	// isTrans = true
	if (isTrans)
	{
		TransparentBlt(
			hdc, 
			fX, 
			fY, 
			imageInformation->nWidth, 
			imageInformation->nHeight, 
			imageInformation->hMemDC, 
			0, 
			0, 
			imageInformation->nWidth,
			imageInformation->nHeight,
			RGB(255, 0, 255));
	}

	// isTrans = false
	else
	{
		BitBlt(hdc, fX, fY, imageInformation->nWidth, imageInformation->nHeight, imageInformation->hMemDC, 0, 0, SRCCOPY);
	}
}