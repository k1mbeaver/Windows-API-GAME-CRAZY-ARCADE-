#include "BlockManager.h"

BlockManager::BlockManager()
{
    parseJson.Initialize();
}

BlockManager::~BlockManager()
{
}

HRESULT BlockManager::Initialize()
{
    for (int nCount1 = 0; nCount1 < 1; nCount1++)
    {
        for (int nCount2 = 0; nCount2 < 16; nCount2++)
        {
            //BlockList[nCount1][nCount2] = new Map;
            BlockList[nCount1][nCount2]->Initialize(parseJson.getMapX("Map", nCount1, nCount2), parseJson.getMapY("Map", nCount1, nCount2),
                parseJson.getMapExist("Map", nCount1, nCount2), parseJson.getMapBreak("Map", nCount1, nCount2) ,parseJson.getMapWidth("Map", nCount1, nCount2), parseJson.getMapHeight("Map", nCount1, nCount2));
        }
    }

    return S_OK;
}