#include "Login.h"

Login::Login()
{
	SetRect(&clickStart, 608, 61, 784, 268);
	//���� �� 608, 61 ���� �Ʒ� 608, 268 ������ �Ʒ� 784, 268 ������ �� 784, 61
}
Login::~Login() {}

void Login::Initialize(HDC hdc)
{
	myDC = CreateCompatibleDC(hdc);
	hbitmap = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\������ ����\\����� ����� ���͵�\\ũ������ �����̵�\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\loginBackGround.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	holdbitmap = (HBITMAP)SelectObject(myDC, hbitmap);
	myActivation = false;
	nConnection = 0;
	myKey.Initialize();
}

int Login::Progress(int& m_nCurrent)
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

void Login::Render(HDC hdc)
{
	GetObject(hbitmap, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	TransparentBlt(hdc, 0, 0, bx, by, myDC, 0, 0, bx, by, RGB(255, 0, 255));
}