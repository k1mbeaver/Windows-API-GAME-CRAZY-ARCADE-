#include "Player.h"
Player::Player() {}
Player::~Player() {}

void Player::Initialize(HDC hdc)
{
	myXY.myX = 500;
	myXY.myY = 500;

	// Initialize에서 각 이미지들의 정보를 저장해 놓으면?

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

void Player::Render(HDC hdc) // 게임 플레이 화면 용
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

	// 애니메이션 출력을 위한 프레임
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

void Player::Render(HDC hdc, int nState) // 로비용
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


// 플레이어와 무언가가 충돌하였을 때 통과시키지 않고 밀어내기
void Player::pushbackPlayer(Direction myDirection)
{
	// 교차된 영역의 가로 세로 크기를 따진다.
	int nInterW = rcInter.right - rcInter.left;
	int nInterH = rcInter.bottom - rcInter.top;

	// 반환 받은 열거형 변수에 따라 캐릭터를 밀어낸다.
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

