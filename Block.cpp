#include "Block.h"
Block::Block() {}
Block::~Block() {}

void Block::Initialize(HDC hdc)
{
	// 이미지 링크 읽어오기
	parseJson.Initialize();
	myBlockManager->Initialize();
	// 빈 DC
	myDC = CreateCompatibleDC(hdc);

	Block1bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("block1").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block2bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("block2").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block3bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("block3").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block4bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("block4").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	BlockBreak1bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Breakblock1").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak1old = (HBITMAP)SelectObject(myDC, BlockBreak1bit);
	BlockBreak2bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Breakblock2").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak2old = (HBITMAP)SelectObject(myDC, BlockBreak2bit);
	BlockBreak3bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Breakblock3").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak3old = (HBITMAP)SelectObject(myDC, BlockBreak3bit);
	BlockBreak4bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Breakblock4").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak4old = (HBITMAP)SelectObject(myDC, BlockBreak4bit);

	Stone1bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Stone1").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Stone2bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Stone2").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Stone3bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Stone3").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Stone4bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Stone4").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	myActivation = false;
	nConnection = 0;
}

void Block::Progress()
{
}

void Block::Render(HDC hdc)
{
	Block1old = (HBITMAP)SelectObject(myDC, Block1bit);
	TransparentBlt(hdc, getX("block1"), getY("block1"), getWidth("block1"), getHeight("block1"), myDC, 0, 0, getWidth("block1"), getHeight("block1"), RGB(255, 0, 255));
	Block2old = (HBITMAP)SelectObject(myDC, Block2bit);
	TransparentBlt(hdc, getX("block2"), getY("block2"), getWidth("block2"), getHeight("block2"), myDC, 0, 0, getWidth("block2"), getHeight("block2"), RGB(255, 0, 255));
	Block3old = (HBITMAP)SelectObject(myDC, Block3bit);
	TransparentBlt(hdc, getX("block3"), getY("block3"), getWidth("block3"), getHeight("block3"), myDC, 0, 0, getWidth("block3"), getHeight("block3"), RGB(255, 0, 255));
	Block4old = (HBITMAP)SelectObject(myDC, Block4bit);
	TransparentBlt(hdc, getX("block4"), getY("block4"), getWidth("block4"), getHeight("block4"), myDC, 0, 0, getWidth("block4"), getHeight("block4"), RGB(255, 0, 255));

	// stone3 DC 입력
	Stone1old = (HBITMAP)SelectObject(myDC, Stone1bit);
	for (int nIndex = 0; nIndex < 27; nIndex++)
	{
		TransparentBlt(hdc, getX("Stone1"), getY("Stone1") + getBetweenY("Stone1") * nIndex, getWidth("Stone1"), getHeight("Stone1"), myDC, 0, 0, getWidth("Stone1"), getHeight("Stone1"), RGB(255, 0, 255));
	}
	/*
	for (int nIndex = 0; nIndex < 27; nIndex++)
	{
		TransparentBlt(hdc, getX("Stone3") + getBetweenX("Stone3") * nIndex, getY("Stone3"), getWidth("Stone3"), getHeight("Stone3"), myDC, 0, 0, getWidth("Stone3"), getHeight("Stone3"), RGB(255, 0, 255));
	}
	for (int nIndex = 0; nIndex < 27; nIndex++)
	{
		TransparentBlt(hdc, getX2("Stone3") + getBetweenX("Stone3") * nIndex, getY2("Stone3"), getWidth("Stone3"), getHeight("Stone3"), myDC, 0, 0, getWidth("Stone3"), getHeight("Stone3"), RGB(255, 0, 255));
	}
	*/
	/*
	// stone1 DC 입력
	Stone1old = (HBITMAP)SelectObject(myDC, Stone1bit);
	for (int nIndex = 0; nIndex < 16; nIndex++)
	{
		TransparentBlt(hdc, getX("Stone1"), getY("Stone1") + getBetweenY("Stone1") * nIndex, getWidth("Stone1"), getHeight("Stone1"), myDC, 0, 0, getWidth("Stone1"), getHeight("Stone1"), RGB(255, 0, 255));
	}

	// stone2 DC 입력
	Stone2old = (HBITMAP)SelectObject(myDC, Stone2bit);
	for (int nIndex = 0; nIndex < 16; nIndex++)
	{
		TransparentBlt(hdc, getX("Stone2"), getY("Stone2") + getBetweenY("Stone2") * nIndex, getWidth("Stone2"), getHeight("Stone2"), myDC, 0, 0, getWidth("Stone2"), getHeight("Stone2"), RGB(255, 0, 255));
	}

	// stone4 DC 입력
	Stone4old = (HBITMAP)SelectObject(myDC, Stone4bit);
	for (int nIndex = 0; nIndex < 4; nIndex++)
	{
		TransparentBlt(hdc, (getX("Stone4") + (getBetweenX("Stone4") * nIndex)), getY("Stone4"), getWidth("Stone4"), getHeight("Stone4"), myDC, 0, 0, getWidth("Stone4"), getHeight("Stone4"), RGB(255, 0, 255));
	}
	*/
	

	/*
	fFrameDelay += dDT;
	if (fFrameDelay > 0.1f)
	{
		fFrameDelay = 0;

		if (UDFrameX >= 512)
		{
			UDFrameX = 0;
		}

		if (LRFrameX >= 384)
		{
			LRFrameX = 0;
		}
	}
	*/
}

int Block::getWidth(const char* chFileName)
{
	int nWidth;
	nWidth = parseJson.getMyObjectWidth(chFileName);

	return nWidth;
}

int Block::getHeight(const char* chFileName)
{
	int nHeight;
	nHeight = parseJson.getMyObjectHeight(chFileName);

	return nHeight;
}

float Block::getX(const char* chFileName)
{
	float fX;
	fX = parseJson.getMyObjectX(chFileName);

	return fX;
}

float Block::getY(const char* chFileName)
{
	float fY;
	fY = parseJson.getMyObjectY(chFileName);

	return fY;
}

float Block::getX2(const char* chFileName)
{
	float fX;
	fX = parseJson.getMyObjectX2(chFileName);

	return fX;
}

float Block::getY2(const char* chFileName)
{
	float fY;
	fY = parseJson.getMyObjectY2(chFileName);

	return fY;
}

int Block::getBetweenX(const char* chFileName)
{
	int nBX;
	nBX = parseJson.getMyObjectBetweenX(chFileName);

	return nBX;
}

int Block::getBetweenY(const char* chFileName)
{
	int nBY;
	nBY = parseJson.getMyObjectBetweenY(chFileName);

	return nBY;
}

