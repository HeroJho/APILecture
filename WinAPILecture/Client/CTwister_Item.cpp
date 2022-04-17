#include "pch.h"
#include "CTwister_Item.h"

#include "CResMgr.h"
#include "CGameMgr.h"
#include "CSKillMgr.h"

#include "CCollider.h"
#include "CTexture.h"

CTwister_Item::CTwister_Item(Vec2 _vPos)
{
	SetPos(_vPos);

	m_pTex = CResMgr::GetInst()->LoadTexture(L"TwisterTex", L"texture\\Twister2.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

CTwister_Item::~CTwister_Item()
{
}


void CTwister_Item::update()
{

}

void CTwister_Item::render(HDC _dc)
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


void CTwister_Item::useItem(CObject* _pObj)
{
	CGameMgr::GetInst()->GetSkillMgr()->UpgradeSkill(SKILL_TYPE::TWISTER);

	DeleteObject(this);
}


