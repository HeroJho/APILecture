#include "pch.h"
#include "CScene.h"

#include "CObject.h"
#include "CTile.h"
#include "CResMgr.h"
#include "CPooling.h"


CScene::CScene()
	: m_iTileX(0)
	, m_iTileY(0)
{

}

CScene::~CScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			delete m_arrObj[i][j];
		}
	}
}


void CScene::update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			// Ǯ�� ������Ʈ�� ��Ƽ�� ������ ��
			if (m_arrObj[i][j]->GetPooling())
			{
				if (m_arrObj[i][j]->GetPooling()->Get_Active())
				{
					m_arrObj[i][j]->update();
				}
				continue;
			}

			// ���� �����̸� ������Ʈ 
			if (!m_arrObj[i][j]->IsDead())
			{
				m_arrObj[i][j]->update();
			}
		}
	}
}

void CScene::finalupdate()
{
	// �浹ü �̵�
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			// Ǯ�� ������Ʈ�� ��Ƽ�� ������ ��
			if (m_arrObj[i][j]->GetPooling())
			{
				if (m_arrObj[i][j]->GetPooling()->Get_Active())
				{
					m_arrObj[i][j]->finalupdate();
				}
				continue;
			}

			// ���� ���൵ ���������� �ݸ��� ó�� >> �ٷ� ������� �ݸ��� exitó�� ������?
			if (!m_arrObj[i][j]->IsDead())
			{
				m_arrObj[i][j]->finalupdate();
			}
		}
	}
}

void CScene::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		vector<CObject*>::iterator iter = m_arrObj[i].begin();

		for (; iter != m_arrObj[i].end();)
		{

			// ���� ���� Ȯ��
			if ((*iter)->GetPooling())
			{
				if ((*iter)->GetPooling()->Get_Active())
				{
					(*iter)->render(_dc);
				}
				
				++iter;
				continue;
			}


			// ������ ��� ������ �������̱� ������ �̶� ������ ���ش�
			if (!(*iter)->IsDead())
			{
				(*iter)->render(_dc);
				++iter;
			}
			else  
			{    // �����ϸ� ���� ��ġ �޾ƿ��ϱ�
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}


void CScene::DeleteGroup(GROUP_TYPE _eTarget)
{
	Safe_Delete_Vec<CObject*>(m_arrObj[(UINT)_eTarget]);
}

void CScene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		DeleteGroup((GROUP_TYPE)i);
	}
}

void CScene::CreateTile(UINT _iXCount, UINT _iYCount)
{
	m_iTileX = _iXCount;
	m_iTileY = _iYCount;

	CTexture* pTileTex = CResMgr::GetInst()->LoadTexture(L"Tile", L"texture\\tile\\TILE.bmp");

	// Ÿ�� ����
	for (UINT i = 0; i < _iYCount; ++i)
	{
		for (UINT j = 0; j < _iXCount; ++j)
		{
			CTile* pTile = new CTile();

			pTile->SetPos(Vec2((float)(j * TILE_SIZE), (float)(i * TILE_SIZE)));
			pTile->SetTexture(pTileTex);

			AddObject(pTile, GROUP_TYPE::TILE);
		}
	}
}


