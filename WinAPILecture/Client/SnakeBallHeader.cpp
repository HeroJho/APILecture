#include "pch.h"
#include "SnakeBallHeader.h"


#include "CCore.h"
#include "CTimeMgr.h"
#include "CCamera.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "Creature.h"



SnakeBallHeader::SnakeBallHeader(Creature* _pOwner, float _fSpeed)
	: m_pOwner(_pOwner)
	, m_fSpeed(_fSpeed)
	, m_fRange(0)
	, m_vDir(Vec2(0.f, 0.f))
	, m_fTheta(0.f)
	, m_pTex(nullptr)
	, m_iCheckDir(0)
{
	SetPos(_pOwner->GetPos());

	float x = GetRandomNum(-5.f, 5.f);
	float y = GetRandomNum(-5.f, 5.f);
	m_vDir = Vec2(x, y);

	m_pTex = CResMgr::GetInst()->LoadTexture(L"TTengBallTex", L"texture\\TTengBall.bmp");

	m_vDir.Normalize();	// 벡터 정규화

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));

}

SnakeBallHeader::~SnakeBallHeader()
{

}


void SnakeBallHeader::update()
{
	Vec2 vPos = GetPos();

	// 벽에 닿았냐
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	Vec2 vResol_L_U(0.f, 0.f);
	Vec2 vResol_R_B = vResolution;

	Vec2 vReflectionDir = m_vDir;	// 반사 벡터
	Vec2 vNormal(0, 0);				// 법선 벡터
	Vec2 vPrjct(0, 0);				// 투영 벡터


	if (vRenderPos.y < vResol_L_U.y && m_iCheckDir != 1)		// 상
	{
		vNormal.x = 0;
		vNormal.y = 1;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
		m_iCheckDir = 1;
	}
	else if (vRenderPos.y > vResol_R_B.y && m_iCheckDir != 2)	// 하
	{
		vNormal.x = 0;
		vNormal.y = -1;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
		m_iCheckDir = 2;
	}
	else if (vRenderPos.x < vResol_L_U.x && m_iCheckDir != 3)	// 좌
	{
		vNormal.x = 1;
		vNormal.y = 0;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
		m_iCheckDir = 3;
	}
	else if (vRenderPos.x > vResol_R_B.x && m_iCheckDir != 4)	// 우
	{
		vNormal.x = -1;
		vNormal.y = 0;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
		m_iCheckDir = 4;
	}

	// 닿았다면 반사각 적용
	m_vDir = vReflectionDir;

	vPos.x += m_fSpeed * m_vDir.x * fDT;
	vPos.y -= m_fSpeed * m_vDir.y * fDT;


	// 거리가 너무 벌어지면 다시 리스폰
	float dist = (vPos - m_pOwner->GetPos()).Length();
	if (1000.f < dist)
		SetPos(m_pOwner->GetPos());
	else
		SetPos(vPos);

}

void SnakeBallHeader::render(HDC _dc)
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



void SnakeBallHeader::OnCollisionEnter(CCollider* _pOther)
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