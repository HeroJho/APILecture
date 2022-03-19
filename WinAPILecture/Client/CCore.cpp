#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"

#include "CObject.h"

// CCore* CCore::g_pInst = nullptr;

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_memDC(0)
{

}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);	// 커널에 DC 반환

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{ 
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정
	// 메뉴바가 존재할 때 순수 작업 영역 구하기 (메뉴바 제거)
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);  // true -> 메뉴바 여부
	// tr 값은 이제 순수 작업 범위 >> 내가 원하는 실제 값
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);		// 메시지 기반이 아닌 그리기 DC

	// 이중 버퍼링 용도의 비트맵과 DC를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);  // 도구를 주면 이전 도구를 준다
	DeleteObject(hOldBit);		// 1픽셀 디폴트 삭제


	// Mnanager 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();


	return S_OK;
}


void CCore::progress()
{
	// Manager Update
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CSceneMgr::GetInst()->update();

	// ===Rendering===
	// 화면 Clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInst()->render(m_memDC);


	// 그린 종이를 윈도우 종이에 복사
	// 이처럼 픽셀을 그리는 단순 작업이 엄청 많음 >> cpu가 하는게 아니라 Dir가면 GPU가 하도록 함
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		, m_memDC, 0, 0, SRCCOPY);
}

