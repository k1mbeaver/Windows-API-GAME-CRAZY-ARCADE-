#include "Lobby.h"

Lobby::Lobby() 
{
	SetRect(&clickStart, 848, 594, 1078, 660);
	//���� �� 848, 594 ���� �Ʒ� 848, 660 ������ �Ʒ� 1078, 660 ������ �� 1078, 594
}
Lobby::~Lobby() {}

void Lobby::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap1 = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\������ ����\\����� ����� ���͵�\\ũ������ �����̵�\\Crazy Arcade\\Crazy Arcade\\Image\\lobbyBackGround.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	holdbitmap1 = (HBITMAP)SelectObject(myDC, hbitmap1);
	//hbitmap2 = (HBITMAP)LoadImage(NULL, L"C:\\Users\\USER\\Desktop\\������ ����\\����� ����� ���͵�\\ũ������ �����̵�\\Crazy Arcade\\Crazy Arcade\\Image\\player\\down\\down1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	//holdbitmap2 = (HBITMAP)SelectObject(myDC, hbitmap2);
	myActivation = false;
	nConnection = 0;
}

int Lobby::Progress(int &m_nCurrent)
{
	if (PtInRect(&clickStart, ptMouse))
	{
		if (myKey.isOnceKeyDown(VK_LBUTTON))
		{
			m_nCurrent++;
			return 1;
		}
	}

	return 0;
}

void Lobby::Render(HDC hdc)
{
	GetObject(hbitmap1, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	TransparentBlt(hdc, 0, 0, bx, by, myDC, 0, 0, bx, by, RGB(255, 0, 255));


	//SelectObject(myDC, holdbitmap1);
	//DeleteObject(hbitmap1);
	//DeleteDC(myDC);
}