#include "Block.h"
Block::Block() {}
Block::~Block() 
{
	for (int nIndex = 0; nIndex < 12; nIndex++)
	{
		for (int nJndex = 0; nJndex < 27; nJndex++)
		{
			delete myMap[nIndex][nJndex];
		}
	}
}

void Block::Initialize(HDC hdc)
{
	// 이미지 링크 읽어오기
	parseJson.Initialize();

	// 맵에 있는 블록 정보 가져 오기
	getMapPosition();
	// 빈 DC
	myDC = CreateCompatibleDC(hdc);

	Block2bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("block2").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block3bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("block3").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	BlockBreak2bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Breakblock2").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak2old = (HBITMAP)SelectObject(myDC, BlockBreak2bit);
	BlockBreak3bit = (HBITMAP)LoadImage(NULL, parseJson.getMyObjectLink("Breakblock3").c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak3old = (HBITMAP)SelectObject(myDC, BlockBreak3bit);

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
	Block2old = (HBITMAP)SelectObject(myDC, Block2bit);

	// 블럭 [12][27]까지 다 만들어 보기
	for (int nIndex = 0; nIndex < 12; nIndex++)
	{
		for (int nJndex = 0; nJndex < 27; nJndex++)
		{
			// 블럭이 존재 & 부서지는 블럭
			if (myMap[nIndex][nJndex]->BlockExist == true && myMap[nIndex][nJndex]->BlockBreak == true)
			{
				Block2old = (HBITMAP)SelectObject(myDC, Block2bit);
				TransparentBlt(hdc, myMap[nIndex][nJndex]->fX, myMap[nIndex][nJndex]->fY, myMap[nIndex][nJndex]->nWidth, myMap[nIndex][nJndex]->nHeight
					, myDC, 0, 0, myMap[nIndex][nJndex]->nWidth, myMap[nIndex][nJndex]->nHeight, RGB(255, 0, 255));
			}

			// 블럭이 존재 & 부서지지 않는 블럭
			else if(myMap[nIndex][nJndex]->BlockExist == true && myMap[nIndex][nJndex]->BlockBreak == false)
			{
				Block3old = (HBITMAP)SelectObject(myDC, Block3bit);
				TransparentBlt(hdc, myMap[nIndex][nJndex]->fX, myMap[nIndex][nJndex]->fY, myMap[nIndex][nJndex]->nWidth, myMap[nIndex][nJndex]->nHeight
					, myDC, 0, 0, myMap[nIndex][nJndex]->nWidth, myMap[nIndex][nJndex]->nHeight, RGB(255, 0, 255));
			}
		}
	}	
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

void Block::getMapPosition()
{
	int nCount = 0;
	for (int nCount1 = 0; nCount1 < 12; nCount1++)
	{
		for (int nCount2 = 0; nCount2 < 27; nCount2++)
		{
			myMap[nCount1][nCount2] = MapInitialize(parseJson.getMapX(nCount), parseJson.getMapY(nCount),
				parseJson.getMapExist(nCount), parseJson.getMapBreak(nCount), parseJson.getMapWidth(nCount), parseJson.getMapHeight(nCount));
			nCount++;
		}
	}
}

MapInfo* Block::MapInitialize(float m_fX, float m_fY, bool m_BlockExist, bool m_BlockBreak, int m_nWidth, int m_nHeight)
{
	MapPosition* myBlock = new MapPosition;
	myBlock->fX = m_fX;
	myBlock->fY = m_fY;
	myBlock->BlockExist = m_BlockExist;
	myBlock->BlockBreak = m_BlockBreak;
	myBlock->nWidth = m_nWidth;
	myBlock->nHeight = m_nHeight;
	myBlock->BlockRECT.left = myBlock->fX;
	myBlock->BlockRECT.top = myBlock->fY;
	myBlock->BlockRECT.right = myBlock->BlockRECT.left + myBlock->nWidth;
	myBlock->BlockRECT.bottom = myBlock->BlockRECT.top + myBlock->nHeight;

	return myBlock;
}

RECT Block::getBlockRect(int nCount1, int nCount2)
{
	RECT returnRECT;

	returnRECT = myMap[nCount1][nCount2]->BlockRECT;
	return returnRECT;


}