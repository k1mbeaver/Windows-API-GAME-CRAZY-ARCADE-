#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

HRESULT Map::Initialize(float m_fX, float m_fY, bool m_BlockExist, bool m_BlockBreak, int m_nWidth, int m_nHeight)
{
	BlockInformation = new IMAGE_INFO;
	BlockInformation->fX = m_fX;
	BlockInformation->fY = m_fY;
	BlockInformation->BlockExist = m_BlockExist;
	BlockInformation->BlockBreak = m_BlockBreak;
	BlockInformation->nWidth = m_nWidth;
	BlockInformation->nHeight = m_nHeight;

	return S_OK;
}