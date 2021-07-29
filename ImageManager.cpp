#include "ImageManager.h"

ImageManager::ImageManager()
{

}

ImageManager::~ImageManager()
{

}


HRESULT ImageManager::Initialize() // 초기화
{
	// 각종 이미지 등록

	// 배경 화면 
	addImage("LoginBackGround", "Crazy Arcade\\Image\\loginBackGround.bmp", crt.right, crt.bottom, true); // 시작 화면
	addImage("LobbyBackGround", "Crazy Arcade\\Image\\lobbyBackGround.bmp", crt.right, crt.bottom, true); // 로비 화면
	addImage("PlayBackGround", "Crazy Arcade\\Image\\BackGround.bmp", crt.right, crt.bottom, false);

	// 캐릭터
	// 방향 : 아래
	addImage("BazziDown1", "Crazy Arcade\\Image\\player\\down\\down1.bmp", 64, 76, true);
	addImage("BazziDown2", "Crazy Arcade\\Image\\player\\down\\down2.bmp", 64, 76, true);
	addImage("BazziDown3", "Crazy Arcade\\Image\\player\\down\\down3.bmp", 64, 76, true);
	addImage("BazziDown4", "Crazy Arcade\\Image\\player\\down\\down4.bmp", 64, 76, true);
	addImage("BazziDown5", "Crazy Arcade\\Image\\player\\down\\down5.bmp", 64, 76, true);
	addImage("BazziDown6", "Crazy Arcade\\Image\\player\\down\\down6.bmp", 64, 76, true);
	addImage("BazziDown7", "Crazy Arcade\\Image\\player\\down\\down7.bmp", 64, 76, true);
	addImage("BazziDown8", "Crazy Arcade\\Image\\player\\down\\down8.bmp", 64, 76, true);

	// 방향 : 위
	addImage("BazziUp1", "Crazy Arcade\\Image\\player\\up\\up1.bmp", 64, 76, true);
	addImage("BazziUp2", "Crazy Arcade\\Image\\player\\up\\up2.bmp", 64, 76, true);
	addImage("BazziUp3", "Crazy Arcade\\Image\\player\\up\\up3.bmp", 64, 76, true);
	addImage("BazziUp4", "Crazy Arcade\\Image\\player\\up\\up4.bmp", 64, 76, true);
	addImage("BazziUp5", "Crazy Arcade\\Image\\player\\up\\up5.bmp", 64, 76, true);
	addImage("BazziUp6", "Crazy Arcade\\Image\\player\\up\\up6.bmp", 64, 76, true);
	addImage("BazziUp7", "Crazy Arcade\\Image\\player\\up\\up7.bmp", 64, 76, true);
	addImage("BazziUp8", "Crazy Arcade\\Image\\player\\up\\up8.bmp", 64, 76, true);

	// 방향 : 왼쪽
	addImage("BazziLeft1", "Crazy Arcade\\Image\\player\\left\\left1.bmp", 64, 76, true);
	addImage("BazziLeft2", "Crazy Arcade\\Image\\player\\left\\left2.bmp", 64, 76, true);
	addImage("BazziLeft3", "Crazy Arcade\\Image\\player\\left\\left3.bmp", 64, 76, true);
	addImage("BazziLeft4", "Crazy Arcade\\Image\\player\\left\\left4.bmp", 64, 76, true);
	addImage("BazziLeft5", "Crazy Arcade\\Image\\player\\left\\left5.bmp", 64, 76, true);
	addImage("BazziLeft6", "Crazy Arcade\\Image\\player\\left\\left6.bmp", 64, 76, true);

	// 방향 : 오른쪽
	addImage("BazziRight1", "Crazy Arcade\\Image\\player\\right\\right1.bmp", 64, 76, true);
	addImage("BazziRight2", "Crazy Arcade\\Image\\player\\right\\right2.bmp", 64, 76, true);
	addImage("BazziRight3", "Crazy Arcade\\Image\\player\\right\\right3.bmp", 64, 76, true);
	addImage("BazziRight4", "Crazy Arcade\\Image\\player\\right\\right4.bmp", 64, 76, true);
	addImage("BazziRight5", "Crazy Arcade\\Image\\player\\right\\right5.bmp", 64, 76, true);
	addImage("BazziRight6", "Crazy Arcade\\Image\\player\\right\\right6.bmp", 64, 76, true);

	// 그림자
	addImage("Shadow", "Crazy Arcade\\Image\\player\\shadow.bmp", 42, 19, true);

	// 캐릭터 표시
	addImage("Mark", "Crazy Arcade\\Image\\player\\solo_player.bmp", 24, 28, true);

	return S_OK;
}

