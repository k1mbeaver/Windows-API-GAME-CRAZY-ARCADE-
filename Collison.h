//�浹 ó��
#include "stdafx.h"
#include "Define.h"
#include "Player.h"

class Collison
{
private:
public:
	void Initialize() {};
	void Progress() {};
	void Render() {};
	void SetNotInterSect(RECT pRect, RECT pHold); // �簢�� ���� �������� �ʰ� ����
	Player* myPlayer;
};