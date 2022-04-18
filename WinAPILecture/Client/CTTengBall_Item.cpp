#include "pch.h"
#include "CTTengBall_Item.h"

#include "CResMgr.h"
#include "CGameMgr.h"
#include "CSKillMgr.h"

#include "CCollider.h"
#include "CTexture.h"

CTTengBall_Item::CTTengBall_Item(Vec2 _vPos)
{
	SetPos(_vPos);

	m_pTex = CResMgr::GetInst()->LoadTexture(L"TTengBallTex", L"texture\\TTengBall.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

CTTengBall_Item::~CTTengBall_Item()
{
}


void CTTengBall_Item::update()
{

}

void CTTengBall_Item::render(HDC _dc)
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


void CTTengBall_Item::useItem(CObject* _pObj)
{
	CGameMgr::GetInst()->GetSkillMgr()->UpgradeSkill(SKILL_TYPE::TTENGBALL);

	DeleteObject(this);
}


