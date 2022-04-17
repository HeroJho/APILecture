#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "Creature.h"

CMissile::CMissile(Creature* _pOwner, float _fRange, float _fSpeed)
	: m_pOwner(_pOwner)
	, m_fSpeed(_fSpeed)
	, m_fRange(_fRange)
	, m_vInitPos(_pOwner->GetPos())
	, m_vDir(Vec2(1.f, 1.f))
	, m_fTheta(0.f)
	, m_pTex(nullptr)
{
	SetPos(_pOwner->GetPos());

	m_pTex = CResMgr::GetInst()->LoadTexture(L"MissileTex", L"texture\\Missile.bmp");

	m_vDir.Normalize();	// 벡터 정규화

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));

}

CMissile::~CMissile()
{
	
}


void CMissile::update()
{
	Vec2 vPos = GetPos();
	
	Vec2 vDiffer = vPos - m_vInitPos;
	float fLenth = vDiffer.Length();

	//vPos.x += 600.f * m_vDir.x * fDT;
	//vPos.y += 600.f * m_vDir.y * fDT;
	
	vPos.x += m_fSpeed * cosf(m_fTheta) * fDT;
	vPos.y -= m_fSpeed * sinf(m_fTheta) * fDT;

	if (m_fRange < fLenth)
	{
		DeleteObject(this);
		return;
	}

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	// 그림의 크기에 따라 좌상단 위치에서 그린다
	// 화면 왼쪽으로 나가면 음수값이 나올 수 있으니 int로 캐스팅
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	//BitBlt(_dc 
	//	, int(vPos.x - (float)(iWidth / 2))
	//	, int(vPos.y - (float)(iHeight / 2))
	//	, iWidth, iHeight
	//	, m_pTex->GetDC()
	//	, 0, 0, SRCCOPY);

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



void CMissile::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (this->IsDead())
		return;

	if (pOtherObj->GetName() == L"Monster")
	{
		Creature* pCreature = static_cast<Creature*>(pOtherObj);
		pCreature->Attacked(m_pOwner);
		DeleteObject(this);
	}
}
