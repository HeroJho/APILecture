#include "pch.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CGameMgr.h"
#include "CSKillMgr.h"

#include "CMissile.h"
#include "CItem.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CTimmer.h"
#include "CRigidBody.h"

#include "CBounceBall.h"

CPlayer::CPlayer(CreatureInfo* _sInfo)
{
	m_sInfo = _sInfo;

	// Texture 로딩하기
	// m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
	

	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, -5.f));
	GetCollider()->SetScale(Vec2(15.f, 25.f));

	CTexture* m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\link_0.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"WALK_DOWN" , m_pTex, Vec2(0.f, 0.f), Vec2(16.f, 32.f), Vec2(16.f, 0.f), 0.1f, 9);
	GetAnimator()->Play(L"WALK_DOWN", true);

	// 애니 오프셋 설정
	CAnimation* pAnim = GetAnimator()->FindAnimation(L"WALK_DOWN");
	for (UINT i = 0; i < pAnim->GetMaxFrame(); ++i)
		pAnim->GetFrame(i).vOffset = Vec2(0.f, -10.f);

	CreateTimmer();
	GetTimmer()->SetNoneStopObj();

}

CPlayer::~CPlayer()
{

}


void CPlayer::CreatureUpdate()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 300.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 300.f * fDT;
	}

	//if (KEY_TAP(KEY::P))
	//{
	//	// TEST
	//	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

	//	CBounceBall* pBounce = new CBounceBall(CGameMgr::GetInst()->GetPlayer());
	//	pBounce->SetName(L"BounceBall_Player");
	//	pBounce->SetScale(Vec2(25.f, 25.f));

	//	CreateObject(pBounce, GROUP_TYPE::PROJ_PLAYER);
	//}


	SetPos(vPos);

	SkillUpdate();
	GetAnimator()->update();
}

void CPlayer::render(HDC _dc)
{
	// 컴포넌트 랜더(collider, etc...)가 있는 경우 랜더 
	component_render(_dc);
}

void CPlayer::Die()
{
	// DeleteObject(this);
}

void CPlayer::SkillUpdate()
{
	CGameMgr::GetInst()->GetSkillMgr()->update();
}



void CPlayer::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->IsDead())
		return;

	if (pOtherObj->GetName() == L"Item" && KEY_TAP(KEY::Z))
	{
		CItem* pItem = static_cast<CItem*>(pOtherObj);
		pItem->useItem(this);
	}
}

void CPlayer::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"ItemBox")
	{
		CItem* pItem = static_cast<CItem*>(pOtherObj);
		pItem->useItem(this);
	}
}



