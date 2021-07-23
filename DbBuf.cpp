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

	HDC hdc = GetDC(myhWnd);
	PatBlt(hdcBuffer, 0, 0, crt.right, crt.bottom, BLACKNESS); 
	// ���� ��� �ʱ�ȭ �Լ� : �ش� DC�� ��Ʈ�� ������ ���� ���·� �ʱ�ȭ �ϴ� �� ��� ( ���� : �귯�� ), ������ �簢������ ���� DC�� ���õ� �귯���� ä��
	// �ʱ�ȭ�� �ϰ� �̹����� �Ѹ�

	BitBlt(hDCMain, 0, 0, crt.right, crt.bottom, hdcBuffer, 0, 0, SRCCOPY);
	// ��� ���� �Լ� : �޸� DC�� ��Ʈ���� ���� DC�� ��Ӻ����ϴ� �Լ�
	// ����ۿ� ������


	ReleaseDC(myhWnd, hDCMain);
}

void DbBuf::Destroy()
{

}

void DbBuf::ImageDraw(HDC I_hdc, int fX, int fY)
{
	HBITMAP MyBitMap, OldBitMap;

	HDC NewDC = CreateCompatibleDC(I_hdc);
	MyBitMap = (HBITMAP)LoadImage(NULL, L"../image/right.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	OldBitMap = (HBITMAP)SelectObject(NewDC, MyBitMap);
	BitBlt(I_hdc, fX, fY, 192, 192, NewDC, 0, 0, SRCCOPY);

	SelectObject(NewDC, OldBitMap);
	DeleteObject(MyBitMap);
}