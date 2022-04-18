#include "pch.h"
#include "CRigidBody.h"

#include "CCore.h"
#include "CTimeMgr.h"
#include "CCamera.h"

#include "CObject.h"

CRigidBody::CRigidBody()
	: m_pOwner(nullptr)
	, m_vGravityPar(0.f, 0.f)
	, m_vVelocity(0.f, 0.f)
{

}

CRigidBody::~CRigidBody()
{
}

void CRigidBody::finalupdate()
{
	m_vGravityPar.y = 9.8f * fDT;

	Vec2 vPos = m_pOwner->GetPos();

	// º®¿¡ ´ê¾Ò³Ä
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	Vec2 vResol_L_U(0.f, 0.f);
	Vec2 vResol_R_B = vResolution;

	if (vRenderPos.y >= vResol_R_B.y)	// ¶¥¿¡ ´ê¾Ò´Ù
	{
		m_vVelocity.y = 0.f;
	}
	else
	{
		m_vVelocity -= m_vGravityPar;
	}

	//vPos += m_vVelocity;

	//m_pOwner->SetPos(vPos);
}

void CRigidBody::render(HDC _dc)
{

}

