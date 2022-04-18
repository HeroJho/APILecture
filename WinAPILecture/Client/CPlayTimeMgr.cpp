#include "pch.h"
#include "CPlayTimeMgr.h"

#include "CTimeMgr.h"

CPlayTimeMgr::CPlayTimeMgr()
	: m_bIsStop(false)
	, m_fStopTime(5.f)
	, m_fCurTime(0.f)
{
}

CPlayTimeMgr::~CPlayTimeMgr()
{
}


void CPlayTimeMgr::update()
{
	if (!m_bIsStop)
		return;

	m_fCurTime += fDT;

	if (m_fCurTime > m_fStopTime)
	{
		m_bIsStop = false;
		m_fCurTime = 0.f;
	}
}
