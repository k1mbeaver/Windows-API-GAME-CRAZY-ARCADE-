//�浹 ó��
#include "stdafx.h"
#include "Define.h"

class Collison
{
private:
public:
	void Initialize() {};
	void Progress() {};
	void Render() {};
	BOOL IntersectRect(LPRECT pInterSect, CONST LPRECT pRect1, CONST LPRECT pRect2); // �簢�� ������ �浹 ���� ���ϱ�
	void SetNotInterSect(LPRECT pRect, CONST LPRECT pHold); // �簢�� ���� �������� �ʰ� ����
};