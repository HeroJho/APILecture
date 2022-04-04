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
	// ���� ī��Ʈ
	QueryPerformanceCounter(&m_llPreCount);

	// �ʴ� ī��Ʈ Ƚ��(����)  �� �ʴ� 1000 �� �� �־�
	QueryPerformanceFrequency(&m_llFrequency);

}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// �����Ӱ� �ð� = ���� �������� ī���ð� ���� ������ ī���� ����  / �ʴ� ī���� ���� Ƚ��
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPreCount.QuadPart) / (double)m_llFrequency.QuadPart;
	
	m_llPreCount = m_llCurCount;

	// m_dDT�� �����ϸ� �ʴ� �������� ���´�.
	// ������ �̷��� �������� ���ϸ� �Ҿ����ϴ�. >> ���� Count�� ���°� �� ���� ���
	//   �� 1������ �� ������ �ʴ� �������� �޶����ϱ�
	// >> render();

#ifdef _DEBUG
	// ����� ����� ��(�ߴ��� ������) 
	if (m_dDT > (1. / 60.))
		m_dDT = (1. / 60.);
#endif
}

void CTimeMgr::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT; // DT ����
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
