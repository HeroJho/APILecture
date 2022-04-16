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
			// 풀링 오브젝트면 엑티브 상태일 때
			if (m_arrObj[i][j]->GetPooling())
			{
				if (m_arrObj[i][j]->GetPooling()->Get_Active())
				{
					m_arrObj[i][j]->update();
				}
				continue;
			}

			// 죽음 예약이면 업데이트 
			if (!m_arrObj[i][j]->IsDead())
			{
				m_arrObj[i][j]->update();
			}
		}
	}
}

void CScene::finalupdate()
{
	// 충돌체 이동
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			// 풀링 오브젝트면 엑티브 상태일 때
			if (m_arrObj[i][j]->GetPooling())
			{
				if (m_arrObj[i][j]->GetPooling()->Get_Active())
				{
					m_arrObj[i][j]->finalupdate();
				}
				continue;
			}

			// 죽음 예약도 마지막까지 콜리젼 처리 >> 바로 사라지면 콜리전 exit처리 못해줌?
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

			// 먼저 폴링 확인
			if ((*iter)->GetPooling())
			{
				if ((*iter)->GetPooling()->Get_Active())
				{
					(*iter)->render(_dc);
				}
				
				++iter;
				continue;
			}


			// 랜더는 모든 고정의 마무리이기 때문에 이때 씬에서 빼준다
			if (!(*iter)->IsDead())
			{
				(*iter)->render(_dc);
				++iter;
			}
			else  
			{    // 삭제하면 다음 위치 받아오니까
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

	// 타일 생성
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


