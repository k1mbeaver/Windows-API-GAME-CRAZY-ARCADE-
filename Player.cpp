#include "Player.h"
Player::Player() {}
Player::~Player() {}

void Player::Initialize(HDC hdc)
{
	myXY.myX = 500;
	myXY.myY = 500;

	// Initialize���� �� �̹������� ������ ������ ������?

	parseJson.Initialize();
	myDC = CreateCompatibleDC(hdc);
	Downbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BazziDown").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Upbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BazziUp").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Leftbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BazziLeft").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Rightbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BazziRight").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Jumpbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BazziJump").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void Player::Progress()
{
}

void Player::Render(HDC hdc) // ���� �÷��� ȭ�� ��
{
	if (nPlayerWay == 0)
	{
		Downold = (HBITMAP)SelectObject(myDC, Downbit);
		TransparentBlt(hdc, myXY.myX, myXY.myY, getWidth("BazziDown"), getHeight("BazziDown"), myDC, 0, 0, getWidth("BazziDown"), getHeight("BazziDown"), RGB(255, 0, 255));
	}
	switch (nPlayerWay)
	{
	case VK_LEFT:
		Leftold = (HBITMAP)SelectObject(myDC, Leftbit);
		TransparentBlt(hdc, myXY.myX, myXY.myY, getWidth("BazziLeft"), getHeight("BazziLeft"), myDC, LRFrameX, 0, getWidth("BazziLeft"), getHeight("BazziLeft"), RGB(255, 0, 255));
		break;
	case VK_UP:
		Upold = (HBITMAP)SelectObject(myDC, Upbit);
		TransparentBlt(hdc, myXY.myX, myXY.myY, getWidth("BazziUp"), getHeight("BazziUp"), myDC, UDFrameX, 0, getWidth("BazziUp"), getHeight("BazziUp"), RGB(255, 0, 255));
		break;
	case VK_RIGHT:
		Rightold = (HBITMAP)SelectObject(myDC, Rightbit);
		TransparentBlt(hdc, myXY.myX, myXY.myY, getWidth("BazziRight"), getHeight("BazziRight"), myDC, LRFrameX, 0, getWidth("BazziRight"), getHeight("BazziRight"), RGB(255, 0, 255));
		break;
	case VK_DOWN:
		Downold = (HBITMAP)SelectObject(myDC, Downbit);
		TransparentBlt(hdc, myXY.myX, myXY.myY, getWidth("BazziDown"), getHeight("BazziDown"), myDC, UDFrameX, 0, getWidth("BazziDown"), getHeight("BazziDown"), RGB(255, 0, 255));

		break;
	}

	// �ִϸ��̼� ����� ���� ������
	fFrameDelay += dDT;
	if (fFrameDelay > 0.1f)
	{
		fFrameDelay = 0;
		UDFrameX += 64;
		LRFrameX += 64;
		if (UDFrameX >= 512)
		{
			UDFrameX = 0;
		}

		if (LRFrameX >= 384)
		{
			LRFrameX = 0;
		}
	}
}

void Player::Render(HDC hdc, int nState) // �κ��
{
	Jumpold = (HBITMAP)SelectObject(myDC, Jumpbit);
	TransparentBlt(hdc, getX("BazziJump"), getY("BazziJump"), getWidth("BazziJump"), getHeight("BazziJump"), myDC, JumpFrameX, 0, getWidth("BazziJump"), getHeight("BazziJump"), RGB(255, 0, 255));

	fFrameDelay += dDT;
	if (fFrameDelay > 0.5f)
	{
		fFrameDelay = 0;
		JumpFrameX += 64;
		if (JumpFrameX >= 512)
		{
			JumpFrameX = 0;
		}

	}
}

int Player::getWidth(const char* chFileName)
{
	int nWidth;
	nWidth = parseJson.getMyObjectWidth(chFileName);

	return nWidth;
}

int Player::getHeight(const char* chFileName)
{
	int nHeight;
	nHeight = parseJson.getMyObjectHeight(chFileName);

	return nHeight;
}

float Player::getX(const char* chFileName)
{
	float fX;
	fX = parseJson.getMyObjectX(chFileName);

	return fX;
}

float Player::getY(const char* chFileName)
{
	float fY;
	fY = parseJson.getMyObjectY(chFileName);

	return fY;
}

RECT& Player::getPlayerRECT(float fX, float fY)
{
	PlayerRECT.left = fX;
	PlayerRECT.top = fY + 40;
	PlayerRECT.right =  PlayerRECT.left + getWidth("BazziDown");
	PlayerRECT.bottom = PlayerRECT.top + getHeight("BazziDown") - 40;

	return PlayerRECT;
}


// �÷��̾�� ���𰡰� �浹�Ͽ��� �� �����Ű�� �ʰ� �о��
void Player::pushbackPlayer(Direction myDirection)
{
	// ������ ������ ���� ���� ũ�⸦ ������.
	int nInterW = rcInter.right - rcInter.left;
	int nInterH = rcInter.bottom - rcInter.top;

	// ��ȯ ���� ������ ������ ���� ĳ���͸� �о��.
	switch (myDirection)
	{
	case Up:
		myXY.myY -= nInterH;
		break;
	case Down:
		myXY.myY += nInterH;
		break;
	case Right:
		myXY.myX += nInterW;
		break;
	case Left:
		myXY.myX -= nInterW;
		break;
	case None:
		break;
	}
}

