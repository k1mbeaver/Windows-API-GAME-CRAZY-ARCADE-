#include "Bomb.h"
Bomb::Bomb() {}
Bomb::~Bomb() {}

void Bomb::Initialize(HDC hdc)
{
	// Initialize에서 각 이미지들의 정보를 저장해 놓으면?

	parseJson.Initialize();
	myDC = CreateCompatibleDC(hdc);
	Bombbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Bomb").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BombPopbit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("BombPop").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	nBombCount = 1; // 물풍선 갯수 1개로 초기화
}

void Bomb::Progress()
{
}

void Bomb::Render(HDC hdc, float fX, float fY) // 물풍선 설치
{
	Bombold = (HBITMAP)SelectObject(myDC, Bombbit);
	TransparentBlt(hdc, fX, fY, getWidth("Bomb"), getHeight("Bomb"), myDC, FrameX, 0, getWidth("Bomb"), getHeight("Bomb"), RGB(255, 0, 255));

	// 애니메이션 출력을 위한 프레임
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

void Bomb::BombRender(HDC hdc, float fX, float fY) // 물풍선 폭파
{
	BombPopold = (HBITMAP)SelectObject(myDC, BombPopbit);
	TransparentBlt(hdc, fX, fY, getWidth("BombPop"), getHeight("BombPop"), myDC, FrameX, 0, getWidth("BombPop"), getHeight("BombPop"), RGB(255, 0, 255));

	// 애니메이션 출력을 위한 프레임
	fFrameDelay += dDT;
	if (fFrameDelay > 0.1f)
	{
		fFrameDelay = 0;
		FrameX += 52;

		if (FrameX >= 312)
		{
			FrameX = 0;
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

BombInfo* Bomb::CreateBomb(float m_fX, float m_fY)
{
	BombInfo* myCreateBomb = new BombInfo;
	myCreateBomb -> fX = m_fX;
	myCreateBomb -> fY = m_fY;
	myCreateBomb -> myExist = true;
	return myCreateBomb;
}

void Bomb::DeleteBomb(BombInfo* m_myCreateBomb)
{
	delete m_myCreateBomb;
}

bool Bomb::ExistBomb(BombInfo* m_myCreateBomb)
{
	if (m_myCreateBomb == nullptr)
	{
		return false;
	}

	else
	{
		return true;
	}
}