//�浹 ó��
#include "stdafx.h"
#include "Define.h"
#include "Player.h"
#include "Statue.h"


class Collison
{
private:
public:
	void Initialize() {};
	void Progress();
	void Render() {};
	Direction SetNotInterSect(RECT& pRect, RECT pHold); // �簢�� ���� �������� �ʰ� ����
};