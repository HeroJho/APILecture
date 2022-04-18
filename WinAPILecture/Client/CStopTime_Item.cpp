#include "pch.h"
#include "CStopTime_Item.h"

#include "CResMgr.h"
#include "CGameMgr.h"
#include "CSKillMgr.h"
#include "CPlayTimeMgr.h"

#include "CCollider.h"
#include "CTexture.h"

CStopTime_Item::CStopTime_Item(Vec2 _vPos)
{
	SetPos(_vPos);

	m_pTex = CResMgr::GetInst()->LoadTexture(L"StopTimeItemTex", L"texture\\Item_StopTime.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

CStopTime_Item::~CStopTime_Item()
{

}


void CStopTime_Item::update()
{

}

void CStopTime_Item::render(HDC _dc)
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


void CStopTime_Item::useItem(CObject* _pObj)
{
	//  �ð� ����
	CGameMgr::GetInst()->GetPlayTimeMgr()->SetIsStop(true);

	DeleteObject(this);
}
