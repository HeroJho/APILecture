#include "pch.h"
#include "CBounceBall.h"

#include "CCore.h"
#include "CTimeMgr.h"
#include "CCamera.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "Creature.h"

#include "CRigidBody.h"

CBounceBall::CBounceBall(Creature* _pOwner)
	: m_pOwner(_pOwner)
	, m_fTheta(0.f)
	, m_fPower(0.f)
	, m_fDuration(5.f)
	, m_fCurTime(0.f)
{	  
	SetPos(_pOwner->GetPos());

	float fTheta = GetRandomNum(0.14f, 3.f);
	float fPower = GetRandomNum(400.f, 900.f);
	m_fTheta = fTheta;
	m_fPower = fPower;

	m_pTex = CResMgr::GetInst()->LoadTexture(L"BounceBallTex", L"texture\\BounceBall.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));

	CreateRigidBody();		// �߷� ����
}

CBounceBall::~CBounceBall()
{

}


void CBounceBall::update()
{
	Vec2 vPos = GetPos();

	m_fCurTime += fDT;
	if (m_fCurTime > m_fDuration)
	{
		float fTheta = GetRandomNum(0.14f, 3.f);
		float fPower = GetRandomNum(400.f, 900.f);
		m_fTheta = fTheta;
		m_fPower = fPower;

		vPos = m_pOwner->GetPos();
		GetRigidBody()->SetZeroVelocity();

		m_fCurTime = 0.f;
	}

	vPos.x += m_fPower * cosf(m_fTheta) * fDT;
	vPos.y -= m_fPower * sinf(m_fTheta) * fDT;
	vPos.y -= GetRigidBody()->GetVelocity().y;		// �߷� ����

	SetPos(vPos);
}

void CBounceBall::render(HDC _dc)
{
	// �׸��� ũ�⿡ ���� �»�� ��ġ���� �׸���
	// ȭ�� �������� ������ �������� ���� �� ������ int�� ĳ����
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);

	// (255, 0, 255) ����Ÿ ������ ���� ��������
	TransparentBlt(_dc
		, int(vRenderPos.x - (float)(iWidth / 2))
		, int(vRenderPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255));

	component_render(_dc);
}



void CBounceBall::OnCollisionEnter(CCollider* _pOther)
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