BitmapImage* ImageManager::addImage(string strKey, const char* chFileName, int nWidth, int nHeight, bool isTrans) // 이미지 용
{
	//동일한 이미지 키값이 있는지 찾자
	BitmapImage* img = findImage(strKey);
	if (img) return img; // 키 값과 같은 이미지가 있으면 추가하지 않고, 기존의 이미지를 불러온다.

	img = new BitmapImage;

	//이미지가 제대로 초기화 X?
	if (FAILED(img->init(chFileName, nWidth, nHeight, isTrans)))
	{
		SAFE_DELETE(img);
		return nullptr;
	}

	//생성된 이미지를 맵 리스트에 추가
	mapImageList.insert(make_pair(strKey, img));

	return img;
}

BitmapImage* ImageManager::addImage(string strKey, const char* chFileName, float fX, float fY, int nWidth, int nHeight, bool isTrans) // 움직이는 이미지용
{
	//동일한 이미지 키값이 있는지 찾자
	BitmapImage* img = findImage(strKey);
	if (img) return img; // 키 값과 같은 이미지가 있으면 추가하지 않고, 기존의 이미지를 불러온다.

	img = new BitmapImage;

	//이미지가 제대로 초기화 X?
	if (FAILED(img->init(chFileName, fX, fY, nWidth, nHeight, isTrans)))
	{
		SAFE_DELETE(img);
		return nullptr;
	}

	//생성된 이미지를 맵 리스트에 추가
	mapImageList.insert(make_pair(strKey, img));

	return img;
}

BitmapImage* ImageManager::findImage(string strKey)
{
	auto key = mapImageList.find(strKey);
	if (key != mapImageList.end()) // 해당키를 찾았을 때
	{
		return key->second;
	}
	return nullptr;
}

BOOL ImageManager::deleteImage(string strKey)
{
	auto key = mapImageList.find(strKey);
	if (key != mapImageList.end())
	{
		key->second->release();

		//메모리 해제
		SAFE_DELETE(key->second);
		mapImageList.erase(key);
		return true;
	}
	return false;
}

BOOL ImageManager::deleteAll()
{
	auto it = mapImageList.begin();
	for (; it != mapImageList.end();)
	{
		if (it->second != NULL)
		{
			SAFE_DELETE(it->second);
			it = mapImageList.erase(it);
		}
		else
		{
			++it;
		}
	}
	mapImageList.clear();
	return true;
}

void ImageManager::render(string strKey, HDC hdc)
{
	BitmapImage* img = findImage(strKey);
	if (img) img->render(hdc);
}

void ImageManager::render(string strKey, HDC hdc, int nDestX, int nDestY)
{
	BitmapImage* img = findImage(strKey);
	if (img) img->render(hdc, nDestX, nDestY);
}

void ImageManager::render(string strKey, HDC hdc, int nDestX, int nDestY, int nSourX, int nSourY, int nSourWidth, int nSourHeight)
{
	BitmapImage* img = findImage(strKey);
	if (img) img->render(hdc, nDestX, nDestY, nSourX, nSourY, nSourWidth, nSourHeight);
}

