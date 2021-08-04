#include "Statue.h"
Statue::Statue() {}
Statue::~Statue() {}

void Statue::Initialize(HDC hdc)
{
	Stone1DC = CreateCompatibleDC(hdc);
	Stone2DC = CreateCompatibleDC(hdc);
	Stone3DC = CreateCompatibleDC(hdc);
	Statue1DC = CreateCompatibleDC(hdc);
	Statue2DC = CreateCompatibleDC(hdc);
	Statue3DC = CreateCompatibleDC(hdc);

	Stone1bit = (HBITMAP)LoadImage(NULL, TEXT("Image//object//object_1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Stone1old = (HBITMAP)SelectObject(Stone1DC, Stone1bit);
	Stone2bit = (HBITMAP)LoadImage(NULL, TEXT("Image//object//object_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Stone2old = (HBITMAP)SelectObject(Stone2DC, Stone2bit);
	Stone3bit = (HBITMAP)LoadImage(NULL, TEXT("Image//object//object_3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Stone3old = (HBITMAP)SelectObject(Stone3DC, Stone3bit);
	Statue1bit = (HBITMAP)LoadImage(NULL, TEXT("Image//object//object_4.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Statue1old = (HBITMAP)SelectObject(Statue1DC, Statue1bit);
	Statue2bit = (HBITMAP)LoadImage(NULL, TEXT("Image//object//object_5.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Statue2old = (HBITMAP)SelectObject(Statue2DC, Statue2bit);
	Statue3bit = (HBITMAP)LoadImage(NULL, TEXT("Image//object//object_6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Statue3old = (HBITMAP)SelectObject(Statue3DC, Statue3bit);
	GetObject(Stone1bit, sizeof(BITMAP), &StoneBitmap);
	GetObject(Statue1bit, sizeof(BITMAP), &Statue1Bitmap);
	GetObject(Statue2bit, sizeof(BITMAP), &Statue2Bitmap);
	GetObject(Statue3bit, sizeof(BITMAP), &Statue3Bitmap);
}

void Statue::Progress()
{
}

void Statue::Render(HDC hdc)
{
	// 요 뒤에 부서지지 않는 돌들 넣기
	
	TransparentBlt(hdc, 102, 38, getStoneX(), getStoneY(), Stone1DC, 0, 0, getStoneX(), getStoneY(), RGB(255, 0, 255));
	TransparentBlt(hdc, 154, 38, getStoneX(), getStoneY(), Stone1DC, 0, 0, getStoneX(), getStoneY(), RGB(255, 0, 255));
	TransparentBlt(hdc, 570, 50, getStoneX(), getStoneY(), Stone1DC, 0, 0, getStoneX(), getStoneY(), RGB(255, 0, 255));
	TransparentBlt(hdc, 620, 50, getStoneX(), getStoneY(), Stone1DC, 0, 0, getStoneX(), getStoneY(), RGB(255, 0, 255));
	TransparentBlt(hdc, 560, 0, getStatue3X(), getStatue3Y(), Statue3DC, 0, 0, getStatue3X(), getStatue3Y(), RGB(255, 0, 255));
	TransparentBlt(hdc, 0, 200, getStatue2X(), getStatue2Y(), Statue2DC, 0, 0, getStatue2X(), getStatue2Y(), RGB(255, 0, 255));
	TransparentBlt(hdc, 1363, 200, getStatue1X(), getStatue1Y(), Statue1DC, 0, 0, getStatue1X(), getStatue1Y(), RGB(255, 0, 255));
}

int Statue::getStoneX()
{
	nStoneX = StoneBitmap.bmWidth;
	return nStoneX;
}
int Statue::getStoneY()
{
	nStoneY = StoneBitmap.bmHeight;
	return nStoneY;
}
int Statue::getStatue1X()
{
	nStatue1X = Statue1Bitmap.bmWidth;
	return nStatue1X;
}
int Statue::getStatue1Y()
{
	nStatue1Y = Statue1Bitmap.bmHeight;
	return nStatue1Y;
}
int Statue::getStatue2X()
{
	nStatue2X = Statue2Bitmap.bmWidth;
	return nStatue2X;
}
int Statue::getStatue2Y()
{
	nStatue2Y = Statue2Bitmap.bmHeight;
	return nStatue2Y;
}
int Statue::getStatue3X()
{
	nStatue3X = Statue3Bitmap.bmWidth;
	return nStatue3X;
}
int Statue::getStatue3Y()
{
	nStatue3Y = Statue3Bitmap.bmHeight;
	return nStatue3Y;
}

RECT Statue::getStatue3RECT()
{
	StatueRect.left = 560;
	StatueRect.top = 0;
	StatueRect.right = StatueRect.left + getStatue3X();
	StatueRect.bottom = StatueRect.top + getStatue3Y();

	return StatueRect;
}



