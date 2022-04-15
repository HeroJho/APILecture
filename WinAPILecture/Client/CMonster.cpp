#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"
#include "CGameMgr.h"

#include "CResMgr.h"
#include "CTexture.h"

#include "CCollider.h"
#include "CPlayer.h"

CMonster::CMonster(CreatureInfo* _sInfo)
	: m_fSpeed(100.f)
	, m_pTex(nullptr)
{
	m_sInfo = _sInfo;

	// Texture 로딩하기
	m_pTex = CResMgr::GetInst()->LoadTexture(L"MonsterTex", L"texture\\Monster.bmp");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(30.f, 30.f));
}

CMonster::~CMonster()
{

}

void CMonster::update()
{

	Vec2 vCurPos = GetPos();

	// 플레이어를 향하는 방향을 구해줘야 한다.

	// 목표 위치 - 내 위치
	Vec2 destinPos = CGameMgr::GetInst()->GetPlayer()->GetPos();
	Vec2 vDir = destinPos - vCurPos;
	m_vDir = vDir.Normalize();

	vCurPos.x += m_fSpeed * m_vDir.x * fDT;
	vCurPos.y += m_fSpeed * m_vDir.y * fDT;

	SetPos(vCurPos);

	//Vec2 vCurPos = GetPos();

	//// 진행 바향으로 시간당 m_fSpeed 만큼 이동
	//vCurPos.x += fDT * m_fSpeed * m_iDir;

	//// 배회거리 기준량을 넘어섰는지 확인
	//// 배회거리 초과량
	//float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	//// 초과했다
	//if (0.f < fDist)
	//{
	//	m_iDir *= -1;
	//	vCurPos.x += fDist * m_iDir;	// 초과한 만큼 빼고 진행
	//}

	//SetPos(vCurPos);
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


void CMonster::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Player")
	{
		Creature* pCreature = static_cast<Creature*>(pOtherObj);
		pCreature->Attacked(this);
	}
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();


}
