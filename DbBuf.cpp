#include "DbBuf.h"

DbBuf::DbBuf()
{

}

DbBuf::~DbBuf()
{

}


bool DbBuf::Initialize()
{
	myhWnd = g_hWnd;
	GetClientRect(myhWnd, &crt); // �ʺ� ���ϱ� ����, crt.right, crt.bottom ���

	if (myhWnd == NULL)
		return false;

	hDCMain = GetDC(myhWnd); // DC�� ������
	hdcBuffer = CreateCompatibleDC(hDCMain); // BackBuffer�� ���� DC�� ���� 
	hdcBmp = CreateCompatibleBitmap(hDCMain, crt.right, crt.bottom); // ������ ȭ�鿡 �ִ� ��� ������ ����
	SelectObject(hdcBuffer, (HBITMAP)hdcBmp);
	ReleaseDC(myhWnd, hDCMain); // ������ DC�� ����

	myXY.myX = 10;
	myXY.myY = 10;

	SetTimer(myhWnd, 0, 10, NULL);

	return true;
}

void DbBuf::Progress()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) myXY.myX -= 1.0f;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) myXY.myX += 1.0f;
}

void DbBuf::Render()
{
	myhWnd = g_hWnd;
	GetClientRect(myhWnd, &crt); // �ʺ� ���ϱ� ����, crt.right, crt.bottom ���

	hDCMain = GetDC(myhWnd);

	BitBlt(hDCMain, 0, 0, crt.right, crt.bottom, hdcBuffer, 0, 0, SRCCOPY);
	// ��� ���� �Լ� : �޸� DC�� ��Ʈ���� ���� DC�� ��Ӻ����ϴ� �Լ�
	// ����ۿ� ������


	ReleaseDC(myhWnd, hDCMain);
}

void DbBuf::Destroy()
{

}

HDC DbBuf::ReturnBackDC()
{
	return hdcBuffer;
}

void DbBuf::DeleteScreen()
{
	PatBlt(hdcBuffer, 0, 0, crt.right, crt.bottom, BLACKNESS);
	// ���� ��� �ʱ�ȭ �Լ� : �ش� DC�� ��Ʈ�� ������ ���� ���·� �ʱ�ȭ �ϴ� �� ��� ( ���� : �귯�� ), ������ �簢������ ���� DC�� ���õ� �귯���� ä��
	// �ʱ�ȭ�� �ϰ� �̹����� �Ѹ�
}