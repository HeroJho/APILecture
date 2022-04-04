#include "pch.h"
#include "CTimeMgr.h"

#include "CCore.h"

CTimeMgr::CTimeMgr()
	: m_llCurCount{}
	, m_llPreCount{}
	, m_llFrequency{}
	, m_dDT(0.)
	, m_dAcc(0.)
	, m_iCallCount(0)
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPreCount);

	// 초당 카운트 횟수(고정)  난 초당 1000 셀 수 있어
	QueryPerformanceFrequency(&m_llFrequency);

}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// 프레임간 시간 = 이전 프레임의 카운팅과 현재 프레임 카운팅 차이  / 초당 카운팅 가능 횟수
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPreCount.QuadPart) / (double)m_llFrequency.QuadPart;
	
	m_llPreCount = m_llCurCount;

	// m_dDT를 역수하면 초당 프레임이 나온다.
	// 하지만 이렇게 프레임을 구하면 불안전하다. >> 직접 Count를 세는게 더 좋은 방법
	//   ㄴ 1프레임 돌 때마다 초당 프레임이 달라지니깐
	// >> render();

#ifdef _DEBUG
	// 디버그 모드일 때(중단점 걸으면) 
	if (m_dDT > (1. / 60.))
		m_dDT = (1. / 60.);
#endif
}

void CTimeMgr::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT; // DT 누적
	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d,	DT : %lf", m_iFPS, m_dDT);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);

	}
}
