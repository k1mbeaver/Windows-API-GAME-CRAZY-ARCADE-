#include "Collison.h"

// �簢������ �浹�� �о��!
void Collison::SetNotInterSect(RECT& pRect, RECT pHold)
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
				pRect.top -= nInterH;
				pRect.bottom -= nInterH;
			}

			// �Ʒ����� �浹
			if (rcInter.bottom == pHold.bottom)
			{
				// �浹 ���� ���̸�ŭ �Ʒ��� �о��ش�.
				pRect.top += nInterH;
				pRect.bottom += nInterH;
			}
		}

		// �¿� üũ
		else
		{
			// ���ʿ��� �浹 ��
			if (rcInter.left == pHold.left)
			{
				// �浹 ���� ����ŭ �·� �о��ش�.
				pRect.left -= nInterW;
				pRect.right -= nInterW;
			}

			else if (rcInter.right == pHold.right)
			{
				// �浹 ���� ����ŭ ��� �о� �ش�.
				pRect.left += nInterW;
				pRect.right += nInterW;
			}
		}
	}
}