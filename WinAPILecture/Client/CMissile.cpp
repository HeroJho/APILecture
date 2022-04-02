#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"

#include "CResMgr.h"
#include "CTexture.h"

CMissile::CMissile()
	: m_fTheta (0.f)
	, m_vDir(Vec2(1.f, 1.f))
	, m_pTex(nullptr)
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"MissileTex", L"texture\\Missile.bmp");

	m_vDir.Normalize();	// ���� ����ȭ
}

CMissile::~CMissile()
{
	
}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	// vPos.x += 600.f * cosf(m_fTheta) * fDT;
	// vPos.y -= 600.f * sinf(m_fTheta) * fDT;
	
	vPos.x += 600.f * m_vDir.x * fDT;
	vPos.y += 600.f * m_vDir.y * fDT;
	 
	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	// �׸��� ũ�⿡ ���� �»�� ��ġ���� �׸���
	// ȭ�� �������� ������ �������� ���� �� ������ int�� ĳ����
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	//BitBlt(_dc 
	//	, int(vPos.x - (float)(iWidth / 2))
	//	, int(vPos.y - (float)(iHeight / 2))
	//	, iWidth, iHeight
	//	, m_pTex->GetDC()
	//	, 0, 0, SRCCOPY);

	// (255, 0, 255) ����Ÿ ������ ���� ��������
	TransparentBlt(_dc
		, int(vPos.x - (float)(iWidth / 2))
		, int(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255));
}
