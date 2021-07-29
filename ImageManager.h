#pragma once
#include "BitmapImage.h"
#include "SingleTon.h"

class ImageManager : public SingletonBase<ImageManager>
{
private:
	
public:
	ImageManager();
	~ImageManager();

	map<string, BitmapImage*> mapImageList;

	//초기화
	HRESULT Initialize();

	//키 값으로 설정해서 초기화하기
	BitmapImage* addImage(string strKey, const char* chFileName, int nWidth, int nHeight, bool isTrans); // 이미지 용
	BitmapImage* addImage(string strKey, const char* chFileName, float fX, float fY, int nWidth, int nHeight, bool isTrans); // 움직이는 이미지 용

	//이미지 찾기 함수
	BitmapImage* findImage(string strKey);

	//이미지 지우기
	BOOL deleteImage(string strKey);

	//전체 이미지 지우기 
	BOOL deleteAll();

	//이미지 렌더
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int nDestX, int nDestY);
	void render(string strKey, HDC hdc, int nDestX, int nDestY, int nSourX, int nSourY, int nSourWidth, int nSourHeight);
};