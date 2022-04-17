#include "pch.h"
#include "CTwister.h"

#include "CTimeMgr.h"
#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "Creature.h"

CTwister::CTwister(Creature* _pOwner, float _fRange)
	: m_pOwner(_pOwner)
	, m_fSpeed(0)
	, m_fRange(_fRange)
	, m_vInitPos(_pOwner->GetPos())
	, m_vDir(Vec2(1.f, 1.f))
	, m_fTheta(0.f)
	, m_pTex(nullptr)
{
	SetPos(_pOwner->GetPos());

	m_pTex = CResMgr::GetInst()->LoadTexture(L"TwisterTex", L"texture\\Twister2.bmp");

	m_vDir.Normalize();	// ���� ����ȭ

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

CTwister::~CTwister()
{

}

void CTwister::update()
{
	Vec2 vPos = GetPos();

	// �ʴ� �� �� ��ŭ ȸ���ϳ�
	// m_fTheta += m_fSpeed * fDT;

	if (DPI < m_fTheta)
		m_fTheta = 0;

	vPos.x = m_pOwner->GetPos().x + m_fRange * cosf(m_fTheta); // *fDT;
	vPos.y = m_pOwner->GetPos().y + m_fRange * sinf(m_fTheta); // *fDT;


	SetPos(vPos);
}

void CTwister::render(HDC _dc)
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



void CTwister::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
		
	if (pOtherObj->GetName() == L"Monster")
	{
		Creature* pCreature = static_cast<Creature*>(pOtherObj);
		pCreature->Attacked(m_pOwner);
		// DeleteObject(this);
	}
}