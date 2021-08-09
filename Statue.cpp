#include "Statue.h"
Statue::Statue() {}
Statue::~Statue() {}

void Statue::Initialize(HDC hdc)
{
	parseJson.Initialize();

	myDC = CreateCompatibleDC(hdc);

	Statue1bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Statue1").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Statue1old = (HBITMAP)SelectObject(myDC, Statue1bit);
	Statue2bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Statue2").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Statue2old = (HBITMAP)SelectObject(myDC, Statue2bit);
	Statue3bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Statue3").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Statue3old = (HBITMAP)SelectObject(myDC, Statue3bit);
}

void Statue::Progress()
{
}

void Statue::Render(HDC hdc)
{
	// 요 뒤에 부서지지 않는 돌들 넣기
	Statue3old = (HBITMAP)SelectObject(myDC, Statue3bit);
	TransparentBlt(hdc, getX("Statue3"), getY("Statue3"), getWidth("Statue3"), getHeight("Statue3"), myDC, 0, 0, getWidth("Statue3"), getHeight("Statue3"), RGB(255, 0, 255));
	Statue2old = (HBITMAP)SelectObject(myDC, Statue2bit);
	TransparentBlt(hdc, getX("Statue2"), getY("Statue2"), getWidth("Statue2"), getHeight("Statue2"), myDC, 0, 0, getWidth("Statue2"), getHeight("Statue2"), RGB(255, 0, 255));
	Statue1old = (HBITMAP)SelectObject(myDC, Statue1bit);
	TransparentBlt(hdc, getX("Statue1"), getY("Statue1"), getWidth("Statue1"), getHeight("Statue1"), myDC, 0, 0, getWidth("Statue1"), getHeight("Statue1"), RGB(255, 0, 255));
}


int Statue::getWidth(const char* chFileName)
{
	int nWidth;
	nWidth = parseJson.getMyObjectWidth(chFileName);

	return nWidth;
}

int Statue::getHeight(const char* chFileName)
{
	int nHeight;
	nHeight = parseJson.getMyObjectHeight(chFileName);

	return nHeight;
}

float Statue::getX(const char* chFileName)
{
	float fX;
	fX = parseJson.getMyObjectX(chFileName);

	return fX;
}

float Statue::getY(const char* chFileName)
{
	float fY;
	fY = parseJson.getMyObjectY(chFileName);

	return fY;
}

int Statue::getBottom(const char* chFileName)
{
	int nBottom;
	nBottom = parseJson.getMyObjectBottomRect(chFileName);

	return nBottom;
}

int Statue::getTop(const char* chFileName)
{
	int nTop;
	nTop = parseJson.getMyObjectTopRect(chFileName);

	return nTop;
}

RECT Statue::getStatueRECT(const char* chFileName)
{
	StatueRect.left = getX(chFileName); // 560
	StatueRect.top = getTop(chFileName); // 149
	StatueRect.right = StatueRect.left + getWidth(chFileName);
	StatueRect.bottom = StatueRect.top + getBottom(chFileName); // + 53

	return StatueRect;
}



