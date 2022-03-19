#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"

CMonster::CMonster()
	: m_vCenterPos(Vec2(0.f, 0.f))
	, m_fSpeed(100.f)
	, m_fMaxDistance(50.f)
	, m_iDir(1)
{
}

CMonster::~CMonster()
{

}

void CMonster::update()
{ 
	Vec2 vCurPos = GetPos();

	// 진행 바향으로 시간당 m_fSpeed 만큼 이동
	vCurPos.x += fDT * m_fSpeed * m_iDir;

	// 배회거리 기준량을 넘어섰는지 확인
	// 배회거리 초과량
	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	// 초과했다
	if (0.f < fDist)
	{
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;	// 초과한 만큼 빼고 진행
	}

	SetPos(vCurPos);
}
