//�浹 ó��
#pragma once
#include "stdafx.h"
#include "Define.h"

extern RECT rcInter;

class Collison
{
private:
public:
	void Initialize() {};
	void Progress();
	void Render() {};
	Direction SetNotCharacter(RECT& pRect, RECT pHold); // �簢�� ���� �������� �ʰ� ����, ĳ���Ϳ�
	Direction SetNotInterSect(RECT pRect, RECT pHold); // ������
};