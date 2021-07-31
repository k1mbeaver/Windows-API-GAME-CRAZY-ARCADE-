#include "Collison.h"

BOOL Collison::IntersectRect(LPRECT pInterSect, CONST LPRECT pRect1, CONST LPRECT pRect2) // �簢�� ������ �浹 ���� ���ϱ�
{
	BOOL bVertical = false; // ���� �浹 ����
	BOOL bHorizontal = false; // ���� �浹 ����

	// ���� �浹
	if (pRect1->left < pRect2->right && pRect1->right > pRect1->left)
	{
		bHorizontal = true;

		if (pInterSect)
		{
			pInterSect->left = (pRect1->left > pRect2->left) ? pRect1->left : pRect2->left;
			pInterSect->right = (pRect1->right < pRect2->right) ? pRect1->right : pRect2->right;
		}
	}

	//���� �浹
	if (pRect1->top < pRect2->bottom && pRect1->bottom > pRect2->top)
	{
		bVertical = true;

		if (pInterSect)
		{
			pInterSect->top = max(pRect1->top, pRect2->top);
			pInterSect->bottom = min(pRect1->bottom, pRect2->bottom);
		}
	}

	if (bVertical && bHorizontal)
	{
		return true;
	}

	if (pInterSect)
	{
		pInterSect->left = 0;
		pInterSect->top = 0;
		pInterSect->right = 0;
		pInterSect->bottom = 0;
	}

	return false;
}

// �簢������ �浹�� �о��!
void Collison::SetNotInterSect(LPRECT pRect, CONST LPRECT pHold)
{
	RECT rcInter; // ���� ������ ���� ���� ����

	// �簢���� �浹 �ߴٸ� if���� ����Ǹ�, rcInter�� ��(�浹 ����)�� ��������.
	if (IntersectRect(&rcInter, pRect, pHold))
	{
		// ������ ������ ���� ���� ũ�⸦ ������.
		int nInterW = rcInter.right - rcInter.left;
		int nInterH = rcInter.bottom - rcInter.top;

		// ���Ʒ� üũ
		if (nInterW > nInterH)
		{
			// ������ �浹
			if (rcInter.top == pHold->top)
			{
				// �浹 ���� ���̸�ŭ ���� �о��ش�.
				pRect->top -= nInterH;
				pRect->bottom -= nInterH;
			}

			// �Ʒ����� �浹
			if (rcInter.bottom == pHold->bottom)
			{
				// �浹 ���� ���̸�ŭ �Ʒ��� �о��ش�.
				pRect->top += nInterH;
				pRect->bottom += nInterH;
			}
		}

		// �¿� üũ
		else
		{
			// ���ʿ��� �浹 ��
			if (rcInter.left == pHold->left)
			{
				// �浹 ���� ����ŭ �·� �о��ش�.
				pRect->left -= nInterW;
				pRect->right -= nInterW;
			}

			else if (rcInter.right == pHold->right)
			{
				// �浹 ���� ����ŭ ��� �о��ش�.
				pRect->left += nInterW;
				pRect->right += nInterW;
			}
		}
	}
}