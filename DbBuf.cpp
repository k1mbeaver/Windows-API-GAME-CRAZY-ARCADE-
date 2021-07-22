#include "DbBuf.h"

DbBuf::DbBuf()
{

}

DbBuf::~DbBuf()
{

}


void DbBuf::Initialize()
{
	GetClientRect(g_hWnd, &crt);

	hdcBuffer = CreateCompatibleDC(hDCMain);
	hdcBmp = CreateCompatibleBitmap(hdcBuffer, crt.right, crt.bottom);
	OldBmp = (HBITMAP)SelectObject(hdcBuffer, hdcBmp);
}

void DbBuf::Progress()
{

}

void DbBuf::Render()
{
	BitBlt(hDCMain, 0, 0, crt.right, crt.bottom, hdcBuffer, 0, 0, SRCCOPY);
	DeleteObject(SelectObject(hdcBuffer, OldBmp));
	DeleteDC(hdcBuffer);
}