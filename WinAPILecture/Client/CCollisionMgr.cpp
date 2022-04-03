#include "pch.h"
#include "CCollisionMgr.h"

#include "CSceneMgr.h"
#include "CScene.h"s
#include "CObject.h"
#include "CCollider.h"

CCollisionMgr::CCollisionMgr()
	: m_arrCheck{}
{

}

CCollisionMgr::~CCollisionMgr()
{

}

void CCollisionMgr::update()
{
	// ��Ʈ ����� ���鼭 üũ�Ѵ�
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; ++iRow)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_TYPE::END; ++iCol)
		{
			// �ش� �׷� �浹 ó�� üũ
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				CollisionGroupUpdate((GROUP_TYPE)iRow, (GROUP_TYPE)iCol);
			}
		}
	}
}

void CCollisionMgr::CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

	const vector<CObject*>& vecLeft = pCurScene->GetGroupObject(_eLeft);
	const vector<CObject*>& vecRight = pCurScene->GetGroupObject(_eRight);

	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// �浹ü�� ���� ���
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 9; j < vecRight.size(); ++j)
		{
			// �浹ü�� ���ų� �� �ڽ��̶��
			if (nullptr == vecRight[j]->GetCollider() ||
				vecLeft[i] == vecRight[j])
				continue;

			if (IsCollision(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider()))
			{
				
			}
			else
			{

			}
		}
	}
}

bool CCollisionMgr::IsCollision(CCollider* _pLeftCol, CCollider* _pRightCol)
{


	return false;
}



void CCollisionMgr::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	// ������
	// ����
	// ��


	UINT iRow = (UINT)_eLeft;
	UINT iCol = (UINT)_eRight;

	// �� ���� ���� �׷� Ÿ���� ������,
	// ū ���� ��(��Ʈ)�� ���!
	if (iCol < iRow)
	{
		iRow = (UINT)_eRight;
		iCol = (UINT)_eLeft;
	}

	// �̹� üũ�������� ����
	if (m_arrCheck[iRow] & (1 << iCol))
	{
		m_arrCheck[iRow] &= ~(1 << iCol); // ����
	}
	else
	{
		m_arrCheck[iRow] |= 1 << iCol; // üũ
	}

}


