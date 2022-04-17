#include "pch.h"
#include "CTTengBall.h"

#include "CCore.h"
#include "CTimeMgr.h"
#include "CCamera.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "Creature.h"

CTTengBall::CTTengBall(Creature* _pOwner, float _fRange, float _fSpeed)
	: m_pOwner(_pOwner)
	, m_fSpeed(_fSpeed)
	, m_fRange(_fRange)
	, m_vDir(Vec2(-0.5f, -1.f))
	, m_fTheta(0.f)
	, m_pTex(nullptr)
{
	SetPos(_pOwner->GetPos());

	m_pTex = CResMgr::GetInst()->LoadTexture(L"MissileTex", L"texture\\Missile.bmp");

	m_vDir.Normalize();	// ���� ����ȭ

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));

}

CTTengBall::~CTTengBall()
{

}


void CTTengBall::update()
{
	Vec2 vPos = GetPos();

	// ���� ��ҳ�
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	Vec2 vResol_L_U(0.f, 0.f);
	Vec2 vResol_R_B = vResolution;

	Vec2 vReflectionDir = m_vDir;	// �ݻ� ����
	Vec2 vNormal(0, 0);				// ���� ����
	Vec2 vPrjct(0, 0);				// ���� ����


	if (vRenderPos.y < vResol_L_U.y)		// ��
	{
		vNormal.x = 0;
		vNormal.y = 1;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
	}
	else if (vRenderPos.y > vResol_R_B.y)	// ��
	{
		vNormal.x = 0;
		vNormal.y = -1;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
	}
	else if (vRenderPos.x < vResol_L_U.x)	// ��
	{
		vNormal.x = 1;
		vNormal.y = 0;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
	}
	else if (vRenderPos.x > vResol_R_B.x)	// ��
	{
		vNormal.x = -1;
		vNormal.y = 0;

		vPrjct = vNormal * (vReflectionDir.GetInverseVec() * vNormal);
		vReflectionDir = m_vDir + (vPrjct * 2.f);
	}

	// ��Ҵٸ� �ݻ簢 ����
	m_vDir = vReflectionDir;

	vPos.x += m_fSpeed * m_vDir.x * fDT;
	vPos.y -= m_fSpeed * m_vDir.y * fDT;


	// �Ÿ��� �ʹ� �������� �ٽ� ������
	float dist = (vPos - m_pOwner->GetPos()).Length();
	if (700.f < dist)
		SetPos(m_pOwner->GetPos());
	else
		SetPos(vPos);

}

void CTTengBall::render(HDC _dc)
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



void CTTengBall::OnCollisionEnter(CCollider* _pOther)
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
