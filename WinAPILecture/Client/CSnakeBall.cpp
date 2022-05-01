#include "pch.h"
#include "CSnakeBall.h"

#include "CCore.h"
#include "CTimeMgr.h"
#include "CCamera.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "Creature.h"



CSnakeBall::CSnakeBall(Creature* _pOwner, CSnakeBall* _pNextSankeBall)
	: m_pTex(nullptr)
	, m_pOwner(_pOwner)
	, m_pNextSankeBall(_pNextSankeBall)
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"TTengBallTex", L"texture\\TTengBall.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));

}

CSnakeBall::~CSnakeBall()
{
}



void CSnakeBall::update()
{
	// 내 다음 꼬리가 없다면 return
	if (m_pNextSankeBall == nullptr)
		return;

	
}

void CSnakeBall::render(HDC _dc)
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



void CSnakeBall::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (this->IsDead())
		return;

	if (pOtherObj->GetName() == L"Monster")
	{
		Creature* pCreature = static_cast<Creature*>(pOtherObj);
		pCreature->Attacked(m_pOwner);
	}
}