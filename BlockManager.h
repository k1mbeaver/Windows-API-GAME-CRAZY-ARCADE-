#pragma once
#include "Map.h"
#include "myJson.h"

class BlockManager
{
public:
	Map* BlockList[1][16];
	myJson parseJson;
	BlockManager();
	~BlockManager();

	//Initialize
	HRESULT Initialize();
	void release();
};