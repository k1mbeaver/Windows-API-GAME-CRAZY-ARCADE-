//충돌 처리
#include "stdafx.h"
#include "Define.h"

class Collison
{
private:
public:
	void Initialize() {};
	void Progress() {};
	void Render() {};
	BOOL IntersectRect(LPRECT pInterSect, CONST LPRECT pRect1, CONST LPRECT pRect2); // 사각형 끼리의 충돌 영역 구하기
	void SetNotInterSect(LPRECT pRect, CONST LPRECT pHold); // 사각형 끼리 교차되지 않게 셋팅
};