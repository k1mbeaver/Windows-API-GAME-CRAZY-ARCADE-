#pragma once
#include "stdafx.h"
//������ ���ӿ� ���õ� Ŭ������ �ִ� ����� �߰��Ѵ�.

class GameCore
{
private:
	//���õ� Ŭ������ �߰�
	HDC myHDC;
	int nCurrent = 0; // ó�� �������� �� Initialize() �ʱ�ȭ�� ���� ����

public:
	GameCore();
	~GameCore();

	void Initialize(); // �ʱ�ȭ
	void Prograss(); // ó��
	void Render(); // �׸���

};