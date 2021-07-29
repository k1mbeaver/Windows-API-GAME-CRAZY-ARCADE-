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

	//�ʱ�ȭ
	HRESULT Initialize();

	//Ű ������ �����ؼ� �ʱ�ȭ�ϱ�
	BitmapImage* addImage(string strKey, const char* chFileName, int nWidth, int nHeight, bool isTrans); // �̹��� ��
	BitmapImage* addImage(string strKey, const char* chFileName, float fX, float fY, int nWidth, int nHeight, bool isTrans); // �����̴� �̹��� ��

	//�̹��� ã�� �Լ�
	BitmapImage* findImage(string strKey);

	//�̹��� �����
	BOOL deleteImage(string strKey);

	//��ü �̹��� ����� 
	BOOL deleteAll();

	//�̹��� ����
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int nDestX, int nDestY);
	void render(string strKey, HDC hdc, int nDestX, int nDestY, int nSourX, int nSourY, int nSourWidth, int nSourHeight);
};