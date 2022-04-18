#include "pch.h"
#include "CItemBox.h"

#include "CResMgr.h"
#include "CGameMgr.h"
#include "CSKillMgr.h"

#include "CCollider.h"
#include "CTexture.h"
#include "CEnergeBall_Item.h"
#include "CTwister_Item.h"
#include "CTTengBall_Item.h"
#include "CStopTime_Item.h"

CItemBox::CItemBox(Vec2 _vPos)
{
	SetPos(_vPos);

	m_pTex = CResMgr::GetInst()->LoadTexture(L"ItemBoxTex", L"texture\\ItemBox.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

CItemBox::~CItemBox()
{
}


void CItemBox::update()
{

}

void CItemBox::render(HDC _dc)
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


void CItemBox::useItem(CObject* _pObj)
{
	GenerateRandomItem();

	DeleteObject(this);
}

void CItemBox::GenerateRandomItem()
{
	CItem* pItem = nullptr;

	float randomNum = GetRandomNum(0.f, 100.f);

	
	if (10.f >= randomNum)
	{
		pItem = new CEnergeBall_Item(GetPos());

		pItem->SetName(L"Item");
		CreateObject(pItem, GROUP_TYPE::ITEM);
	}
	else if (20.f >= randomNum)
	{
		pItem = new CTwister_Item(GetPos());

		pItem->SetName(L"Item");
		CreateObject(pItem, GROUP_TYPE::ITEM);
	}
	else if (30.f >= randomNum)
	{
		pItem = new CTTengBall_Item(GetPos());

		pItem->SetName(L"Item");
		CreateObject(pItem, GROUP_TYPE::ITEM);
	}
	else if (40.f >= randomNum)
	{
		pItem = new CStopTime_Item(GetPos());

		pItem->SetName(L"Item");
		CreateObject(pItem, GROUP_TYPE::ITEM);
	}
	else
	{

	}
	
}
