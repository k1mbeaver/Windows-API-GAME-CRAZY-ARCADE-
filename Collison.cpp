#include "Collison.h"

// �簢������ �浹�� �о��!
Direction Collison::SetNotInterSect(RECT& pRect, RECT pHold) // ĳ���� ����
{
	RECT rcInter; // ���� ������ ���� ���� ����

	// �簢���� �浹 �ߴٸ� if���� ����Ǹ�, rcInter�� ��(�浹 ����)�� ��������.
	if (IntersectRect(&rcInter, &pRect, &pHold))
	{
		// ������ ������ ���� ���� ũ�⸦ ������.
		int nInterW = rcInter.right - rcInter.left;
		int nInterH = rcInter.bottom - rcInter.top;

		// ���Ʒ� üũ
		if (nInterW > nInterH)
		{
			// ������ �浹
			if (rcInter.top == pHold.top)
			{
				// �浹 ���� ���̸�ŭ ���� �о��ش�.
				//pRect.top -= nInterH;
				//pRect.bottom -= nInterH;
				//myXY.myY -= nInterH;
				return Up;
			}

			// �Ʒ����� �浹
			if (rcInter.bottom == pHold.bottom)
			{
				// �浹 ���� ���̸�ŭ �Ʒ��� �о��ش�.
				//pRect.top += nInterH;
				//pRect.bottom += nInterH;
				//myXY.myY += nInterH;
				return Down;
			}
		}

		// �¿� üũ
		else
		{
			// ���ʿ��� �浹 ��
			if (rcInter.left == pHold.left)
			{
				// �浹 ���� ����ŭ �·� �о��ش�.
				//pRect.left -= nInterW;
				//pRect.right -= nInterW;
				//myXY.myX -= nInterW;
				return Left;
			}

			else if (rcInter.right == pHold.right)
			{
				// �浹 ���� ����ŭ ��� �о� �ش�.
				//pRect.left += nInterW;
				//pRect.right += nInterW;
				//myXY.myX += nInterW;
				return Right;
			}
		}
	}

	return None;
}