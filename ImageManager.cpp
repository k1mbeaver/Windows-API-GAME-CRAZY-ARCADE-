#include "ImageManager.h"

ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}

HRESULT ImageManager::Initialize()
{
    addImage("BazziDown1", parseJson.getMyObjectHeight("BazziDown1"), parseJson.getMyObjectWidth("BazziDown1"), parseJson.getMyObjectX("BazziDown1"), parseJson.getMyObjectY("BazziDown1"), true);
    addImage("BazziDown2", parseJson.getMyObjectHeight("BazziDown2"), parseJson.getMyObjectWidth("BazziDown2"), parseJson.getMyObjectX("BazziDown2"), parseJson.getMyObjectY("BazziDown2"), true);
    addImage("BazziDown3", parseJson.getMyObjectHeight("BazziDown3"), parseJson.getMyObjectWidth("BazziDown3"), parseJson.getMyObjectX("BazziDown3"), parseJson.getMyObjectY("BazziDown3"), true);
    addImage("BazziDown4", parseJson.getMyObjectHeight("BazziDown4"), parseJson.getMyObjectWidth("BazziDown4"), parseJson.getMyObjectX("BazziDown4"), parseJson.getMyObjectY("BazziDown4"), true);
    addImage("BazziDown5", parseJson.getMyObjectHeight("BazziDown5"), parseJson.getMyObjectWidth("BazziDown5"), parseJson.getMyObjectX("BazziDown5"), parseJson.getMyObjectY("BazziDown5"), true);
    addImage("BazziDown6", parseJson.getMyObjectHeight("BazziDown6"), parseJson.getMyObjectWidth("BazziDown6"), parseJson.getMyObjectX("BazziDown6"), parseJson.getMyObjectY("BazziDown6"), true);
    addImage("BazziDown7", parseJson.getMyObjectHeight("BazziDown7"), parseJson.getMyObjectWidth("BazziDown7"), parseJson.getMyObjectX("BazziDown7"), parseJson.getMyObjectY("BazziDown7"), true);
    addImage("BazziDown8", parseJson.getMyObjectHeight("BazziDown8"), parseJson.getMyObjectWidth("BazziDown8"), parseJson.getMyObjectX("BazziDown8"), parseJson.getMyObjectY("BazziDown8"), true);

    return S_OK;
}

Image* ImageManager::addImage(string strKey, int nHeight, int nWidth, float fX, float fY, bool isTrans)
{
    //������ �̹��� Ű���� �ִ��� ã��
    Image* img = findImage(strKey);
    if (img) return img; // Ű ���� ���� �̹����� ������ �߰����� �ʰ�, ������ �̹����� �ҷ��´�

    img = new Image;
    img->Initialize(strKey, nWidth, nHeight, fX, fY, isTrans);
    //�̹����� ����� �ʱ�ȭ���� �ʾ�����

    //������ �̹����� �ʸ���Ʈ�� �߰�������
    ImageList.insert(make_pair(strKey, img));
    return img;
}

Image* ImageManager::findImage(string strKey)
{
    auto key = ImageList.find(strKey);
    if (key != ImageList.end()) //�ش�Ű�� ã���� ��
    {
        return key->second;
    }
    return nullptr;
}

void ImageManager::Render(string strKey, HDC hdc)
{
    Image* img = findImage(strKey);
    if (img) img->Render(hdc, 0, 0);
}

void ImageManager::Render(string strKey, HDC hdc, float fX, float fY)
{
    Image* img = findImage(strKey);
    if (img) img->Render(hdc, fX, fY);
}