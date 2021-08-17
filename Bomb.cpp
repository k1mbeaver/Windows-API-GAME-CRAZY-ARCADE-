#include "Bomb.h"
Bomb::Bomb() {}
Bomb::~Bomb() {}

void Bomb::Initialize(HDC hdc)
{
	// Initialize���� �� �̹������� ������ ������ ������?

	parseJson.Initialize();
	myDC = CreateCompatibleDC(hdc);
	Bombbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Bomb").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BombPopbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BombPop").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	nBombCount = 1; // ��ǳ�� ���� 1���� �ʱ�ȭ
}

void Bomb::Progress()
{
}

void Bomb::Render(HDC hdc) // ��ǳ�� ��ġ
{
	Bombold = (HBITMAP)SelectObject(myDC, Bombbit);
	TransparentBlt(hdc, myCreateBomb.fX, myCreateBomb.fY, getWidth("Bomb"), getHeight("Bomb"), myDC, FrameX, 0, getWidth("Bomb"), getHeight("Bomb"), RGB(255, 0, 255));

	// �ִϸ��̼� ����� ���� ������
	fFrameDelay += dDT;
	if (fFrameDelay > 0.1f)
	{
		fFrameDelay = 0;
		FrameX += 56;

		if (FrameX >= 224)
		{
			FrameX = 0;
		}
	}
}

void Bomb::BombRender(HDC hdc) // ��ǳ�� ����
{
	BombPopold = (HBITMAP)SelectObject(myDC, BombPopbit);
	TransparentBlt(hdc, myCreateBomb.fX, myCreateBomb.fY, getWidth("BombPop"), getHeight("BombPop"), myDC, BombFrameX, 0, getWidth("BombPop"), getHeight("BombPop"), RGB(255, 0, 255)); // ���

	// �ִϸ��̼� ����� ���� ������
	fFrameDelay += dDT;
	if (fFrameDelay > 0.1f)
	{
		fFrameDelay = 0;
		BombFrameX += 52; // ���

		if (BombFrameX >= 312)
		{
			BombFrameX = 0;
		}
	}
}

int Bomb::getWidth(const char* chFileName)
{
	int nWidth;
	nWidth = parseJson.getMyObjectWidth(chFileName);

	return nWidth;
}

int Bomb::getHeight(const char* chFileName)
{
	int nHeight;
	nHeight = parseJson.getMyObjectHeight(chFileName);

	return nHeight;
}

void Bomb::CreateBomb(float m_fX, float m_fY)
{
	myCreateBomb.fX = m_fX;
	myCreateBomb.fY = m_fY;
	myCreateBomb.myExist = true;

	// ��ǳ�� �ִϸ��̼� ������ �ʱ�ȭ
	FrameX = 0;
	BombFrameX = 0;
}

void Bomb::DeleteBomb()
{
	myCreateBomb.fX = 0;
	myCreateBomb.fY = 0;
	myCreateBomb.myExist = false;
}

bool Bomb::ExistBomb()
{
	if (myCreateBomb.myExist == false)
	{
		return false;
	}

	else
	{
		return true;
	}
}

float Bomb::getX()
{
	return myCreateBomb.fX;
}

float Bomb::getY()
{
	return myCreateBomb.fY;
}