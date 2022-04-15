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

	// Texture �ε��ϱ�
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

	// �÷��̾ ���ϴ� ������ ������� �Ѵ�.

	// ��ǥ ��ġ - �� ��ġ
	Vec2 destinPos = CGameMgr::GetInst()->GetPlayer()->GetPos();
	Vec2 vDir = destinPos - vCurPos;
	m_vDir = vDir.Normalize();

	vCurPos.x += m_fSpeed * m_vDir.x * fDT;
	vCurPos.y += m_fSpeed * m_vDir.y * fDT;

	SetPos(vCurPos);

	//Vec2 vCurPos = GetPos();

	//// ���� �������� �ð��� m_fSpeed ��ŭ �̵�
	//vCurPos.x += fDT * m_fSpeed * m_iDir;

	//// ��ȸ�Ÿ� ���ط��� �Ѿ���� Ȯ��
	//// ��ȸ�Ÿ� �ʰ���
	//float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	//// �ʰ��ߴ�
	//if (0.f < fDist)
	//{
	//	m_iDir *= -1;
	//	vCurPos.x += fDist * m_iDir;	// �ʰ��� ��ŭ ���� ����
	//}

	//SetPos(vCurPos);
}

void CMonster::render(HDC _dc)
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
