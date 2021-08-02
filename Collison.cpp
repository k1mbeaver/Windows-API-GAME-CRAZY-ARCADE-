#include "Collison.h"

// 사각형끼리 충돌시 밀어내기!
void Collison::SetNotInterSect(RECT pRect, RECT pHold)
{
	RECT rcInter; // 교차 영역을 얻을 변수 선언

	// 사각형이 충돌 했다면 if문이 실행되며, rcInter의 값(충돌 영역)이 구해진다.
	if (IntersectRect(&rcInter, &pRect, &pHold))
	{
		// 교차된 영역의 가로 세로 크기를 따진다.
		int nInterW = rcInter.right - rcInter.left;
		int nInterH = rcInter.bottom - rcInter.top;

		// 위아래 체크
		if (nInterW > nInterH)
		{
			// 위에서 충돌
			if (rcInter.top == pHold.top)
			{
				// 충돌 수직 높이만큼 위로 밀어준다.
				pRect.top -= nInterH;
				pRect.bottom -= nInterH;
			}

			// 아래에서 충돌
			if (rcInter.bottom == pHold.bottom)
			{
				// 충돌 수직 높이만큼 아래로 밀어준다.
				pRect.top += nInterH;
				pRect.bottom += nInterH;
			}
		}

		// 좌우 체크
		else
		{
			// 왼쪽에서 충돌 시
			if (rcInter.left == pHold.left)
			{
				// 충돌 가로 폭만큼 좌로 밀어준다.
				pRect.left -= nInterW;
				pRect.right -= nInterW;
			}

			else if (rcInter.right == pHold.right)
			{
				// 충돌 가로 폭만큼 우로 밀어준다.
				pRect.left += nInterW;
				pRect.right += nInterW;
			}
		}
	}
}