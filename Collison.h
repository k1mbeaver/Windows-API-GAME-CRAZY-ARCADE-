//�浹 ó��
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
	Direction SetNotInterSect(RECT& pRect, RECT pHold); // �簢�� ���� �������� �ʰ� ����
	Direction SetNotWallInterSect(RECT& pRect, RECT pHold); // ��üȭ��
};