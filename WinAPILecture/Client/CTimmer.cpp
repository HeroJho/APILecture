#include "pch.h"
#include "CTimmer.h"

#include "CTimeMgr.h"
#include "CGameMgr.h"
#include "CPlayTimeMgr.h"

#include "CObject.h"

CTimmer::CTimmer()
	: m_pOwner(nullptr)
	, m_fPreTime(5.f)
	, m_fCurTime(0.f)
	, m_bIsStopObj(true)
{

}

CTimmer::~CTimmer()
{
}


bool CTimmer::IsNowStop()
{
	return CGameMgr::GetInst()->GetPlayTimeMgr()->GetIsStop() && m_bIsStopObj;
}

void CTimmer::backTimeUpdate()
{
	// 살아난지 얼마 안 됐다는 말
	if (m_listPrePos.empty())
	{
		// TODO:
	}
	else
	{
		m_fCurTime -= fDT;
		Vec2 vPrePos = m_listPrePos.back();
		m_listPrePos.pop_back();

		m_pOwner->SetPos(vPrePos);
	}

}

void CTimmer::update()
{
	if (0.f > m_fCurTime)
		m_fCurTime = 0.f;

	if (m_fPreTime > m_fCurTime)
	{
		m_fCurTime += fDT;
		m_listPrePos.push_back(m_pOwner->GetPos());
	}
	else
	{
		m_listPrePos.push_back(m_pOwner->GetPos());
		m_listPrePos.pop_front();
	}
}

void CTimmer::finalupdate()
{
}

void CTimmer::render(HDC _dc)
{
}


