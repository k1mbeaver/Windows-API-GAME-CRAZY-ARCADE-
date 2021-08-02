#include "Block.h"
Block::Block() {}
Block::~Block() {}

void Block::Initialize(HDC hdc)
{
	Block1DC = CreateCompatibleDC(hdc);
	Block2DC = CreateCompatibleDC(hdc);
	Block3DC = CreateCompatibleDC(hdc);
	Block4DC = CreateCompatibleDC(hdc);
	BlockBreak1DC = CreateCompatibleDC(hdc);
	BlockBreak2DC = CreateCompatibleDC(hdc);
	BlockBreak3DC = CreateCompatibleDC(hdc);
	BlockBreak4DC = CreateCompatibleDC(hdc);
	Block1bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block1old = (HBITMAP)SelectObject(Block1DC, Block1bit);
	Block2bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block2old = (HBITMAP)SelectObject(Block2DC, Block2bit);
	Block3bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block3old = (HBITMAP)SelectObject(Block3DC, Block3bit);
	Block4bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Block4old = (HBITMAP)SelectObject(Block4DC, Block4bit);
	BlockBreak1bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_1_pop.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak1old = (HBITMAP)SelectObject(BlockBreak1DC, BlockBreak1bit);
	BlockBreak2bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_2_pop.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak2old = (HBITMAP)SelectObject(BlockBreak2DC, BlockBreak2bit);
	BlockBreak3bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_3_pop.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak3old = (HBITMAP)SelectObject(BlockBreak3DC, BlockBreak3bit);
	BlockBreak4bit = (HBITMAP)LoadImage(NULL, "C:\\Users\\USER\\Desktop\\연구실 공부\\허승찬 선배님 스터디\\크레이지 아케이드\\Crazy Arcade ver2\\Crazy Arcade ver2\\Image\\block\\block_4_pop.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BlockBreak4old = (HBITMAP)SelectObject(BlockBreak4DC, BlockBreak4bit);
	myActivation = false;
	nConnection = 0;
}

void Block::Progress()
{
}

void Block::Render(HDC hdc)
{
	GetObject(Block1bit, sizeof(BITMAP), &Blockbit);
	nGeneralX = Blockbit.bmWidth;
	nGeneralY = Blockbit.bmHeight;

	GetObject(BlockBreak1bit, sizeof(BITMAP), &BlockBreakbit);
	nBreakX = BlockBreakbit.bmWidth;
	nBreakY = BlockBreakbit.bmHeight;

	TransparentBlt(hdc, 305, 290, nGeneralX, nGeneralY, Block1DC, 0, 0, nGeneralX, nGeneralY, RGB(255, 0, 255));
	TransparentBlt(hdc, 305, 345, nGeneralX, nGeneralY, Block2DC, 0, 0, nGeneralX, nGeneralY, RGB(255, 0, 255));
	TransparentBlt(hdc, 305, 400, nGeneralX, nGeneralY, Block3DC, 0, 0, nGeneralX, nGeneralY, RGB(255, 0, 255));
	TransparentBlt(hdc, 305, 455, nGeneralX, nGeneralY, Block4DC, 0, 0, nGeneralX, nGeneralY, RGB(255, 0, 255));

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

