#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"
#include "CGameMgr.h"

#include "CResMgr.h"
#include "CTexture.h"

#include "CCollider.h"
#include "CPlayer.h"
#include "CItemBox.h"


CMonster::CMonster(CreatureInfo* _sInfo)
	: m_fSpeed(100.f)
	, m_pTex(nullptr)
	, m_bIsOnMonster(false)
{
	m_sInfo = _sInfo;

	// Texture 로딩하기
	m_pTex = CResMgr::GetInst()->LoadTexture(L"MonsterTex", L"texture\\Monster.bmp");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(30.f, 30.f));

	CreateTimmer();
}

CMonster::~CMonster()
{

}

void CMonster::CreatureUpdate()
{
	Vec2 vCurPos = GetPos();

	// 몬스터랑 충돌하면 반대로 밀어내기
	if (m_bIsOnMonster)
	{
		Vec2 vInverseDir = m_vDir.GetInverseVec();
		m_vDir = vInverseDir.Normalize();
	}
	else
	{
		// 플레이어를 향하는 방향을 구해줘야 한다.
		// 목표 위치 - 내 위치
		Vec2 destinPos = CGameMgr::GetInst()->GetPlayer()->GetPos();
		Vec2 vDir = destinPos - vCurPos;
		m_vDir = vDir.Normalize();
	}
	
	vCurPos.x += m_fSpeed * m_vDir.x * fDT;
	vCurPos.y += m_fSpeed * m_vDir.y * fDT;

	SetPos(vCurPos);
	SetIsOnMonster(false);
}

void CMonster::render(HDC _dc)
{
	// 그림의 크기에 따라 좌상단 위치에서 그린다
	// 화면 왼쪽으로 나가면 음수값이 나올 수 있으니 int로 캐스팅
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);

	// (255, 0, 255) 마젠타 색상은 빼고 복사해줘
	TransparentBlt(_dc
		, int(vRenderPos.x - (float)(iWidth / 2))
		, int(vRenderPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255));

	component_render(_dc);
}

void CMonster::Die()
{
	int iRandom = GetRandomNum(0, 100);
	if (50 > iRandom)
	{
		CItemBox* pItem = new CItemBox(GetPos());

		pItem->SetName(L"ItemBox");
		CreateObject(pItem, GROUP_TYPE::ITEM);
	}

	DeleteObject(this);
}


void CMonster::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();


	if (pOtherObj->GetName() == L"Player")
	{
		Creature* pCreature = static_cast<Creature*>(pOtherObj);
		pCreature->Attacked(this);
	}
	else if (pOtherObj->GetName() == L"Monster")
	{
		// 플레이어랑 가까운애가 부딪힘을 당한거다
		// 부딪힌 애가 뒤로 밀려난다

		Vec2 vDestPos = CGameMgr::GetInst()->GetPlayer()->GetPos();
		float fOtherDist = (vDestPos - pOtherObj->GetPos()).Length();
		float fMyDist = (vDestPos - GetPos()).Length();

		if (fOtherDist > fMyDist)
		{
			((CMonster*)pOtherObj)->SetIsOnMonster(true);
		}
		else
			SetIsOnMonster(true);
	}
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

}

void CMonster::OnCollisionExit(CCollider* _pOther)
{
}
